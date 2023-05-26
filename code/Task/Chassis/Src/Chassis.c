#include "main.h"
#include "Chassis.h"
#include "main_init.h"

typedef struct {
  float M1;
	float M2;
	float M3;
	float M4;
} motor_v;

motor_v M_v;

void Chassis_task(void)
{
	get_v();
	M_v.M1=car_instruct.DIR.UD-car_instruct.DIR.RL+car_instruct.DIR.W*19.5f;
	M_v.M2=car_instruct.DIR.UD+car_instruct.DIR.RL-car_instruct.DIR.W*19.5f;
	M_v.M3=car_instruct.DIR.UD-car_instruct.DIR.RL-car_instruct.DIR.W*19.5f;
	M_v.M4=car_instruct.DIR.UD+car_instruct.DIR.RL+car_instruct.DIR.W*19.5f;
	
	send_v(1,M_v.M1);
	send_v(2,M_v.M2);
	send_v(3,M_v.M3);
	send_v(4,M_v.M4);
}
