#ifndef __KEY_MODLUE_H__
#define __KEY_MODLUE_H__

#include "main.h"

extern int8_t lcd_flag;
extern uint8_t enter_flag;
extern uint8_t start_flag;
extern uint8_t lcdUpdateFlag;

void motor_start_keyfun(void);
void motor_stop_keyfun(void);
void motor_enter_set(void);
void motor_set(void);
void motor_clear_para(void);
void motor_clear_err(void);
void add_key(void);
void minus_key(void);

#endif /* __KEY_MODLUE_H__ */
