#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

#include "main.h"

extern uint32_t sys_time;

typedef struct
{
	void (*fun)(void);        //运行函数
	uint16_t period;//周期
	uint16_t cnt;
}run_queue_t;

int create_task(void (*fun)(void), uint16_t period);
int scheduler_run(void);



#endif /* __SCHEDULER_H__ */


