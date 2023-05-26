#include "main.h"
#include "USER_can.h"

#include "main_init.h"

//can1发送函数
CAN_TxHeaderTypeDef TxHeader;
void USER_CAN1_transmit(uint8_t*TxData,uint8_t TxDatalen,int BOX,int can1_id)
{
	
  TxHeader.RTR = CAN_RTR_DATA;   //选择帧种类（数据帧、遥控帧）
  TxHeader.IDE = CAN_ID_STD;     //选择标准长度ID和扩展长度ID 
  TxHeader.DLC = TxDatalen;	         //发送几位的数据（1-8）
//  TxHeader.StdId=0x405;
	TxHeader.StdId=can1_id;
	
	if (BOX==0){
  if (HAL_CAN_AddTxMessage(&hcan1, &TxHeader, TxData, (uint32_t*)CAN_TX_MAILBOX0) != HAL_OK)
    {
     /* Transmission request Error */
     Error_Handler();
    }
	}
	
	if (BOX==1){
  if (HAL_CAN_AddTxMessage(&hcan1, &TxHeader, TxData, (uint32_t*)CAN_TX_MAILBOX1) != HAL_OK)
    {
     /* Transmission request Error */
     Error_Handler();
    }
	}
	
	if (BOX==2){
  if (HAL_CAN_AddTxMessage(&hcan1, &TxHeader, TxData, (uint32_t*)CAN_TX_MAILBOX2) != HAL_OK)
    {
     /* Transmission request Error */
     Error_Handler();
    }
	}
}



