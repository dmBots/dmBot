#include "task.h"
#include "scheduler.h"
//#include "vofa.h"
#include "adc_modlue.h"
#include "drivers.h"
#include "dm4310_ctrl.h"
#include "display.h"
#include "lcd.h"
#include "dm4310_drv.h"

/* 创建任务函数 */
void task_init(void)
{
	create_task(task_1ms, 1);
	create_task(task_2ms, 2);
	create_task(task_5ms, 5);
	create_task(task_10ms, 10);
	create_task(task_100ms, 100);
	create_task(task_500ms, 500);
}

/* 1ms 任务函数 */
void task_1ms(void)
{
	key_process();
	get_key_adc();
}
/* 2ms 任务函数 */
void task_2ms(void)
{

}
/* 5ms 任务函数 */
void task_5ms(void)
{
	ctrl_send();
}
/* 10ms 任务函数 */
void task_10ms(void)
{

}
/* 100ms 任务函数 */
void task_100ms(void)
{
//	display();
}
/* 500ms 任务函数 */
void task_500ms(void)
{
	display();
	led_toggle(led_net_red);
}
