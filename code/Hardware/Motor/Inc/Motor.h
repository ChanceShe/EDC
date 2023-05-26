
void send_v(int num,float V_send);
void motor_stop(void);
#define DIR1_up   HAL_GPIO_WritePin(DIR1_up_GPIO_Port,DIR1_up_Pin,1),HAL_GPIO_WritePin(DIR1_down_GPIO_Port,DIR1_down_Pin,0);
#define DIR1_down HAL_GPIO_WritePin(DIR1_up_GPIO_Port,DIR1_up_Pin,0),HAL_GPIO_WritePin(DIR1_down_GPIO_Port,DIR1_down_Pin,1);
#define DIR1_stop HAL_GPIO_WritePin(DIR1_up_GPIO_Port,DIR1_up_Pin,0),HAL_GPIO_WritePin(DIR1_down_GPIO_Port,DIR1_down_Pin,0);

#define DIR2_up   HAL_GPIO_WritePin(DIR2_up_GPIO_Port,DIR2_up_Pin,1),HAL_GPIO_WritePin(DIR2_down_GPIO_Port,DIR2_down_Pin,0);
#define DIR2_down HAL_GPIO_WritePin(DIR2_up_GPIO_Port,DIR2_up_Pin,0),HAL_GPIO_WritePin(DIR2_down_GPIO_Port,DIR2_down_Pin,1);
#define DIR2_stop HAL_GPIO_WritePin(DIR2_up_GPIO_Port,DIR2_up_Pin,0),HAL_GPIO_WritePin(DIR2_down_GPIO_Port,DIR2_down_Pin,0);

#define DIR3_up   HAL_GPIO_WritePin(DIR3_up_GPIO_Port,DIR3_up_Pin,1),HAL_GPIO_WritePin(DIR3_down_GPIO_Port,DIR3_down_Pin,0);
#define DIR3_down HAL_GPIO_WritePin(DIR3_up_GPIO_Port,DIR3_up_Pin,0),HAL_GPIO_WritePin(DIR3_down_GPIO_Port,DIR3_down_Pin,1);
#define DIR3_stop HAL_GPIO_WritePin(DIR3_up_GPIO_Port,DIR3_up_Pin,0),HAL_GPIO_WritePin(DIR3_down_GPIO_Port,DIR3_down_Pin,0);

#define DIR4_up   HAL_GPIO_WritePin(DIR4_up_GPIO_Port,DIR4_up_Pin,1),HAL_GPIO_WritePin(DIR4_down_GPIO_Port,DIR4_down_Pin,0);
#define DIR4_down HAL_GPIO_WritePin(DIR4_up_GPIO_Port,DIR4_up_Pin,0),HAL_GPIO_WritePin(DIR4_down_GPIO_Port,DIR4_down_Pin,1);
#define DIR4_stop HAL_GPIO_WritePin(DIR4_up_GPIO_Port,DIR4_up_Pin,0),HAL_GPIO_WritePin(DIR4_down_GPIO_Port,DIR4_down_Pin,0);