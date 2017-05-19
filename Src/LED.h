#ifndef __LED_H__
#define __LED_H__
#include "include.h"

#define GPIO_1	GPIO_PIN_SET
#define GPIO_0	GPIO_PIN_RESET


#define LED_1_OFF     	HAL_GPIO_WritePin(LED_1_GPIO_Port,LED_1_Pin,GPIO_PIN_SET)
#define LED_1_ON		HAL_GPIO_WritePin(LED_1_GPIO_Port,LED_1_Pin,GPIO_PIN_RESET)
#define LED_1_TOG		HAL_GPIO_TogglePin(LED_1_GPIO_Port,LED_1_Pin)
#define SET_1_LED(X)       HAL_GPIO_WritePin(LED_1_GPIO_Port,LED_1_Pin,X)

#define LED_2_OFF     	HAL_GPIO_WritePin(LED_2_GPIO_Port,LED_2_Pin,GPIO_PIN_SET)
#define LED_2_ON		HAL_GPIO_WritePin(LED_2_GPIO_Port,LED_2_Pin,GPIO_PIN_RESET)
#define LED_2_TOG		HAL_GPIO_TogglePin(LED_2_GPIO_Port,LED_2_Pin)
#define SET_2_LED(X)       HAL_GPIO_WritePin(LED_2_GPIO_Port,LED_2_Pin,X)

#define LED_3_OFF     	HAL_GPIO_WritePin(LED_3_GPIO_Port,LED_3_Pin,GPIO_PIN_SET)
#define LED_3_ON		HAL_GPIO_WritePin(LED_3_GPIO_Port,LED_3_Pin,GPIO_PIN_RESET)
#define LED_3_TOG		HAL_GPIO_TogglePin(LED_3_GPIO_Port,LED_3_Pin)
#define SET_3_LED(X)       HAL_GPIO_WritePin(LED_3_GPIO_Port,LED_3_Pin,X)

#define LED_4_OFF     	HAL_GPIO_WritePin(LED_4_GPIO_Port,LED_4_Pin,GPIO_PIN_SET)
#define LED_4_ON		HAL_GPIO_WritePin(LED_4_GPIO_Port,LED_4_Pin,GPIO_PIN_RESET)
#define LED_4_TOG		HAL_GPIO_TogglePin(LED_4_GPIO_Port,LED_4_Pin)
#define SET_4_LED(X)       HAL_GPIO_WritePin(LED_4_GPIO_Port,LED_4_Pin,X)

#define LED_5_OFF     	HAL_GPIO_WritePin(LED_5_GPIO_Port,LED_5_Pin,GPIO_PIN_SET)
#define LED_5_ON		HAL_GPIO_WritePin(LED_5_GPIO_Port,LED_5_Pin,GPIO_PIN_RESET)
#define LED_5_TOG		HAL_GPIO_TogglePin(LED_5_GPIO_Port,LED_5_Pin)
#define SET_5_LED(X)       HAL_GPIO_WritePin(LED_5_GPIO_Port,LED_5_Pin,X)

#define LED_6_OFF     	HAL_GPIO_WritePin(LED_6_GPIO_Port,LED_6_Pin,GPIO_PIN_SET)
#define LED_6_ON		HAL_GPIO_WritePin(LED_6_GPIO_Port,LED_6_Pin,GPIO_PIN_RESET)
#define LED_6_TOG		HAL_GPIO_TogglePin(LED_6_GPIO_Port,LED_6_Pin)
#define SET_6_LED(X)       HAL_GPIO_WritePin(LED_6_GPIO_Port,LED_6_Pin,X)

#define SET_SPK(X) 	HAL_GPIO_WritePin(SPK_GPIO_Port,SPK_Pin,X)

void spk_echo(unsigned char times,unsigned interval);

#endif
