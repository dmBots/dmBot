#ifndef __ADC_MODLUE_H__
#define __ADC_MODLUE_H__

#include "main.h"

extern uint8_t key_up;
extern uint8_t key_down;
extern uint8_t key_mid;
extern uint8_t key_left;
extern uint8_t key_right;

typedef enum
{
	KEY 	= 0,
} adc1_num;

void get_key_adc(void);

#endif /* __MODLUE_H__ */
