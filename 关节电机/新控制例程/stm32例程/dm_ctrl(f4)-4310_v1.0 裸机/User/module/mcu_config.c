#include "mcu_config.h"
#include "drivers.h"
#include "adc.h"
#include "task.h"
#include "tim.h"
#include "lcd.h"
#include "adc_modlue.h"
#include "dm4310_ctrl.h"

void MCU_Init(void)
{
	task_init();
	
	can_driver_init();
	key_driver_init();
	adc_driver_init();
	led_driver_init();
	
	// 开启LCD背光
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	
	LCD_Init();//LCD初始化
	LCD_Fill(0,0,LCD_W, LCD_H,BLACK);	
	
	dm4310_motor_init();
}

