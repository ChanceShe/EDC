#include "main.h"
#include "main_init.h"
#include "usart.h"
#include "remote.h"

RC_Ctl_t RC_Ctl;
instruct car_instruct;


void USART5_IdleCallback()
{
	
 RC_Ctl.rc.ch0 = (rx_buffer_usart5[0]| (rx_buffer_usart5[1] << 8)) & 0x07ff; //!< Channel 0
 RC_Ctl.rc.ch1 = ((rx_buffer_usart5[1] >> 3) | (rx_buffer_usart5[2] << 5)) & 0x07ff; 
 //!< Channel 1 
 RC_Ctl.rc.ch2 = ((rx_buffer_usart5[2] >> 6) | (rx_buffer_usart5[3] << 2) | //!< Channel 2 
 (rx_buffer_usart5[4] << 10)) & 0x07ff; 
 RC_Ctl.rc.ch3 = ((rx_buffer_usart5[4] >> 1) | (rx_buffer_usart5[5] << 7)) & 0x07ff;
 //!< Channel 3 
 RC_Ctl.rc.s1 = ((rx_buffer_usart5[5] >> 4)& 0x000C) >> 2; //!< Switch left 
 RC_Ctl.rc.s2 = ((rx_buffer_usart5[5] >> 4)& 0x0003); //!< Switch right
 car_instruct.DIR.UD=(RC_Ctl.rc.ch1-1024)/10.0f;
 car_instruct.DIR.RL=(RC_Ctl.rc.ch0-1024)/70.0f;
 car_instruct.DIR.W =-(RC_Ctl.rc.ch2-1024)/200.0f;
 switch (RC_Ctl.rc.s1)
 {
  	case 1:
			car_instruct.other.door_1=1;	
  		break;
  	case 3:
			car_instruct.other.door_1=2;	
  		break;
  	default:
			car_instruct.other.door_1=0;	
  		break;
  }	
  if (car_instruct.other.rocker_1==0 && RC_Ctl.rc.ch3 >1400)
	{
		car_instruct.other.rocker_1=2;
	}
  if (car_instruct.other.rocker_1==1 && RC_Ctl.rc.ch3 >1400)
	{
		car_instruct.other.rocker_1=2;
	}
	if (car_instruct.other.rocker_1==2 && RC_Ctl.rc.ch3 <400)
	{
		car_instruct.other.rocker_1=1;
	}
		
	
	for(uint16_t i=0;i<40;i++){
	   rx_buffer_usart5[i]=0;
	}	
	HAL_UART_DMAStop(&huart5); 
	HAL_UART_Receive_DMA(&huart5,rx_buffer_usart5,BUFFER_SIZE_usart5);
}




