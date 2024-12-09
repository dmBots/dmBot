#include "dm_motor_drv.h"
#include "fdcan.h"


/**
************************************************************************
* @brief:      	dm_motor_enable
* @param[in]:   hcan:    fdcan struct
* @param[in]:   motor:   motor typedef struct
* @retval:     	void
* @details:    	enable motor control mode
************************************************************************
**/
void dm_motor_enable(hcan_t* hcan, motor_t *motor)
{
	switch(motor->ctrl.mode)
	{
		case mit_mode:
			enable_motor_mode(hcan, motor->id, MIT_MODE);
			break;
		case pos_mode:
			enable_motor_mode(hcan, motor->id, POS_MODE);
			break;
		case spd_mode:
			enable_motor_mode(hcan, motor->id, SPD_MODE);
			break;
		case psi_mode:
			enable_motor_mode(hcan, motor->id, PSI_MODE);
			break;
	}	
}
/**
************************************************************************
* @brief:      	dm_motor_disable
* @param[in]:   hcan:    fdcan struct
* @param[in]:   motor:   motor typedef struct
* @retval:     	void
* @details:    	disable motor control mode
************************************************************************
**/
void dm_motor_disable(hcan_t* hcan, motor_t *motor)
{
	switch(motor->ctrl.mode)
	{
		case mit_mode:
			disable_motor_mode(hcan, motor->id, MIT_MODE);
			break;
		case pos_mode:
			disable_motor_mode(hcan, motor->id, POS_MODE);
			break;
		case spd_mode:
			disable_motor_mode(hcan, motor->id, SPD_MODE);
			break;
		case psi_mode:
			disable_motor_mode(hcan, motor->id, PSI_MODE);
			break;
	}	
	dm_motor_clear_para(motor);
}
/**
************************************************************************
* @brief:      	dm_motor_ctrl_send
* @param[in]:   hcan:    fdcan struct
* @param[in]:   motor:   motor typedef struct
* @retval:     	void
* @details:    	send motor control mode commands
************************************************************************
**/
void dm_motor_ctrl_send(hcan_t* hcan, motor_t *motor)
{
	switch(motor->ctrl.mode)
	{
		case mit_mode:
			mit_ctrl(hcan, motor, motor->id, motor->ctrl.pos_set, motor->ctrl.vel_set, motor->ctrl.kp_set, motor->ctrl.kd_set, motor->ctrl.tor_set);
			break;
		case pos_mode:
			pos_ctrl(hcan, motor->id, motor->ctrl.pos_set, motor->ctrl.vel_set);
			break;
		case spd_mode:
			spd_ctrl(hcan, motor->id, motor->ctrl.vel_set);
			break;
		case psi_mode:
			psi_ctrl(hcan, motor->id,motor->ctrl.pos_set, motor->ctrl.vel_set, motor->ctrl.cur_set);
			break;
	}	
}

/**
************************************************************************
* @brief:      	dm_motor_clear_para
* @param[in]:   hcan:    fdcan struct
* @param[in]:   motor:   motor typedef struct
* @details:    	clear paraments
************************************************************************
**/
void dm_motor_clear_para(motor_t *motor)
{
	motor->ctrl.kd_set 	= 0;
	motor->ctrl.kp_set	= 0;
	motor->ctrl.pos_set = 0;
	motor->ctrl.vel_set = 0;
	motor->ctrl.tor_set = 0;
	motor->ctrl.cur_set = 0;
}
/**
************************************************************************
* @brief:      	dm_motor_clear_err
* @param[in]:   hcan:    fdcan struct
* @param[in]:   motor:   motor typedef struct
* @retval:     	void
* @details:    	clear motor error
************************************************************************
**/
void dm_motor_clear_err(hcan_t* hcan, motor_t *motor)
{
	switch(motor->ctrl.mode)
	{
		case mit_mode:
			clear_err(hcan, motor->id, MIT_MODE);
			break;
		case pos_mode:
			clear_err(hcan, motor->id, POS_MODE);
			break;
		case spd_mode:
			clear_err(hcan, motor->id, SPD_MODE);
			break;
		case psi_mode:
			clear_err(hcan, motor->id, PSI_MODE);
			break;
	}	
}
/**
************************************************************************
* @brief:      	dm_motor_fbdata
* @param[in]:   motor:   motor typedef struct
* @param[in]:   rx_data:  receive data buffer
* @retval:     	void
* @details:    	analyze motor parameters
************************************************************************
**/
void dm_motor_fbdata(motor_t *motor, uint8_t *rx_data)
{
	motor->para.id = (rx_data[0])&0x0F;
	motor->para.state = (rx_data[0])>>4;
	motor->para.p_int=(rx_data[1]<<8)|rx_data[2];
	motor->para.v_int=(rx_data[3]<<4)|(rx_data[4]>>4);
	motor->para.t_int=((rx_data[4]&0xF)<<8)|rx_data[5];
	motor->para.pos = uint_to_float(motor->para.p_int, -motor->tmp.PMAX, motor->tmp.PMAX, 16); // (-12.5,12.5)
	motor->para.vel = uint_to_float(motor->para.v_int, -motor->tmp.VMAX, motor->tmp.VMAX, 12); // (-45.0,45.0)
	motor->para.tor = uint_to_float(motor->para.t_int, -motor->tmp.TMAX, motor->tmp.TMAX, 12); // (-18.0,18.0)
	motor->para.Tmos = (float)(rx_data[6]);
	motor->para.Tcoil = (float)(rx_data[7]);
}

/**
************************************************************************
* @brief:      	float_to_uint: Function to convert a float to an unsigned integer
* @param[in]:   x_float:	Float value to be converted
* @param[in]:   x_min:		Minimum range value
* @param[in]:   x_max:		Maximum range value
* @param[in]:   bits: 		Bit width of the target unsigned integer
* @retval:     	Unsigned integer result
* @details:    	Maps the given float x linearly within the specified range [x_min, x_max] to an unsigned integer of the specified bit width.
************************************************************************
**/

int float_to_uint(float x_float, float x_min, float x_max, int bits)
{
	/* Converts a float to an unsigned int, given range and number of bits */
	float span = x_max - x_min;
	float offset = x_min;
	return (int) ((x_float-offset)*((float)((1<<bits)-1))/span);
}
/**
************************************************************************
* @brief:      	uint_to_float: Function to convert an unsigned integer to a float
* @param[in]:   x_int: Unsigned integer to be converted
* @param[in]:   x_min: Minimum range value
* @param[in]:   x_max: Maximum range value
* @param[in]:   bits:  Bit width of the unsigned integer
* @retval:     	Float result
* @details:    	Maps the given unsigned integer x_int linearly within the specified range [x_min, x_max] to a float.
************************************************************************
**/

float uint_to_float(int x_int, float x_min, float x_max, int bits)
{
	/* converts unsigned int to float, given range and number of bits */
	float span = x_max - x_min;
	float offset = x_min;
	return ((float)x_int)*span/((float)((1<<bits)-1)) + offset;
}

/**
************************************************************************
* @brief:      	enable_motor_mode: Function to enable motor mode
* @param[in]:   hcan:     Pointer to the CAN_HandleTypeDef structure
* @param[in]:   motor_id: Motor ID specifying the target motor
* @param[in]:   mode_id:  Mode ID specifying the mode to enable
* @retval:     	void
* @details:     Sends a command via the CAN bus to enable a specific mode on the targeted motor
************************************************************************
**/
void enable_motor_mode(hcan_t* hcan, uint16_t motor_id, uint16_t mode_id)
{
	uint8_t data[8];
	uint16_t id = motor_id + mode_id;
	
	data[0] = 0xFF;
	data[1] = 0xFF;
	data[2] = 0xFF;
	data[3] = 0xFF;
	data[4] = 0xFF;
	data[5] = 0xFF;
	data[6] = 0xFF;
	data[7] = 0xFC;
	
	fdcanx_send_data(hcan, id, data, 8);
}

/**
************************************************************************
* @brief:      	disable_motor_mode: Function to disable motor mode
* @param[in]:   hcan:     Pointer to the CAN_HandleTypeDef structure
* @param[in]:   motor_id: Motor ID specifying the target motor
* @param[in]:   mode_id:  Mode ID specifying the mode to disable
* @retval:     	void
* @details:     Sends a command via the CAN bus to disable a specific mode on the targeted motor
************************************************************************
**/
void disable_motor_mode(hcan_t* hcan, uint16_t motor_id, uint16_t mode_id)
{
	uint8_t data[8];
	uint16_t id = motor_id + mode_id;
	
	data[0] = 0xFF;
	data[1] = 0xFF;
	data[2] = 0xFF;
	data[3] = 0xFF;
	data[4] = 0xFF;
	data[5] = 0xFF;
	data[6] = 0xFF;
	data[7] = 0xFD;
	
	fdcanx_send_data(hcan, id, data, 8);
}

/**
************************************************************************
* @brief:      	save_pos_zero: Function to save position zero point
* @param[in]:   hcan:     Pointer to the CAN_HandleTypeDef structure
* @param[in]:   motor_id: Motor ID specifying the target motor
* @param[in]:   mode_id:  Mode ID specifying the mode to save position zero point
* @retval:     	void
* @details:     Sends a command via the CAN bus to save the position zero point for a specific motor
************************************************************************
**/
void save_pos_zero(hcan_t* hcan, uint16_t motor_id, uint16_t mode_id)
{
	uint8_t data[8];
	uint16_t id = motor_id + mode_id;
	
	data[0] = 0xFF;
	data[1] = 0xFF;
	data[2] = 0xFF;
	data[3] = 0xFF;
	data[4] = 0xFF;
	data[5] = 0xFF;
	data[6] = 0xFF;
	data[7] = 0xFE;
	
	fdcanx_send_data(hcan, id, data, 8);
}

/**
************************************************************************
* @brief:      	clear_err: Function to clear motor error
* @param[in]:   hcan:     Pointer to the CAN_HandleTypeDef structure
* @param[in]:   motor_id: Motor ID specifying the target motor
* @param[in]:   mode_id:  Mode ID specifying the mode to clear errors
* @retval:     	void
* @details:     Sends a command via the CAN bus to clear errors on a specific motor
************************************************************************
**/
void clear_err(hcan_t* hcan, uint16_t motor_id, uint16_t mode_id)
{
	uint8_t data[8];
	uint16_t id = motor_id + mode_id;
	
	data[0] = 0xFF;
	data[1] = 0xFF;
	data[2] = 0xFF;
	data[3] = 0xFF;
	data[4] = 0xFF;
	data[5] = 0xFF;
	data[6] = 0xFF;
	data[7] = 0xFB;
	
	fdcanx_send_data(hcan, id, data, 8);
}

/**
************************************************************************
* @brief:      	mit_ctrl: MIT mode motor control function
* @param[in]:   hcan:      Pointer to the CAN_HandleTypeDef structure
* @param[in]:   motor_id:  Motor ID specifying the target motor
* @param[in]:   pos:       Position setpoint
* @param[in]:   vel:       Velocity setpoint
* @param[in]:   kp:        Position proportional gain
* @param[in]:   kd:        Position derivative gain
* @param[in]:   tor:       Torque setpoint
* @retval:     	void
* @details:     Sends a control frame in MIT mode to the motor via the CAN bus
************************************************************************
**/
void mit_ctrl(hcan_t* hcan, motor_t *motor, uint16_t motor_id, float pos, float vel,float kp, float kd, float tor)
{
	uint8_t data[8];
	uint16_t pos_tmp,vel_tmp,kp_tmp,kd_tmp,tor_tmp;
	uint16_t id = motor_id + MIT_MODE;

	pos_tmp = float_to_uint(pos, -motor->tmp.PMAX, motor->tmp.PMAX, 16);
	vel_tmp = float_to_uint(vel, -motor->tmp.VMAX, motor->tmp.VMAX, 12);
	tor_tmp = float_to_uint(tor, -motor->tmp.TMAX, motor->tmp.TMAX, 12);
	kp_tmp  = float_to_uint(kp,  KP_MIN, KP_MAX, 12);
	kd_tmp  = float_to_uint(kd,  KD_MIN, KD_MAX, 12);

	data[0] = (pos_tmp >> 8);
	data[1] = pos_tmp;
	data[2] = (vel_tmp >> 4);
	data[3] = ((vel_tmp&0xF)<<4)|(kp_tmp>>8);
	data[4] = kp_tmp;
	data[5] = (kd_tmp >> 4);
	data[6] = ((kd_tmp&0xF)<<4)|(tor_tmp>>8);
	data[7] = tor_tmp;
	
	fdcanx_send_data(hcan, id, data, 8);
}

/**
************************************************************************
* @brief:      	pos_ctrl: Position and speed control function
* @param[in]:   hcan:      Pointer to the CAN_HandleTypeDef structure
* @param[in]:   motor_id:  Motor ID specifying the target motor
* @param[in]:   pos:       Position setpoint
* @param[in]:   vel:       Velocity setpoint
* @retval:     	void
* @details:     Sends a position and speed control command to the motor via the CAN bus
************************************************************************
**/
void pos_ctrl(hcan_t* hcan,uint16_t motor_id, float pos, float vel)
{
	uint16_t id;
	uint8_t *pbuf, *vbuf;
	uint8_t data[8];
	
	id = motor_id + POS_MODE;
	pbuf=(uint8_t*)&pos;
	vbuf=(uint8_t*)&vel;
	
	data[0] = *pbuf;
	data[1] = *(pbuf+1);
	data[2] = *(pbuf+2);
	data[3] = *(pbuf+3);

	data[4] = *vbuf;
	data[5] = *(vbuf+1);
	data[6] = *(vbuf+2);
	data[7] = *(vbuf+3);
	
	fdcanx_send_data(hcan, id, data, 8);
}

/**
************************************************************************
* @brief:      	spd_ctrl: Speed control function
* @param[in]:   hcan:      Pointer to the CAN_HandleTypeDef structure
* @param[in]:   motor_id:  Motor ID specifying the target motor
* @param[in]:   vel:       Velocity setpoint
* @retval:     	void
* @details:     Sends a speed control command to the motor via the CAN bus
************************************************************************
**/
void spd_ctrl(hcan_t* hcan, uint16_t motor_id, float vel)
{
	uint16_t id;
	uint8_t *vbuf;
	uint8_t data[4];
	
	id = motor_id + SPD_MODE;
	vbuf=(uint8_t*)&vel;
	
	data[0] = *vbuf;
	data[1] = *(vbuf+1);
	data[2] = *(vbuf+2);
	data[3] = *(vbuf+3);
	
	fdcanx_send_data(hcan, id, data, 4);
}

/**
************************************************************************
* @brief:      	psi_ctrl: Mixed control mode
* @param[in]:   hcan:      Pointer to the CAN_HandleTypeDef structure
* @param[in]:   motor_id:  Motor ID specifying the target motor
* @param[in]:   pos:       Position setpoint
* @param[in]:   vel:       Velocity setpoint
* @param[in]:   cur:       Current setpoint
* @retval:     	void
* @details:     Sends a mixed control command to the motor via the CAN bus
************************************************************************
**/
void psi_ctrl(hcan_t* hcan, uint16_t motor_id, float pos, float vel,float cur)
{
	uint16_t id;
	uint8_t *pbuf, *vbuf, *cbuf;
	uint8_t data[12];
	
	id = motor_id + PSI_MODE;
	pbuf=(uint8_t*)&pos;
	vbuf=(uint8_t*)&vel;
	cbuf=(uint8_t*)&cur;
	
	data[0] = *pbuf;
	data[1] = *(pbuf+1);
	data[2] = *(pbuf+2);
	data[3] = *(pbuf+3);

	data[4] = *vbuf;
	data[5] = *(vbuf+1);
	data[6] = *(vbuf+2);
	data[7] = *(vbuf+3);

	data[8] = *cbuf;
	data[9] = *(cbuf+1);
	data[10] = *(cbuf+2);
	data[11] = *(cbuf+3);

	fdcanx_send_data(hcan, id, data, 12);
}
/**
************************************************************************
* @brief:      	read_motor_data: Sends a command to read a register
* @param[in]:   id:    Motor CAN ID
* @param[in]:   rid:   Register address
* @retval:     	void
* @details:     Reads motor parameters by sending a CAN command to the motor
************************************************************************
**/
void read_motor_data(uint16_t id, uint8_t rid) 
{
	uint8_t can_id_l = id & 0x0F;
	uint8_t can_id_h = (id >> 4) & 0x0F;
	
	uint8_t data[4] = {can_id_l, can_id_h, 0x33, rid};
	fdcanx_send_data(&hfdcan1, 0x7FF, data, 4);
}

/**
************************************************************************
* @brief:      	read_motor_ctrl_fbdata(uint16_t id, uint8_t rid) 
* @param[in]:   id:    Motor CAN ID
* @retval:     	void
* @details:     Read the control data feedback from the motor
************************************************************************
**/
void read_motor_ctrl_fbdata(uint16_t id) 
{
	uint8_t can_id_l = id & 0x0F;
	uint8_t can_id_h = (id >> 4) & 0x0F;
	
	uint8_t data[4] = {can_id_l, can_id_h, 0xCC, 0x00};
	fdcanx_send_data(&hfdcan1, 0x7FF, data, 4);
}

/**
************************************************************************
* @brief:      	write_motor_data: Sends a command to write to a register
* @param[in]:   id:    Motor CAN ID
* @param[in]:   rid:   Register address
* @param[in]:   d0-d3: Data to write to the register
* @retval:     	void
* @details:     Writes data to a motor register by sending a CAN command
************************************************************************
**/
void write_motor_data(uint16_t id, uint8_t rid, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)
{
	uint8_t can_id_l = id & 0x0F;
	uint8_t can_id_h = (id >> 4) & 0x0F;
	
	uint8_t data[8] = {can_id_l, can_id_h, 0x55, rid, d0, d1, d2, d3};
	fdcanx_send_data(&hfdcan1, 0x7FF, data, 8);
}

/**
************************************************************************
* @brief:      	save_motor_data: Sends a command to save motor data
* @param[in]:   id:    Motor CAN ID
* @param[in]:   rid:   Register address
* @retval:     	void
* @details:     Saves the written motor parameters by sending a CAN command
************************************************************************
**/
void save_motor_data(uint16_t id, uint8_t rid) 
{
	uint8_t can_id_l = id & 0x0F;
	uint8_t can_id_h = (id >> 4) & 0x0F;
	
	uint8_t data[4] = {can_id_l, can_id_h, 0xAA, 0x01};
	fdcanx_send_data(&hfdcan1, 0x7FF, data, 4);
}


