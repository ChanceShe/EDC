#include "Encoder.h"
#include "tim.h"
#define _2PI 6.28318530718






long int flag_out=0;                //	圈数
float vel_out=0;                    //给PID的速度
long int UVW_n=0;
float vel_1=0;                   //速度
float vel_2=0;                   //速度
float vel_4=0;                   //速度
float m_pulse_angle=260.0f/_2PI;
int m_pulse_1=0;
int m_pulse_2=0;
int m_pulse_4=0;
float Ts=1/(42000000.0f/(4200.0f*100.0f)) ;       //计算控制周期

vel vel_M1;
vel vel_M2;
vel vel_M3;
vel vel_M4;


void get_v(void)
{
	/********************角度差分计算转速*****************************/
	vel_M1.m_pulse=-(short)__HAL_TIM_GET_COUNTER(&htim3);   //获取定时器的值
	__HAL_TIM_SET_COUNTER(&htim3,0);                //编码器的值清零
	vel_M1.vel_now=vel_M1.m_pulse/m_pulse_angle/Ts;
	avg_v1();
	/*****************************************************************/
	/********************角度差分计算转速*****************************/
	vel_M2.m_pulse=-(short)__HAL_TIM_GET_COUNTER(&htim1);   //获取定时器的值
	__HAL_TIM_SET_COUNTER(&htim1,0);                //编码器的值清零
	vel_M2.vel_now=vel_M2.m_pulse/m_pulse_angle/Ts;
	avg_v2();
	/*****************************************************************/
	/********************角度差分计算转速*****************************/
	vel_M3.m_pulse=(short)__HAL_TIM_GET_COUNTER(&htim2);   //获取定时器的值
	__HAL_TIM_SET_COUNTER(&htim2,0);                //编码器的值清零
	vel_M3.vel_now=vel_M3.m_pulse/m_pulse_angle/Ts;
	avg_v3();
	/*****************************************************************/
	/********************角度差分计算转速*****************************/
	vel_M4.m_pulse=-(short)__HAL_TIM_GET_COUNTER(&htim5);   //获取定时器的值
	__HAL_TIM_SET_COUNTER(&htim5,0);                //编码器的值清零
	vel_M4.vel_now=vel_M4.m_pulse/m_pulse_angle/Ts;
	avg_v4();
	/*****************************************************************/
	
	
	
	
}

void avg_v1(void){
	uint8_t i;
	float sum=0;
  vel_M1.sum.vel_10=vel_M1.sum.vel_9;
	vel_M1.sum.vel_9=vel_M1.sum.vel_8;
	vel_M1.sum.vel_8=vel_M1.sum.vel_7;
	vel_M1.sum.vel_7=vel_M1.sum.vel_6;
	vel_M1.sum.vel_6=vel_M1.sum.vel_5;
	vel_M1.sum.vel_5=vel_M1.sum.vel_4;
	vel_M1.sum.vel_4=vel_M1.sum.vel_3;
	vel_M1.sum.vel_3=vel_M1.sum.vel_2;
	vel_M1.sum.vel_2=vel_M1.sum.vel_1;
	vel_M1.sum.vel_1=vel_M1.vel_now;
	sum=vel_M1.sum.vel_10+vel_M1.sum.vel_9+vel_M1.sum.vel_8+vel_M1.sum.vel_7;
	sum=sum+vel_M1.sum.vel_6+vel_M1.sum.vel_5+vel_M1.sum.vel_4+vel_M1.sum.vel_3+vel_M1.sum.vel_2+vel_M1.sum.vel_1;
	vel_M1.vel_avg=sum/10.0f;
}

void avg_v2(void){
	uint8_t i;
	float sum=0;
  vel_M2.sum.vel_10=vel_M2.sum.vel_9;
	vel_M2.sum.vel_9=vel_M2.sum.vel_8;
	vel_M2.sum.vel_8=vel_M2.sum.vel_7;
	vel_M2.sum.vel_7=vel_M2.sum.vel_6;
	vel_M2.sum.vel_6=vel_M2.sum.vel_5;
	vel_M2.sum.vel_5=vel_M2.sum.vel_4;
	vel_M2.sum.vel_4=vel_M2.sum.vel_3;
	vel_M2.sum.vel_3=vel_M2.sum.vel_2;
	vel_M2.sum.vel_2=vel_M2.sum.vel_1;
	vel_M2.sum.vel_1=vel_M2.vel_now;
	sum=vel_M2.sum.vel_10+vel_M2.sum.vel_9+vel_M2.sum.vel_8+vel_M2.sum.vel_7;
	sum=sum+vel_M2.sum.vel_6+vel_M2.sum.vel_5+vel_M2.sum.vel_4+vel_M2.sum.vel_3+vel_M2.sum.vel_2+vel_M2.sum.vel_1;
	vel_M2.vel_avg=sum/10.0f;
}

void avg_v3(void){
	uint8_t i;
	float sum=0;
  vel_M3.sum.vel_10=vel_M3.sum.vel_9;
	vel_M3.sum.vel_9=vel_M3.sum.vel_8;
	vel_M3.sum.vel_8=vel_M3.sum.vel_7;
	vel_M3.sum.vel_7=vel_M3.sum.vel_6;
	vel_M3.sum.vel_6=vel_M3.sum.vel_5;
	vel_M3.sum.vel_5=vel_M3.sum.vel_4;
	vel_M3.sum.vel_4=vel_M3.sum.vel_3;
	vel_M3.sum.vel_3=vel_M3.sum.vel_2;
	vel_M3.sum.vel_2=vel_M3.sum.vel_1;
	vel_M3.sum.vel_1=vel_M3.vel_now;
	sum=vel_M3.sum.vel_10+vel_M3.sum.vel_9+vel_M3.sum.vel_8+vel_M3.sum.vel_7;
	sum=sum+vel_M3.sum.vel_6+vel_M3.sum.vel_5+vel_M3.sum.vel_4+vel_M3.sum.vel_3+vel_M3.sum.vel_2+vel_M3.sum.vel_1;
	vel_M3.vel_avg=sum/10.0f;
}

void avg_v4(void){
	uint8_t i;
	float sum=0;
  vel_M4.sum.vel_10=vel_M4.sum.vel_9;
	vel_M4.sum.vel_9=vel_M4.sum.vel_8;
	vel_M4.sum.vel_8=vel_M4.sum.vel_7;
	vel_M4.sum.vel_7=vel_M4.sum.vel_6;
	vel_M4.sum.vel_6=vel_M4.sum.vel_5;
	vel_M4.sum.vel_5=vel_M4.sum.vel_4;
	vel_M4.sum.vel_4=vel_M4.sum.vel_3;
	vel_M4.sum.vel_3=vel_M4.sum.vel_2;
	vel_M4.sum.vel_2=vel_M4.sum.vel_1;
	vel_M4.sum.vel_1=vel_M4.vel_now;
	sum=vel_M4.sum.vel_10+vel_M4.sum.vel_9+vel_M4.sum.vel_8+vel_M4.sum.vel_7;
	sum=sum+vel_M4.sum.vel_6+vel_M4.sum.vel_5+vel_M4.sum.vel_4+vel_M4.sum.vel_3+vel_M4.sum.vel_2+vel_M4.sum.vel_1;
	vel_M4.vel_avg=sum/10.0f;
}