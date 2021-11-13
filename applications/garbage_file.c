#include <rtthread.h>
#include "drv_common.h"
#include <rtdevice.h>
#include "drv_spi_ili9488.h"  // spi lcd driver
#include <lcd_spi_port.h>  // lcd ports

/*based on garbage detection */
#include <rt_ai_garbage_model.h>
#include <rt_ai.h>
#include <rt_ai_log.h>
#include <backend_cubeai.h>
#include <logo.h>
#include <garbage_file.h>

//#include <drv_gc0328c.h>

#include <drv_dcmi.h>

#define LED_PIN_R GET_PIN(C, 15)

char *trash_label[] = { "Hazardous waste", "Kitchen waste", "Other trash", "Recyclable trash" }; //Pointer array

//float *input_buf;
struct rt_event ov2640_event; //create a camera event
//rt_ai_buffer_t ai_flag = 0;

rt_uint8_t ov2640_event_flag = 0;
rt_uint32_t execution_count = 0;

void beginning_images()
{
    lcd_show_image(0, 0, 320, 240, LOGO);
    lcd_show_image(0, 240, 320, 240, BEGIN_IMAGE);
    lcd_show_string(90, 140, 16, "RTT_18th Members:");
    lcd_show_string(35, 172, 16, "MingjingXU, ZihengXU, XibangYang");
}

void ending_images()
{
    lcd_show_image(0, 0, 320, 240, LOGO);
    lcd_show_image(0, 240, 320, 240, TRASH_ALL_IMAGE);
    lcd_show_string(30, 140, 16, "Enter or push for other execution");
    lcd_show_string(80, 165, 16, "Execution count = %d", execution_count);
}

/*void ai_run_complete(void *arg)
 {
 *(int*) arg = 1;
 }*/

//normalization
static inline void _itof(float *dst, rt_uint8_t *src, uint32_t size, float div);

void ai_camera();
void bilinera_interpolation(rt_uint8_t *in_array, short height, short width, rt_uint8_t *out_array, short out_height,
        short out_width);

int garbage_app(void)
{

    rt_pin_mode(LED_PIN_R, PIN_MODE_OUTPUT);

    /* init spi data notify event*/
    if (!ov2640_event_flag)
    {
        rt_event_init(&ov2640_event, "ov2640", RT_IPC_FLAG_FIFO);
        ov2640_event_flag += 1;
    }

    struct drv_lcd_device *lcd;
    struct rt_device_rect_info rect_info = { 0, 0, LCD_WIDTH, 240 };
    lcd = (struct drv_lcd_device *) rt_device_find("lcd");

    rt_kprintf("Processing garbage detection \r\n");
    rt_thread_mdelay(1000);

    //find a registered model handle
    static rt_ai_t model = NULL;
    model = rt_ai_find(RT_AI_GARBAGE_MODEL_NAME);
    if (!model)
    {
        rt_kprintf("ai model find err\r\n");
        return -1;
    }

    //input_buf = rt_malloc(64 * 64 * sizeof(float));

    // allocate input memory
    rt_ai_buffer_t *input_image = rt_malloc(RT_AI_GARBAGE_IN_1_SIZE_BYTES);
    if (!input_image)
    {
        rt_kprintf("malloc err\n");
        return -1;
    }

    // allocate calculate memory
    rt_ai_buffer_t *work_buf = rt_malloc(RT_AI_GARBAGE_WORK_BUFFER_BYTES);
    if (!work_buf)
    {
        rt_kprintf("malloc err\n");
        return -1;
    }

    // allocate output memory
    rt_ai_buffer_t *_out = rt_malloc(RT_AI_GARBAGE_OUT_1_SIZE_BYTES);
    if (!_out)
    {
        rt_kprintf("malloc err\n");
        return -1;
    }

    // ai model init
    rt_ai_buffer_t model_init = rt_ai_init(model, work_buf);
    if (model_init != 0)
    {
        rt_kprintf("ai init err\n");
        return -1;
    }
    rt_ai_config(model, CFG_INPUT_0_ADDR, input_image);
    rt_ai_config(model, CFG_OUTPUT_0_ADDR, _out);

    ai_camera();

    rt_uint32_t garbage_count = 0;
    rt_uint8_t prediction = 0;

    rt_pin_write(LED_PIN_R, PIN_LOW);

    do
    {
        //start until finishing initiation
        rt_event_recv(&ov2640_event, 1,
        RT_EVENT_FLAG_AND | RT_EVENT_FLAG_CLEAR,
        RT_WAITING_FOREVER,
        RT_NULL);

        lcd->parent.control(&lcd->parent, RTGRAPHIC_CTRL_RECT_UPDATE, &rect_info);

        DCMI_Start();
        // resize
        bilinera_interpolation(lcd->lcd_info.framebuffer, 240, 320, input_image, 64, 64);
        //_itof(input_buf, input_image, 64 * 64, 255.0);
        rt_ai_run(model, NULL, NULL);

        rt_uint8_t *out = (rt_uint8_t *) rt_ai_output(model, 0);
        //rt_kprintf("pred[0]=%d pred[1]=%d pred[2]=%d pred[3]=%d \r\n", out[0], out[1], out[2], out[3]);

        for (int i = 0; i < 4; i++)
        {
            if (out[i] > out[prediction])
            {
                prediction = i;
            }
        }

        switch (prediction)
        {
        case 0:
            lcd_show_image(0, 240, 320, 240, HAZARDOUS_WASTE__IMAGE);
            break;
        case 1:
            lcd_show_image(0, 240, 320, 240, KITCHEN_WASTE_IMAGE);
            break;
        case 2:
            lcd_show_image(0, 240, 320, 240, OTHER_TRASH_IMAGE);
            break;
        case 3:
            lcd_show_image(0, 240, 320, 240, RECYCLABLE_TRASH__IMAGE);
            break;
        }
        //lcd_show_image(0, 240, 320, 240, Other_trash_image);
        rt_kprintf("Trash prediction: %s\r\n", trash_label[prediction]);
    } while (garbage_count++ < 300);

    //free memory
    rt_free(input_image);
    rt_free(work_buf);
    rt_free(_out);
    //rt_free(input_buf);

    //show images
    execution_count += 1;
    ending_images();
    rt_kprintf("End of Garbage Detection \r\n");
    rt_pin_write(LED_PIN_R, PIN_HIGH);
    return 0;
}

MSH_CMD_EXPORT(garbage_app, garbage demo);
//INIT_COMPONENT_EXPORT(fire_app);

void ai_camera()
{
    rt_gc0328c_init();
    DCMI_Start(); //newly capture a image
    //ai_flag = 1;
}

static inline void _itof(float *dst, rt_uint8_t *src, uint32_t size, float div)
{
    if (div == 0)
    {
        return;
    }
    else
    {
        int i = 0;
        for (i = 0; i < size; i++)
        {
            dst[i] = (float) src[i] / div;
        }
    }
}

int is_in_array(short x, short y, short height, short width)
{
    if (x >= 0 && x < width && y >= 0 && y < height)
        return 1;
    else
        return 0;
}

void bilinera_interpolation(rt_uint8_t* in_array, short height, short width, rt_uint8_t* out_array, short out_height,
        short out_width)
{
    double h_times = (double) out_height / (double) height, w_times = (double) out_width / (double) width;
    short x1, y1, x2, y2, f11, f12, f21, f22;
    double x, y;

    for (int i = 0; i < out_height; i++)
    {
        for (int j = 0; j < out_width * 3; j = j + 3)
        {
            for (int k = 0; k < 3; k++)
            {
                x = j / w_times + k;
                y = i / h_times;

                x1 = (short) (x - 3);
                x2 = (short) (x + 3);
                y1 = (short) (y + 1);
                y2 = (short) (y - 1);
                f11 = is_in_array(x1, y1, height, width * 3) ? in_array[y1 * width * 3 + x1] : 0;
                f12 = is_in_array(x1, y2, height, width * 3) ? in_array[y2 * width * 3 + x1] : 0;
                f21 = is_in_array(x2, y1, height, width * 3) ? in_array[y1 * width * 3 + x2] : 0;
                f22 = is_in_array(x2, y2, height, width * 3) ? in_array[y2 * width * 3 + x2] : 0;
                out_array[i * out_width * 3 + j + k] = (rt_uint8_t) (((f11 * (x2 - x) * (y2 - y))
                        + (f21 * (x - x1) * (y2 - y)) + (f12 * (x2 - x) * (y - y1)) + (f22 * (x - x1) * (y - y1)))
                        / ((x2 - x1) * (y2 - y1)));
            }
        }
    }
}
