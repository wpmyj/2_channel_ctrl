#include "led.h"

void spk_echo(unsigned char times,unsigned interval)
{
	unsigned char loopx;
	for(loopx = 0;loopx < times; loopx++)
		{
		  SET_SPK(GPIO_1);
		  osDelay(interval);
		  SET_SPK(GPIO_0);
		  osDelay(80);
		}
}

