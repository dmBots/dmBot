#ifndef __CAN_BSP_H__
#define __CAN_BSP_H__
#include "main.h"
#include "can.h"


typedef CAN_HandleTypeDef hcan_t;

void can_bsp_init(void);
void can_filter_init(void);
uint8_t canx_bsp_send_data(hcan_t *hcan, uint16_t id, uint8_t *data, uint32_t len);
uint8_t canx_bsp_receive(hcan_t *hcan, uint16_t *recid, uint8_t *buf);
void can1_rx_callback(void);
void can2_rx_callback(void);

#endif /* __CAN_BSP_H_ */

