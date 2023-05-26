
void get_v(void);

extern float vel_1;                   //速度
extern float vel_2;                   //速度

extern float vel_4;                   //速度
void avg_v1(void);
void avg_v2(void);
void avg_v3(void);
void avg_v4(void);

typedef struct {
  int m_pulse; 
  float vel_now; 	
  float vel_avg;  
  struct 
  { 
    float vel_1; 
		float vel_2; 
		float vel_3; 
		float vel_4; 
		float vel_5; 
		float vel_6; 
		float vel_7; 
		float vel_8; 
		float vel_9; 
		float vel_10;
  }sum; 	
} vel;


extern vel vel_M1;
extern vel vel_M2;
extern vel vel_M3;
extern vel vel_M4;