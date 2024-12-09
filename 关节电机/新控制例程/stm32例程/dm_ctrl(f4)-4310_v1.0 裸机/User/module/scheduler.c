#include "scheduler.h"
#include <stdio.h>

#define MAX_TASKS 100
uint8_t task_num = 0;
uint32_t time;
uint32_t sys_time;
run_queue_t run_queue[MAX_TASKS] = {0};
/**
***********************************************************************
* @brief:      create_task(void (*fun)(void), uint16_t period)
* @param[in]:	 (*fun)(void) 任务函数
* @param[in]:	 period       任务周期
* @retval:     void
* @details:    创建任务函数 
***********************************************************************
**/
int create_task(void (*fun)(void), uint16_t period)
{
	if(task_num >= MAX_TASKS)
		return -1;
	
	run_queue[task_num].fun = fun;
	run_queue[task_num].period = period;
	run_queue[task_num].cnt = period;

	task_num++;
	
	return 0;
}
/**
***********************************************************************
* @brief:      scheduler_run(void)
* @param[in]:	 (*fun)(void) 任务函数
* @param[in]:	 period       任务周期
* @retval:     void
* @details:    任务函数按周期运行 
***********************************************************************
**/
int scheduler_run(void)
{
	uint8_t i;
	if(time - sys_time > 1)
	{
		for(i = 0; i < task_num; i++)
		{
			if(run_queue[i].cnt > 0)
			{
				run_queue[i].cnt--;
			}
			else
			{
				run_queue[i].cnt = run_queue[i].period;
				run_queue[i].fun();
			}
		}
		time = sys_time;
	}
	return 0;
}
