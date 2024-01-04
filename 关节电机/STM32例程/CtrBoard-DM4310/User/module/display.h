#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "main.h"
#include "lcd.h"
#include "dm4310_ctrl.h"

void display(void);
void cmd_selection(void);
void motor_id_display(void);
void motor_para_display(motor_t *motor);


#endif /* __DISPLAY_H__ */


