#include "dm4310_drv.h"
#include "dm4310_ctrl.h"
#include "string.h"

motor_t motor[num];

/**
************************************************************************
* @brief:      	dm4310_motor_init: DM4310电机初始化函数
* @param:      	void
* @retval:     	void
* @details:    	初始化两个DM4310型号的电机，设置默认参数和控制模式。
*               分别初始化Motor1和Motor2，设置ID、控制模式和命令模式等信息。
************************************************************************
**/
void dm4310_motor_init(void)
{
	// 初始化Motor1和Motor2的电机结构
	memset(&motor[Motor1], 0, sizeof(motor[Motor1]));
	memset(&motor[Motor2], 0, sizeof(motor[Motor2]));
	memset(&motor[Motor3], 0, sizeof(motor[Motor3]));
	memset(&motor[Motor4], 0, sizeof(motor[Motor4]));
	memset(&motor[Motor5], 0, sizeof(motor[Motor5]));
	memset(&motor[Motor6], 0, sizeof(motor[Motor6]));

	// 设置Motor1的电机信息
	motor[Motor1].id = 0x01;
	motor[Motor1].ctrl.mode = 0;		// 0: MIT模式   1: 位置速度模式   2: 速度模式
	motor[Motor1].ctrl.vel_set = 1.0f;
	motor[Motor1].ctrl.kd_set = 1.0f;
	
	motor[Motor2].id = 0x02;
	motor[Motor2].ctrl.mode = 0;		// 0: MIT模式   1: 位置速度模式   2: 速度模式
	motor[Motor2].ctrl.vel_set = 1.0f;
	motor[Motor2].ctrl.kd_set = 1.0f;
	
	motor[Motor3].id = 0x03;
	motor[Motor3].ctrl.mode = 0;		// 0: MIT模式   1: 位置速度模式   2: 速度模式
	motor[Motor3].ctrl.vel_set = 1.0f;
	motor[Motor3].ctrl.kd_set = 1.0f;
	
	motor[Motor4].id = 0x04;
	motor[Motor4].ctrl.mode = 0;		// 0: MIT模式   1: 位置速度模式   2: 速度模式
	motor[Motor4].ctrl.vel_set = 1.0f;
	motor[Motor4].ctrl.kd_set = 1.0f;
	
	motor[Motor5].id = 0x05;
	motor[Motor5].ctrl.mode = 0;		// 0: MIT模式   1: 位置速度模式   2: 速度模式
	motor[Motor5].ctrl.vel_set = 1.0f;
	motor[Motor5].ctrl.kd_set = 1.0f;
	
	motor[Motor6].id = 0x06;
	motor[Motor6].ctrl.mode = 0;		// 0: MIT模式   1: 位置速度模式   2: 速度模式
	motor[Motor6].ctrl.vel_set = 1.0f;
	motor[Motor6].ctrl.kd_set = 1.0f;
}

/**
************************************************************************
* @brief:      	fdcan1_rx_callback: CAN1接收回调函数
* @param:      	void
* @retval:     	void
* @details:    	处理CAN1接收中断回调，根据接收到的ID和数据，执行相应的处理。
*               当接收到ID为0时，调用dm4310_fbdata函数更新Motor的反馈数据。
************************************************************************
**/
void fdcan1_rx_callback(void)
{
	uint16_t rec_id;
	uint8_t rx_data[8] = {0};
	fdcanx_receive(&hfdcan1, &rec_id, rx_data);
	switch (rec_id)
	{
 		case 0x11: dm4310_fbdata(&motor[Motor1], rx_data); break;
		case 0x12: dm4310_fbdata(&motor[Motor2], rx_data); break;
		case 0x13: dm4310_fbdata(&motor[Motor3], rx_data); break;
		case 0x14: dm4310_fbdata(&motor[Motor4], rx_data); break;
		case 0x15: dm4310_fbdata(&motor[Motor5], rx_data); break;
		case 0x16: dm4310_fbdata(&motor[Motor6], rx_data); break;
	}
}


