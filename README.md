# RT-AK 之 STM32 插件 Demo-Fire

[TOC]

| Version | Date       | Description                                                  | Other      |
| ------- | ---------- | ------------------------------------------------------------ | ---------- |
| v0.1.0  | 2021/07/06 | 火灾检测模型部署到 ART-PI 中                                 |            |
| v0.2.0  | 2021/07/06 | 1. 新增 LCD 和 摄像头驱动;<br>2. 新增使用命令之后 logo 1s 显示 |            |
| v0.2.1  | 2021/07/07 | 新增 c 代码版本的尺度转换，输入 320x240 转成 64x64           | 双线性插值 |
| v0.3.0  | 2021/07/07 | 新增摄像头 ov2640 支持                                       |            |

怎么把生成 ART-PI，怎么使用 RT-AK，怎么使用 RT-Thread Sdutio 编译代码，请看下面这个链接：

[RT-AK 之 STM32 插件快速上手（附源码）](https://blog.csdn.net/weixin_37598106/article/details/118520343)

## 1. 项目说明

火灾二分类模型，仅检测图片中是否已经发生火灾

基于神经网络实现火灾识别，掌握神经网络图像分类识别的基本原理。

当模型训练完成之后，使用RT-AK框架，将模型一键部署到RT-Thread系统中。

训练代码：https://github.com/Lebhoryi/FireNet-LightWeight-Network-for-Fire-Detection

`Demo` 示例代码实现在 `appplications` 文件夹下面，其中文件说明：

```shell
卷 软件 的文件夹 PATH 列表
卷序列号为 E67E-D1CA
D:.
    fire_detection.c		// ai 模型推理应用代码实现
    main.c			// artpi LED 闪烁灯例程原 main 函数，未改动
    rt_ai_fire_model.c			// 与 STM32 平台相关的模型声明文件
    rt_ai_fire_model.h			// 存放 ai 模型输入输出等相关信息文件
    save_image.py			// 将图片保存成 xxx.h 文件形式，ai 模型推理用
    SConscript
    test.h			// 测试图片
    test.jpg			// 测试图片
```

结果显示：

![image-20210706133940472](https://gitee.com/lebhoryi/PicGoPictureBed/raw/master/img/20210706135440.png)

---

其中开启模型推理一次计时的宏定义是在 `rt_ai_lib/aiconfig.h` 文件中的第23行。

![image-20210706141158050](https://gitee.com/lebhoryi/PicGoPictureBed/raw/master/img/20210706141226.png)

## 2. 元件

- 多媒体扩展版
- gc0328

## 3. 步骤

### 3.1 代码流程

**RT-AK Lib 模型加载并运行**：

- 注册模型（代码自动注册，无需修改）
- 找到注册模型
- 初始化模型，挂载模型信息，准备运行环境
- 运行（推理）模型
- 获取输出结果

### 3.2 核心代码

```c
// fire_detection.c

...

// 注册模型的代码在 rt_ai_mnist_model.c 文件下的第43行，代码自动执行
// 模型的相关信息在 rt_ai_mnist_model.h 文件
// find a registered model handle
model = rt_ai_find(RT_AI_FIRE_MODEL_NAME);  // 找到模型
...
result = rt_ai_init(model, work_buffer);  // 初始化模型，传入输入数据
...
result = rt_ai_run(model, ai_run_complete, &ai_run_complete_flag);    // 模型推理一次
...

/* 获取模型输出结果 */
uint8_t *out = (uint8_t *)rt_ai_output(model, 0);
```

------

**如何更换模型输入数据补充说明**：

模型不用重新训练，只需要更改模型输入图片即可。

`test.h` 是模型输入图片。

运行 `save_image.py` 文件即可获取上述文件。

**main.c 代码修改**：

​	修改第 37 行代码，改为新的图片变量名

![image-20210706142035865](https://gitee.com/lebhoryi/PicGoPictureBed/raw/master/img/20210706142035.png)

### 3.3 编译说明

这里我用的是 `RT-Thread Studio`

![image-20210706142445929](https://gitee.com/lebhoryi/PicGoPictureBed/raw/master/img/20210706142450.png)

## 4. 运行结果

开机屏幕是白色的，

当在终端输入 fire_app 之后会有 1s 的 logo 显示，然后实时显示推理结果。

![image](https://git.rt-thread.com/research/edge-ai-group/edge-ai/uploads/2a07cab8ad365f5cd4477cbde603241e/image.png)

![image-20210708173425300](https://gitee.com/lebhoryi/PicGoPictureBed/raw/master/img/20210708173425.png)

![image-20210708173351174](https://gitee.com/lebhoryi/PicGoPictureBed/raw/master/img/20210708173429.png)



---

**感谢名单：**

- Derekduke