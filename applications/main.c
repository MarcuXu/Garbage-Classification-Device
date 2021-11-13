#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#include "drv_spi_ili9488.h"  // spi lcd driver
#include <lcd_spi_port.h>  // lcd ports
#include <logo.h>
#include <garbage_file.h>

#define LED_PIN_B GET_PIN(I, 8)
#define USER_KEY GET_PIN(H,4)

#define THREAD_PRIORITY_KEY     10
#define THREAD_PRIORITY_LED     25
#define THREAD_STACK_SIZE       256
#define THREAD_TIMESLICE        5

static rt_thread_t led_blue_tid = RT_NULL;

ALIGN(8); //8 bytes alignment
static rt_uint8_t app_stack[4096];
static struct rt_thread app_garbage;

rt_uint32_t LED_B_count = 0;
/* dynamic API of LED-BLUE */
static void led_blue_thread_entry(void *parameter)
{
    while (++LED_B_count)
    {
        rt_thread_mdelay(500);
        rt_pin_write(LED_PIN_B, LED_B_count % 2);
        //LOG_D("led_blue_thread count: %d", count);
    }
}

/*static void garbage_app_thread_entry(void *parameter)
 {
 rt_kprintf("garbage_app_thread_entry\n");
 garbage_app();
 }*/

// dynamic thread can't work, so we use static thread
void irq_handle_callback(void *parameter)
{
    rt_thread_init(&app_garbage, "app", garbage_app,
    RT_NULL, app_stack, sizeof(app_stack),
    THREAD_PRIORITY_KEY, THREAD_TIMESLICE);
    //start it
    rt_thread_startup(&app_garbage);
}

int main(void)
{
    beginning_images();
    rt_thread_mdelay(3000);

    rt_pin_mode(LED_PIN_B, PIN_MODE_OUTPUT);

    led_blue_tid = rt_thread_create("led_blue_thread", led_blue_thread_entry, RT_NULL,
    THREAD_STACK_SIZE,
    THREAD_PRIORITY_LED, THREAD_TIMESLICE);
    /* whether led_blue_tid is null */
    if (led_blue_tid != RT_NULL)
    {
        rt_thread_startup(led_blue_tid);
        rt_kprintf("led_blue_thread created successful\r\n");
    }
    else
    {
        rt_kprintf("led_blue_thread created failed\r\n");
    }
    //Key interrupt initialisation
    //Set the USER_KEY to input mode
    rt_pin_mode(USER_KEY, PIN_MODE_INPUT);
    //Binding the USER_KEY with interrupt callback function
    rt_pin_attach_irq(USER_KEY, PIN_IRQ_MODE_FALLING, irq_handle_callback, RT_NULL);
    //Enable the USER_KEY interrupt
    rt_pin_irq_enable(USER_KEY, PIN_IRQ_ENABLE);

    rt_thread_mdelay(500);

    lcd_show_string(40, 20, 16, "User key initiated successful");

    return RT_EOK;
}

#include "stm32h7xx.h"
static int vtor_config(void)
{
    /* Vector Table Relocation in Internal QSPI_FLASH */
    SCB->VTOR = QSPI_BASE;
    return 0;
}
INIT_BOARD_EXPORT(vtor_config);

