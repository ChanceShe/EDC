#include "FILTER.h"




float y_vel_prev=0;

/***********************************����ת�ٵ�ͨ�˲�*******************************************/
float LPF_velocity(float x)
{
	float y = 0.9*y_vel_prev + 0.1*x;
	
	y_vel_prev=y;
	
	return y;
}

