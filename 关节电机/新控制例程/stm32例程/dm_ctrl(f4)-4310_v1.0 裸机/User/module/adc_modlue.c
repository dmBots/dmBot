#include "adc_modlue.h"
#include "drivers.h"
#include "math.h"

uint16_t key_value;
float key_filter_val;
uint8_t key_up;
uint8_t key_down;
uint8_t key_mid;
uint8_t key_left;
uint8_t key_right;

/**
**********************************************************************
* @brief:      	antijamming_filter: 抗扰动滤波函数
* @param[in]: 	value_real: 指向输出实际数值的指针，同时作为输入，用于存储滤波后的值
* @param[in]:   value_new :输入的新值，用于进行滤波
* @param[in]:   err_ware: 输入的扰动允许误差，用于判断是否进行滤波
* @retval:      void
* @details:    	该函数用于对输入的新值进行抗扰动滤波，并将滤波结果存储在value_real指向的地址中。
***********************************************************************
**/
void antijamming_filter(float *value_real, float value_new, uint16_t err_ware)
{
    float temp = 0.1f;

    // 如果当前实际数值与新值之差大于扰动允许误差或小于负扰动允许误差，则进行滤波操作
    if ((*value_real - value_new > err_ware) || (*value_real - value_new < (-1) * err_ware))
        *value_real += (value_new - *value_real) * temp;
}


/**
***********************************************************************
* @brief:      get_key_adc
* @param:			 void
* @retval:     void
* @details:    获取按键adc建值并转化为 0 1 信号
***********************************************************************
**/
void get_key_adc(void)
{
	key_value = (float)adc1_median_filter(KEY);

	/*	ADC原始值跳动超过10才会进行滤波 */
	antijamming_filter(&key_filter_val, key_value, 10);
	
	if (key_value>0 && key_value<100)
		key_mid = 0;
	else
		key_mid = 1;
	if (key_value>2200 && key_value<2500)
		key_up = 0;
	else
		key_up = 1;
	if (key_value>2800 && key_value<3500)
		key_down = 0;
	else
		key_down = 1;
	if (key_value>1500 && key_value<1800)
		key_left = 0;
	else
		key_left = 1;
	if (key_value>700 && key_value<1000)
		key_right = 0;
	else
		key_right = 1;
}







