# DAMIAO | 达秒科技

DM-MC01 驱动多路DM-J4310 DEMO示例

![image-20240322094002609](C:/Users/disno/AppData/Roaming/Typora/typora-user-images/image-20240322094002609.png)

使用说明书 V1.0 2023.12.8

## 修订记录

| 序号 | 修订时间  | 版本号 | 修订说明 |
| :--: | :-------: | :----: | :------: |
|  1   | 2023.12.8 |  V1.0  | 初版创建 |

## 目录

[TOC]

<div style="page-break-after:always"></div>

## 1. demo 使用

demo 示例代码做了应用和驱动分层，方便用户移植

![image-20231208162813672](C:\Users\disno\AppData\Roaming\Typora\typora-user-images\image-20231208162813672.png)

### 1.1 LCD 显示

1. 电机运行信息：**[READY]** 电机准备就绪	**[START]** 电机运行	**[ERROR]** 电机报警
2. 电机ID：可选择 电机ID 号
3. 电机控制模式：**[MIT.]** MIT控制模式     **[Pos.]** 位置速度模式     **[Vel.]** 速度模式
4. 反馈温度显示
5. 电机参数设置和电机反馈参数显示

### 1.2 按键逻辑

user key：短按使能电机，长按失能电机 (该按键在DM-MC01上)

6. mid_key：短按进入参数设置，长按设置成功

7. up_key：向上选择设置项，(当进入参数设置时，变为参数增加)

8. down_key：向下选择设置项，(当进入参数设置时，变为参数减小)
9. left_key：长按清空电机报错参数
10. right_key：长按清空设置参数

### 1.3 电机ID设置

主控板控制多个电机，我们需要确保在一条CAN总线上：每个电机的 **CAN ID** 和 **Master ID** 不一样，具体可以通过达秒科技调试助手设置。

**注意：Master ID 设置不该和电机返回的一些数据ID重复，也就是在一条总线上 CAN ID 与 Master ID 都不能有相同的ID号**。

![image-20231208150846495](C:\Users\disno\AppData\Roaming\Typora\typora-user-images\image-20231208150846495.png)

**CAN1 上可以挂载两个电机，需要将ID设置为：**

+ MOTOR1：CAN ID 0x01	Master ID 0x00
+ MOTOR3：CAN ID 0x02	Master ID 0x00

**CAN2 上可以挂载一个电机，需要将ID设置为：**

+ MOTOR2：CAN ID 0x01	Master ID 0x00



## 2. 在demo中添加电机

如果需要添加电机demo的控制，主要修改 **dm4310_ctrl** 文件和 **display** 文件即可

### 2.1 添加电机

比如需要添加 Motor4 电机，只需要在下面枚举中添加即可：

```c
typedef enum
{
	Motor1,
	Motor2,
	Motor3,
    ...
	num
} motor_num;
```

然后在下面代码中添加初始化信息，包括电机ID与默认控制模式：

```c
void dm4310_motor_init(void)
{
	// 初始化Motor1和Motor2的电机结构
	memset(&motor[Motor1], 0, sizeof(motor[Motor1]));
	memset(&motor[Motor2], 0, sizeof(motor[Motor2]));
	memset(&motor[Motor3], 0, sizeof(motor[Motor2]));

	// 设置Motor1的电机信息
	motor[Motor1].id = 1;
	motor[Motor1].ctrl.mode = 2;		// 0: MIT模式   1: 位置速度模式   2: 速度模式
	motor[Motor1].cmd.mode = 2;

	// 设置Motor2的电机信息
	motor[Motor2].id = 1;
	motor[Motor2].ctrl.mode = 2;
	motor[Motor2].cmd.mode = 2;
	
	// 设置Motor3的电机信息
	motor[Motor3].id = 2;
	motor[Motor3].ctrl.mode = 2;
	motor[Motor3].cmd.mode = 2;
    
    .....................
}
```

然后在 **dm4310_ctrl.c** 的控制函数里面将所有的 switch case 向后递增，具体可查看demo代码。

### 2.2 接收新电机数据

通过判断接收到的 id 数据来区分每个电机的参数信息，如果增加了电机，这里也要同步增加。

```c
void can1_rx_callback(void)
{
	uint16_t rec_id;
	uint8_t rx_data[8] = {0};
	canx_receive_data(&hcan1, &rec_id, rx_data);
	switch (rec_id)
	{
 		case 0: dm4310_fbdata(&motor[Motor1], rx_data); break;
		case 1: dm4310_fbdata(&motor[Motor3], rx_data); break;
        .....................
	}
}
```

### 2.3 新的电机显示界面修改

同步在 **display.c** 修改增加 Motor4 电机：

```c
void motor_id_display(void)
{
	switch(motor_id)
	{
		case 1:
			motor_start_display(&motor[Motor1]);
			LCD_ShowString(200, 10,(uint8_t *)"MOTOR1", WHITE, BLACK, 24, 0);
			motor_para_display(&motor[Motor1]);
			break;
		case 2:
			motor_start_display(&motor[Motor2]);
			LCD_ShowString(200, 10,(uint8_t *)"MOTOR2", WHITE, BLACK, 24, 0);
			motor_para_display(&motor[Motor2]);
			break;
		case 3:
			motor_start_display(&motor[Motor3]);
			LCD_ShowString(200, 10,(uint8_t *)"MOTOR3", WHITE, BLACK, 24, 0);
			motor_para_display(&motor[Motor3]);
			break;
        .....................
	}
}
```

## 3. 目录结构 

```bash
CtrBoard-DM4310
├─ .mxproject						# STM32CubeMX项目文件
├─ CtrBoard.ioc						# STM32CubeMX项目文件
├─ Core								# HAL库外设配置文件
│    ├─ Inc
│    └─ Src
├─ Drivers							# 底层驱动文件夹							
├─ MDK-ARM							# keil 启动文件夹
├─ README.md
└─ User								# 用户文件
       ├─ bsp
       │    ├─ adc_bsp.c			# 板级 adc 配置文件
       │    ├─ adc_bsp.h			# 板级 adc 配置头文件
       │    ├─ can_bsp.c			# 板级 can 配置文件
       │    ├─ can_bsp.h			# 板级 can 配置头文件
       │    ├─ key_bsp.c			# 板级 key 配置文件
       │    ├─ key_bsp.h			# 板级 key 配置头文件
       │    ├─ led_bsp.c			# 板级 led 配置文件
       │    └─ led_bsp.h			# 板级 led 配置头文件
       ├─ driver
       │    ├─ adc_driver.c			# adc驱动文件
       │    ├─ adc_driver.h			# adc驱动头文件
       │    ├─ can_driver.c			# can驱动文件
       │    ├─ can_driver.h			# can驱动头文件
       │    ├─ drivers.h			# 驱动头文件			
       │    ├─ key_driver.c			# key驱动文件
       │    ├─ key_driver.h			# key驱动头文件
       │    ├─ led_driver.c			# led驱动文件
       │    └─ led_driver.h			# led驱动头文件
       ├─ module
       │   ├─ adc_modlue.c         	# adc模块文件
       │   ├─ adc_modlue.h         	# adc模块头文件
       │   ├─ display.c            	# 显示模块文件
       │   ├─ display.h            	# 显示模块头文件
       │   ├─ key_modlue.c         	# 按键模块文件
       │   ├─ key_modlue.h         	# 按键模块头文件
       │   ├─ lcd.c                	# LCD文件
       │   ├─ lcd.h                	# LCD头文件
       │   ├─ lcdfont.h            	# LCD字体头文件
       │   ├─ mcu_config.c         	# MCU配置文件
       │   ├─ mcu_config.h         	# MCU配置头文件
       │   ├─ pic.h                	# 图片头文件
       │   ├─ scheduler.c          	# 调度器文件
       │   ├─ scheduler.h          	# 调度器头文件
       │   ├─ task.c               	# 任务文件
       │   └─ task.h               	# 任务头文件
       └─ motor
           ├─ dm4310_ctrl.c        	# DM4310电机控制文件
           ├─ dm4310_ctrl.h        	# DM4310电机控制头文件
           ├─ dm4310_drv.c         	# DM4310电机驱动文件
           └─ dm4310_drv.h         	# DM4310电机驱动头文件
```
