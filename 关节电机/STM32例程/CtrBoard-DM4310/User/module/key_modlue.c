#include "key_modlue.h"
#include "drivers.h"
#include "dm4310_ctrl.h"
#include "dm4310_drv.h"

int8_t lcd_flag;
uint8_t enter_flag;

/**
************************************************************************
* @brief:      	motor_start_keyfun: 电机启动按键回调函数
* @param:      	void
* @retval:     	void
* @details:    	调用ctrl_enable函数，启动当前选定电机。
************************************************************************
**/
void motor_start_keyfun(void)
{
	ctrl_enable();
}
/**
************************************************************************
* @brief:      	motor_stop_keyfun: 电机停止按键回调函数
* @param:      	void
* @retval:     	void
* @details:    	调用ctrl_disable函数，停止当前选定电机。
************************************************************************
**/
void motor_stop_keyfun(void)
{
	ctrl_disable();
}
/**
************************************************************************
* @brief:      	motor_enter_set: 进入设置按键回调函数
* @param:      	void
* @retval:     	void
* @details:    	根据当前enter_flag状态，切换其值。
*               若enter_flag为1，将其设为0；若为0，将其设为1。
************************************************************************
**/
void motor_enter_set(void)
{
	if (enter_flag)
		enter_flag = 0;
	else
		enter_flag = 1;
}
/**
************************************************************************
* @brief:      	motor_set: 设置电机参数按键回调函数
* @param:      	void
* @retval:     	void
* @details:    	调用ctrl_set函数，设置当前选定电机的参数。
************************************************************************
**/
void motor_set(void)
{
	ctrl_set();
} 
/**
************************************************************************
* @brief:      	motor_clear_para: 清除电机参数按键回调函数
* @param:      	void
* @retval:     	void
* @details:    	调用ctrl_clear函数，清除当前选定电机的参数。
************************************************************************
**/
void motor_clear_para(void)
{
	ctrl_clear_para();
} 
/**
************************************************************************
* @brief:      	motor_clear_err: 清除电机错误信息按键回调函数
* @param:      	void
* @retval:     	void
* @details:    	调用ctrl_clear函数，清除当前选定电机的参数。
************************************************************************
**/
void motor_clear_err(void)
{
	ctrl_clear_err();
}
/**
************************************************************************
* @brief:      	add_key: 增加键函数
* @param:      	void
* @retval:     	void
* @details:    	如果未确认（enter_flag为0），则可以进行参数选择，
*               此时lcd_flag递减。若lcd_flag小于0，则将其设置为6。
*               若确认（enter_flag为1），则调用ctrl_add函数，增加当前选定电机的参数。
************************************************************************
**/
void add_key(void)
{
	if(!enter_flag) // 没有确认才可以进行参数选择
	{
		lcd_flag--;
		if(lcd_flag < 0)
		{
			lcd_flag = 6;
		}
	}
	else
	{
		ctrl_add();
	}
}
/**
************************************************************************
* @brief:      	minus_key: 减少键函数
* @param:      	void
* @retval:     	void
* @details:    	如果未确认（enter_flag为0），则可以进行参数选择，
*               此时lcd_flag递增。若lcd_flag大于6，则将其设置为0。
*               若确认（enter_flag为1），则调用ctrl_minus函数，减少当前选定电机的参数。
************************************************************************
**/
void minus_key(void)
{
	if(!enter_flag) // 没有确认才可以进行参数选择
	{
		lcd_flag++;
		if(lcd_flag > 6)
		{
			lcd_flag = 0;
		}
	}
	else
	{
		ctrl_minus();
	}
}
