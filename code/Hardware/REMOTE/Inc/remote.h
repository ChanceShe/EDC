#ifndef __REMOTE_H
#define __REMOTE_H	 

#include "main.h"
void USART5_IdleCallback();


typedef struct 
{ 
 struct 
 { 
     uint16_t ch0; 
     uint16_t ch1; 
     uint16_t ch2; 
     uint16_t ch3; 
     uint8_t s1; 
     uint8_t s2; 
 }rc;
 struct 
 { 
     int16_t x; 
     int16_t y; 
     int16_t z; 
     uint8_t press_l; 
     uint8_t press_r; 
 }mouse; 
 struct 
 { 
 	uint16_t v; 
 }key; 
}RC_Ctl_t;

typedef struct 
{	
 struct 
 { 
     float UD; 
     float RL; 
	   float W; 
 }DIR;
 struct 
 { 
     int16_t door_1; 
     int16_t rocker_1; 
     int16_t z; 
 }other; 
}instruct;


#endif
