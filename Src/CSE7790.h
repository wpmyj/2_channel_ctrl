#ifndef __CSE7790_H__
#define __CSE7790_H__
#include "include.h"

#define ENABLE_CSE7790	HAL_GPIO_WritePin(SPI1_CS_GPIO_Port,SPI1_CS_Pin,GPIO_PIN_RESET)
#define DISABLE_CSE7790	HAL_GPIO_WritePin(SPI1_CS_GPIO_Port,SPI1_CS_Pin,GPIO_PIN_SET)



unsigned int read_cse7790(unsigned char address,unsigned char data_length);
void write_cse7790(unsigned char address,unsigned int value,unsigned char data_length);
void enable_cse7790_write(void);
void disable_cse7790_write(void);
void enable_cse7790_channelA(void);
void enable_cse7790_channelB(void);
void reset_cse7790(void);

#endif

