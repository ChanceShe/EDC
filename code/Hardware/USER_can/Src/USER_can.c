#include "main.h"
#include "USER_can.h"

#include "main_init.h"

//can1���ͺ���
CAN_TxHeaderTypeDef TxHeader;
void USER_CAN1_transmit(uint8_t*TxData,uint8_t TxDatalen,int BOX,int can1_id)
{
	
  TxHeader.RTR = CAN_RTR_DATA;   //ѡ��֡���ࣨ����֡��ң��֡��
  TxHeader.IDE = CAN_ID_STD;     //ѡ���׼����ID����չ����ID 
  TxHeader.DLC = TxDatalen;	         //���ͼ�λ�����ݣ�1-8��
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



