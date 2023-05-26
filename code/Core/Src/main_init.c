#include "main.h"
#include "main_init.h"




uint8_t rx_buffer_usart5[100]={0};  //�������ݻ������飨���ջ���

int f_init=0;


tim_n tim_ctrl;

pid_t pid_M1;
pid_t pid_M2;
pid_t pid_M3;
pid_t pid_M4;


void user_init(void)
{


	
	//ʹ�ܶ�ʱ��7�ж�	
	HAL_TIM_Base_Start_IT(&htim7);
  //ʹ�ܶ�ʱ��10�ж�	
	HAL_TIM_Base_Start_IT(&htim10);    
	//ʹ�ܶ�ʱ��14�ж�	
	HAL_TIM_Base_Start_IT(&htim14);  
	//������32λ 
  HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL); 
		//������16λ 
  HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL); 
			//������16λ 
  HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL); 
				//������16λ 
  HAL_TIM_Encoder_Start(&htim5, TIM_CHANNEL_ALL); 
	//�������PWM
	HAL_TIM_PWM_Start(&htim8,TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim8,TIM_CHANNEL_4);
	HAL_TIM_PWM_Start(&htim12,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim12,TIM_CHANNEL_2);
	PID_struct_init(&pid_M1,POSITION_PID,10,2,0.6f,0.02f,0.0f); //M1 PID INIT
	PID_struct_init(&pid_M2,POSITION_PID,10,2,0.6f,0.02f,0.0f); //M2 PID INIT
	PID_struct_init(&pid_M3,POSITION_PID,10,2,0.1f,0.01f,0.0f); //M3 PID INIT
	PID_struct_init(&pid_M4,POSITION_PID,10,2,0.1f,0.01f,0.0f); //M4 PID INIT
	
	if (HAL_CAN_Start(&hcan1) != HAL_OK) //can1
  {
    /* Start Error */
    Error_Handler();
  }
	
	HAL_GPIO_WritePin(red_GPIO_Port,red_Pin,0);
	

	
	
	f_init=1;
	HAL_Delay(10);

	
}



void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

	if (htim->Instance == TIM7 && f_init==1) //200hz
	{
	Allocation_task();
  tim_ctrl.tim_n++;
  }
	
	
	if (htim->Instance == TIM10 && f_init==1) //40hz ���ƵƵ����� ����ָ������
	{
	
  }
	
	

	
	if (htim->Instance == TIM14 && f_init==1) //1hz
	{

	tim_ctrl.tim_n_out =tim_ctrl.tim_n;
  tim_ctrl.tim_n     =0;
  HAL_GPIO_TogglePin(green_GPIO_Port,green_Pin);	
  }	
}


