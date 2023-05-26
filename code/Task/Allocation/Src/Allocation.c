#include "main.h"
#include "main_init.h"
uint8_t can1_Data[8];

char data_send[10] = {0}; //向后板发送的数据

void Allocation_task(void)
{
	send_to_G0();
	HAL_UART_Transmit_DMA(&huart3, (uint8_t *)data_send, sizeof(data_send));	

switch (RC_Ctl.rc.s2)
{

	case 1:
	{
  
	Chassis_task();	
	can1_Data[0] = 1;
	USER_CAN1_transmit(can1_Data,8,1,0x5);	//can1发送	

	}
		break;
	case 2:
	{
	motor_stop();	
	can1_Data[0] = 0;
	USER_CAN1_transmit(can1_Data,8,1,0x5);	//can1发送	
	}
		break;
	default:
		break;
}

	
	
}

void send_to_G0(void)
{
	switch (car_instruct.other.door_1)
  {
  	case 1:
			data_send[0] = 0x01;	
  		break;
  	case 2:
			data_send[0] = 0x02;	
  		break;
  	default:
			data_send[0] = 0x0;	
  		break;
  }
		switch (car_instruct.other.rocker_1)
  {
  	case 1:
			data_send[1] = 0x02;	
  		break;
  	case 2:
			data_send[1] = 0x01;	
  		break;
  	default:
			data_send[1] = 0x0;	
  		break;
  }
	

}