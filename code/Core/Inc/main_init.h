#include "main.h"
#include "can.h"
#include "USER_can.h"
#include "Encoder.h"
#include "usart.h"
#include "tim.h"
#include "pid.h"
#include "math.h"
#include "Motor.h"
#include "remote.h"
#include "Chassis.h"
#include "Allocation.h"
extern RC_Ctl_t RC_Ctl;
extern instruct car_instruct;
extern pid_t pid_M1;
extern pid_t pid_M2;
extern pid_t pid_M3;
extern pid_t pid_M4;
void user_init(void);


#define BUFFER_SIZE_usart5  100
extern uint8_t rx_buffer_usart5[100];  //接收数据缓存数组

typedef struct {
  int tim_n;                       
  int tim_n_out;                       
} tim_n;