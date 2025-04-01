#include "dm_imu.h"

#include "can.h"

imu_t imu;

/**
************************************************************************
* @brief:      	float_to_uint: 浮点数转换为无符号整数函数
* @param[in]:   x_float:	待转换的浮点数
* @param[in]:   x_min:		范围最小值
* @param[in]:   x_max:		范围最大值
* @param[in]:   bits: 		目标无符号整数的位数
* @retval:     	无符号整数结果
* @details:    	将给定的浮点数 x 在指定范围 [x_min, x_max] 内进行线性映射，映射结果为一个指定位数的无符号整数
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
* @brief:      	uint_to_float: 无符号整数转换为浮点数函数
* @param[in]:   x_int: 待转换的无符号整数
* @param[in]:   x_min: 范围最小值
* @param[in]:   x_max: 范围最大值
* @param[in]:   bits:  无符号整数的位数
* @retval:     	浮点数结果
* @details:    	将给定的无符号整数 x_int 在指定范围 [x_min, x_max] 内进行线性映射，映射结果为一个浮点数
************************************************************************
**/
float uint_to_float(int x_int, float x_min, float x_max, int bits)
{
	/* converts unsigned int to float, given range and number of bits */
	float span = x_max - x_min;
	float offset = x_min;
	return ((float)x_int)*span/((float)((1<<bits)-1)) + offset;
}



void IMU_RequestData(uint16_t can_id,uint8_t reg)
{
	CAN_TxHeaderTypeDef tx_header;
	uint8_t cmd[4]={(uint8_t)can_id,(uint8_t)(can_id>>8),reg,0xCC};
	uint32_t returnBox;
	tx_header.DLC=4;
	tx_header.IDE=CAN_ID_STD;
	tx_header.RTR=CAN_RTR_DATA;
	tx_header.StdId=0x6FF;
	
	if(HAL_CAN_GetTxMailboxesFreeLevel(&hcan2)>1)
	{
		HAL_CAN_AddTxMessage(&hcan2,&tx_header,cmd,&returnBox);
	}
}


void IMU_UpdateAccel(uint8_t* pData)
{
	uint16_t accel[3];
	
	accel[0]=pData[3]<<8|pData[2];
	accel[1]=pData[5]<<8|pData[4];
	accel[2]=pData[7]<<8|pData[6];
	
	imu.accel[0]=uint_to_float(accel[0],ACCEL_CAN_MIN,ACCEL_CAN_MAX,16);
	imu.accel[1]=uint_to_float(accel[1],ACCEL_CAN_MIN,ACCEL_CAN_MAX,16);
	imu.accel[2]=uint_to_float(accel[2],ACCEL_CAN_MIN,ACCEL_CAN_MAX,16);
	
}

void IMU_UpdateGyro(uint8_t* pData)
{
	uint16_t gyro[3];
	
	gyro[0]=pData[3]<<8|pData[2];
	gyro[1]=pData[5]<<8|pData[4];
	gyro[2]=pData[7]<<8|pData[6];
	
	imu.gyro[0]=uint_to_float(gyro[0],GYRO_CAN_MIN,GYRO_CAN_MAX,16);
	imu.gyro[1]=uint_to_float(gyro[1],GYRO_CAN_MIN,GYRO_CAN_MAX,16);
	imu.gyro[2]=uint_to_float(gyro[2],GYRO_CAN_MIN,GYRO_CAN_MAX,16);
}


void IMU_UpdateEuler(uint8_t* pData)
{
	int euler[3];
	
	euler[0]=pData[3]<<8|pData[2];
	euler[1]=pData[5]<<8|pData[4];
	euler[2]=pData[7]<<8|pData[6];
	
	imu.pitch=uint_to_float(euler[0],PITCH_CAN_MIN,PITCH_CAN_MAX,16);
	imu.yaw=uint_to_float(euler[1],YAW_CAN_MIN,YAW_CAN_MAX,16);
	imu.roll=uint_to_float(euler[2],ROLL_CAN_MIN,ROLL_CAN_MAX,16);
}


void IMU_UpdateQuaternion(uint8_t* pData)
{
	int w = pData[1]<<6| ((pData[2]&0xF8)>>2);
	int x = (pData[2]&0x03)<<12|(pData[3]<<4)|((pData[4]&0xF0)>>4);
	int y = (pData[4]&0x0F)<<10|(pData[5]<<2)|(pData[6]&0xC0)>>6;
	int z = (pData[6]&0x3F)<<8|pData[7];
	
	imu.q[0] = uint_to_float(w,Quaternion_MIN,Quaternion_MAX,14);
	imu.q[1] = uint_to_float(x,Quaternion_MIN,Quaternion_MAX,14);
	imu.q[2] = uint_to_float(y,Quaternion_MIN,Quaternion_MAX,14);
	imu.q[3] = uint_to_float(z,Quaternion_MIN,Quaternion_MAX,14);
}

void IMU_UpdateData(uint8_t* pData)
{

	switch(pData[0])
	{
		case 1:
			IMU_UpdateAccel(pData);
			break;
		case 2:
			IMU_UpdateGyro(pData);
			break;
		case 3:
			IMU_UpdateEuler(pData);
			break;
		case 4:
			IMU_UpdateQuaternion(pData);
			break;
	}
}