#ifndef __INCLUDE_H__
#define __INCLUDE_H__


#include <math.h>
#include <stdlib.h>

#include "stm32f1xx_hal.h"
//#include "object.h"
#include "freertos.h"
#include "cmsis_os.h"
#include "key.h"
#include "LED.h"
#include "crc.h"
//#include "FLASH.h"
#include "gpio.h"
#include "usart.h"
//#include "tim.h"
//#include "iap.h"
#include "cpu.h"
#include "CSE7790.h"

//#include "gateway.h"
////////////////////////////////define in main

#define WIFI_DATA_OK 0X56
#define TCM_300_DATA_OK 0X65


/////////////////////////////// funtion in main

void save_tem_hum_buf(unsigned int tem,unsigned int hum);
void average_tem_hum(void);
void change_tem(void);
void change_hum(void);
unsigned compare_id(void);
unsigned char switch_speed(void);


//////////////////////////////


#endif

