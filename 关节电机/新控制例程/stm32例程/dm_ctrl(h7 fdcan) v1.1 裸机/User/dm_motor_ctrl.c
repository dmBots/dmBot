#include "dm_motor_drv.h"
#include "dm_motor_ctrl.h"
#include "string.h"
#include "stdbool.h"

motor_t motor[num];


/**
************************************************************************
* @brief:      	dm4310_motor_init: DM4310电机初始化函数
* @param:      	void
* @retval:     	void
* @details:    	初始化1个DM4310型号的电机，设置默认参数和控制模式。
*               设置ID、控制模式和命令模式等信息。
************************************************************************
**/
void dm_motor_init(void)
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
	motor[Motor1].mst_id = 0x00;	// 实际没有用上，只做标识作用
	motor[Motor1].tmp.read_flag = 1;
	motor[Motor1].ctrl.mode 	= mit_mode;
	motor[Motor1].ctrl.vel_set 	= 1.0f;
	motor[Motor1].ctrl.pos_set 	= 10.0f;
	motor[Motor1].ctrl.tor_set 	= 0.03f;
	motor[Motor1].ctrl.cur_set 	= 0.03f;
	motor[Motor1].ctrl.kd_set 	= 2.0f;
	motor[Motor1].tmp.PMAX		= 12.5f;
	motor[Motor1].tmp.VMAX		= 30.0f;
	motor[Motor1].tmp.TMAX		= 10.0f;
}
/**
************************************************************************
* @brief:      	read_all_motor_data: 读取电机的所有寄存器的数据信息
* @param:      	motor_t：电机参数结构体
* @retval:     	void
* @details:    	逐次发送读取命令
************************************************************************
**/
void read_all_motor_data(motor_t *motor)
{
    switch (motor->tmp.read_flag)
    {
		case 1:  read_motor_data(motor->id, RID_UV_VALUE);  break; // UV_Value
		case 2:  read_motor_data(motor->id, RID_KT_VALUE);  break; // KT_Value
		case 3:  read_motor_data(motor->id, RID_OT_VALUE);  break; // OT_Value
		case 4:  read_motor_data(motor->id, RID_OC_VALUE);  break; // OC_Value
		case 5:  read_motor_data(motor->id, RID_ACC);       break; // ACC
		case 6:  read_motor_data(motor->id, RID_DEC);       break; // DEC
		case 7:  read_motor_data(motor->id, RID_MAX_SPD);   break; // MAX_SPD
		case 8:  read_motor_data(motor->id, RID_MST_ID);    break; // MST_ID 
		case 9:  read_motor_data(motor->id, RID_ESC_ID);    break; // ESC_ID
		case 10: read_motor_data(motor->id, RID_TIMEOUT);   break; // TIMEOUT 
		case 11: read_motor_data(motor->id, RID_CMODE);     break; // CTRL_MODE 
		case 12: read_motor_data(motor->id, RID_DAMP);      break; // Damp 
		case 13: read_motor_data(motor->id, RID_INERTIA);   break; // Inertia
		case 14: read_motor_data(motor->id, RID_HW_VER);    break; // Rsv1 
		case 15: read_motor_data(motor->id, RID_SW_VER);    break; // sw_ver 
		case 16: read_motor_data(motor->id, RID_SN);        break; // Rsv2 
		case 17: read_motor_data(motor->id, RID_NPP);       break; // NPP 
		case 18: read_motor_data(motor->id, RID_RS);        break; // Rs 
		case 19: read_motor_data(motor->id, RID_LS);        break; // Ls 
		case 20: read_motor_data(motor->id, RID_FLUX);      break; // Flux 
		case 21: read_motor_data(motor->id, RID_GR);        break; // Gr 
		case 22: read_motor_data(motor->id, RID_PMAX);      break; // PMAX 
		case 23: read_motor_data(motor->id, RID_VMAX);      break; // VMAX 
		case 24: read_motor_data(motor->id, RID_TMAX);      break; // TMAX 
		case 25: read_motor_data(motor->id, RID_I_BW);      break; // I_BW 
		case 26: read_motor_data(motor->id, RID_KP_ASR);    break; // KP_ASR 
		case 27: read_motor_data(motor->id, RID_KI_ASR);    break; // KI_ASR 
		case 28: read_motor_data(motor->id, RID_KP_APR);    break; // KP_APR 
		case 29: read_motor_data(motor->id, RID_KI_APR);    break; // KI_APR 
		case 30: read_motor_data(motor->id, RID_OV_VALUE);  break; // OV_Value 
		case 31: read_motor_data(motor->id, RID_GREF);      break; // GREF 
		case 32: read_motor_data(motor->id, RID_DETA);      break; // Deta 
		case 33: read_motor_data(motor->id, RID_V_BW);      break; // V_BW 
		case 34: read_motor_data(motor->id, RID_IQ_CL);     break; // IQ_c1 
		case 35: read_motor_data(motor->id, RID_VL_CL);     break; // VL_c1 
		case 36: read_motor_data(motor->id, RID_CAN_BR);    break; // can_br 
		case 37: read_motor_data(motor->id, RID_SUB_VER);   break; // sub_ver 
		case 38: read_motor_data(motor->id, RID_U_OFF);     break; // u_off 
		case 39: read_motor_data(motor->id, RID_V_OFF);     break; // v_off 
		case 40: read_motor_data(motor->id, RID_K1);        break; // k1 
		case 41: read_motor_data(motor->id, RID_K2);        break; // k2 
		case 42: read_motor_data(motor->id, RID_M_OFF);     break; // m_off 
		case 43: read_motor_data(motor->id, RID_DIR);       break; // dir 
		case 44: read_motor_data(motor->id, RID_P_M);       break; // pm 
		case 45: read_motor_data(motor->id, RID_X_OUT);     break; // xout 
    }
}
/**
************************************************************************
* @brief:      	receive_motor_data: 接收电机返回的数据信息
* @param:      	motor_t：电机参数结构体
* @param:      	data：接收的数据
* @retval:     	void
* @details:    	逐次接收电机回传的参数信息
************************************************************************
**/
void receive_motor_data(motor_t *motor, uint8_t *data)
{
	if(motor->tmp.read_flag == 0)
		return ;
	
	float_type_u y;
	
	if(data[2] == 0x33)
	{
		uint16_t rid_value = data[3];
		y.b_val[0] = data[4];
		y.b_val[1] = data[5];
		y.b_val[2] = data[6];
		y.b_val[3] = data[7];
		
		switch (rid_value) 
		{
			case RID_UV_VALUE: motor->tmp.UV_Value = y.f_val; motor->tmp.read_flag =  2; break;
			case RID_KT_VALUE: motor->tmp.KT_Value = y.f_val; motor->tmp.read_flag =  3; break;
			case RID_OT_VALUE: motor->tmp.OT_Value = y.f_val; motor->tmp.read_flag =  4; break;
			case RID_OC_VALUE: motor->tmp.OC_Value = y.f_val; motor->tmp.read_flag =  5; break;
			case RID_ACC:      motor->tmp.ACC      = y.f_val; motor->tmp.read_flag =  6; break;
			case RID_DEC:      motor->tmp.DEC      = y.f_val; motor->tmp.read_flag =  7; break;
			case RID_MAX_SPD:  motor->tmp.MAX_SPD  = y.f_val; motor->tmp.read_flag =  8; break;
			case RID_MST_ID:   motor->tmp.MST_ID   = y.u_val; motor->tmp.read_flag =  9; break;
			case RID_ESC_ID:   motor->tmp.ESC_ID   = y.u_val; motor->tmp.read_flag = 10; break;
			case RID_TIMEOUT:  motor->tmp.TIMEOUT  = y.u_val; motor->tmp.read_flag = 11; break;
			case RID_CMODE:    motor->tmp.cmode    = y.u_val; motor->tmp.read_flag = 12; break;
			case RID_DAMP:     motor->tmp.Damp     = y.f_val; motor->tmp.read_flag = 13; break;
			case RID_INERTIA:  motor->tmp.Inertia  = y.f_val; motor->tmp.read_flag = 14; break;
			case RID_HW_VER:   motor->tmp.hw_ver   = y.u_val; motor->tmp.read_flag = 15; break;
			case RID_SW_VER:   motor->tmp.sw_ver   = y.u_val; motor->tmp.read_flag = 16; break;
			case RID_SN:       motor->tmp.SN       = y.u_val; motor->tmp.read_flag = 17; break;
			case RID_NPP:      motor->tmp.NPP      = y.u_val; motor->tmp.read_flag = 18; break;
			case RID_RS:       motor->tmp.Rs       = y.f_val; motor->tmp.read_flag = 19; break;
			case RID_LS:       motor->tmp.Ls       = y.f_val; motor->tmp.read_flag = 20; break;
			case RID_FLUX:     motor->tmp.Flux     = y.f_val; motor->tmp.read_flag = 21; break;
			case RID_GR:       motor->tmp.Gr       = y.f_val; motor->tmp.read_flag = 22; break;
			case RID_PMAX:     motor->tmp.PMAX     = y.f_val; motor->tmp.read_flag = 23; break;
			case RID_VMAX:     motor->tmp.VMAX     = y.f_val; motor->tmp.read_flag = 24; break;
			case RID_TMAX:     motor->tmp.TMAX     = y.f_val; motor->tmp.read_flag = 25; break;
			case RID_I_BW:     motor->tmp.I_BW     = y.f_val; motor->tmp.read_flag = 26; break;
			case RID_KP_ASR:   motor->tmp.KP_ASR   = y.f_val; motor->tmp.read_flag = 27; break;
			case RID_KI_ASR:   motor->tmp.KI_ASR   = y.f_val; motor->tmp.read_flag = 28; break;
			case RID_KP_APR:   motor->tmp.KP_APR   = y.f_val; motor->tmp.read_flag = 29; break;
			case RID_KI_APR:   motor->tmp.KI_APR   = y.f_val; motor->tmp.read_flag = 30; break;
			case RID_OV_VALUE: motor->tmp.OV_Value = y.f_val; motor->tmp.read_flag = 31; break;
			case RID_GREF:     motor->tmp.GREF     = y.f_val; motor->tmp.read_flag = 32; break;
			case RID_DETA:     motor->tmp.Deta     = y.f_val; motor->tmp.read_flag = 33; break;
			case RID_V_BW:     motor->tmp.V_BW     = y.f_val; motor->tmp.read_flag = 34; break;
			case RID_IQ_CL:    motor->tmp.IQ_cl    = y.f_val; motor->tmp.read_flag = 35; break;
			case RID_VL_CL:    motor->tmp.VL_cl    = y.f_val; motor->tmp.read_flag = 36; break;
			case RID_CAN_BR:   motor->tmp.can_br   = y.u_val; motor->tmp.read_flag = 37; break;
			case RID_SUB_VER:  motor->tmp.sub_ver  = y.u_val; motor->tmp.read_flag = 38; break;
			case RID_U_OFF:    motor->tmp.u_off    = y.f_val; motor->tmp.read_flag = 39; break;
			case RID_V_OFF:    motor->tmp.v_off    = y.f_val; motor->tmp.read_flag = 40; break;
			case RID_K1:       motor->tmp.k1       = y.f_val; motor->tmp.read_flag = 41; break;
			case RID_K2:       motor->tmp.k2       = y.f_val; motor->tmp.read_flag = 42; break;
			case RID_M_OFF:    motor->tmp.m_off    = y.f_val; motor->tmp.read_flag = 43; break;
			case RID_DIR:      motor->tmp.dir      = y.f_val; motor->tmp.read_flag = 44; break;
			case RID_P_M:      motor->tmp.p_m      = y.f_val; motor->tmp.read_flag = 45; break;
			case RID_X_OUT:    motor->tmp.x_out    = y.f_val; motor->tmp.read_flag = 0 ; break;
		}
	}
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
 		case 0x00: dm_motor_fbdata(&motor[Motor1], rx_data); receive_motor_data(&motor[Motor1], rx_data); break;
	}
}


