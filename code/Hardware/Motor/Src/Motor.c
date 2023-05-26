#include "Motor.h"
#include "tim.h"
#include "gpio.h"
#include "main_init.h"

int PWM_crr=10;
float PWM_duty_1=0;
float PWM_duty_2=0;
float PWM_duty_3=0;
float PWM_duty_4=0;

void send_v(int num,float V_send)
{
	switch (num)
  {
  	case 1:
			PWM_duty_1=pid_calc(&pid_M1,vel_M1.vel_avg,V_send);
			if(PWM_duty_1>=0)
			{
				 DIR1_up;
				__HAL_TIM_SET_COMPARE(&htim12,TIM_CHANNEL_1,PWM_duty_1*PWM_crr);      //输出PWM,配置占空比
			}
			else
			{
				 DIR1_down;
				__HAL_TIM_SET_COMPARE(&htim12,TIM_CHANNEL_1,-PWM_duty_1*PWM_crr);      //输出PWM,配置占空比
			}
			
  		break;
		case 2:
			PWM_duty_2=pid_calc(&pid_M2,vel_M2.vel_avg,V_send);
			if(PWM_duty_2>=0)
			{
				 DIR2_up;
				__HAL_TIM_SET_COMPARE(&htim8,TIM_CHANNEL_3,PWM_duty_2*PWM_crr);      //输出PWM,配置占空比
			}
			else
			{
				 DIR2_down;
				__HAL_TIM_SET_COMPARE(&htim8,TIM_CHANNEL_3,-PWM_duty_2*PWM_crr);      //输出PWM,配置占空比
			}
			
  		break;
  	case 3:
			PWM_duty_3=pid_calc(&pid_M3,vel_M3.vel_avg,V_send);
			if(PWM_duty_3>=0)
			{
				 DIR3_up;
				__HAL_TIM_SET_COMPARE(&htim8,TIM_CHANNEL_4,PWM_duty_3*PWM_crr);      //输出PWM,配置占空比
			}
			else
			{
				 DIR3_down;
				__HAL_TIM_SET_COMPARE(&htim8,TIM_CHANNEL_4,-PWM_duty_3*PWM_crr);      //输出PWM,配置占空比
			}
			
  		break;
		case 4:
			PWM_duty_4=pid_calc(&pid_M4,vel_M4.vel_avg,V_send);
			if(PWM_duty_4>=0)
			{
				 DIR4_down;
				__HAL_TIM_SET_COMPARE(&htim12,TIM_CHANNEL_2,PWM_duty_4*PWM_crr);      //输出PWM,配置占空比
			}
			else
			{
				 DIR4_up;
				__HAL_TIM_SET_COMPARE(&htim12,TIM_CHANNEL_2,-PWM_duty_4*PWM_crr);      //输出PWM,配置占空比
			}
			
  		break;	
  	default:
  		break;
  }
}
void motor_stop(void)
{
  DIR1_stop;
	DIR2_stop;
	DIR3_stop;
	DIR4_stop;
}

