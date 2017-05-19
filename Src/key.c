#include "include.h"

key_data_def rtos_key;
extern osMessageQId key_queueHandle;

void test(void)
{
	static unsigned int data[20];
	unsigned char loopx;
	
	for(loopx = 0; loopx<6 ; loopx ++)
		{
			enable_cse7790_write();
			write_cse7790(loopx,(unsigned int)loopx,2);
			disable_cse7790_write();
		}
	HAL_Delay(100);
	for(loopx = 0; loopx<6 ; loopx ++)
		{
			data[loopx] = read_cse7790(loopx,2);
		}
	
	data[0] = read_cse7790(0X7f,3);
	if(data[0] == 1)
		{
			data[0] --;
		}
	data[0]++;
	return;
}

void read_key(void)
{
unsigned char key_trigger_value;
if(GPIO_PIN_RESET == Read_KEY_1) 
  		{
  			rtos_key.press_time[0] = (rtos_key.press_time[0] >0XEE) ? 0XEE : rtos_key.press_time[0] ;
  			rtos_key.press_time[0] ++;
  		}

	  if(GPIO_PIN_RESET == Read_KEY_2) 
  		{
  			rtos_key.press_time[1] = (rtos_key.press_time[1] >0XEE) ? 0XEE : rtos_key.press_time[1] ;
  			rtos_key.press_time[1] ++;
  		}

	 if(GPIO_PIN_RESET == Read_KEY_3) 
  		{
  			rtos_key.press_time[2] = (rtos_key.press_time[2] >0XEE) ? 0XEE : rtos_key.press_time[2] ;
  			rtos_key.press_time[2] ++;
  		}

	if(GPIO_PIN_RESET == Read_KEY_4) 
  		{
  			rtos_key.press_time[3] = (rtos_key.press_time[3] >0XEE) ? 0XEE : rtos_key.press_time[3] ;
  			rtos_key.press_time[3] ++;
  		}

	if(GPIO_PIN_RESET == Read_KEY_5) 
  		{
  			rtos_key.press_time[4] = (rtos_key.press_time[4] >0XEE) ? 0XEE : rtos_key.press_time[4] ;
  			rtos_key.press_time[4] ++;
  		}
	if(GPIO_PIN_RESET == Read_KEY_6) 
  		{
  			rtos_key.press_time[5] = (rtos_key.press_time[5] >0XEE) ? 0XEE : rtos_key.press_time[5] ;
  			rtos_key.press_time[5] ++;
  		}
	if(GPIO_PIN_RESET == Read_KEY_7) 
  		{
  			rtos_key.press_time[6] = (rtos_key.press_time[6] >0XEE) ? 0XEE : rtos_key.press_time[6] ;
  			rtos_key.press_time[6] ++;
  		}
	

	
	for(rtos_key.key_point = 0; rtos_key.key_point <8 ;rtos_key.key_point++)
		{
			if((rtos_key.press_time[rtos_key.key_point ]) > 2)
				{
					rtos_key.key_value[rtos_key.key_point ] = key_press(rtos_key.key_point);	
						if((rtos_key.key_ok[rtos_key.key_point ]&0X01) == 0)
									{
										rtos_key.key_ok[rtos_key.key_point ] |= 0X01; 
										key_trigger_value =rtos_key.key_point;
										xQueueSend(key_queueHandle, &(key_trigger_value), 10);
									}
					if((rtos_key.press_time[rtos_key.key_point ]) > 0X40)
						{
							rtos_key.key_value[rtos_key.key_point ] = key_long_press(rtos_key.key_point);
							if((rtos_key.key_ok[rtos_key.key_point ]&0X02) == 0)
								{
									rtos_key.key_ok[rtos_key.key_point ] |= 0X02; 
									key_trigger_value =KEY_LONG_TRIGGER(rtos_key.key_point);
									xQueueSend(key_queueHandle, &(key_trigger_value), 10);
								}
						}
					if((rtos_key.press_time[rtos_key.key_point ]) > 0XAF)
						{
							rtos_key.key_value[rtos_key.key_point ] = key_long_long_press(rtos_key.key_point);
							if((rtos_key.key_ok[rtos_key.key_point ]&0X04) == 0)
								{
									rtos_key.key_ok[rtos_key.key_point ] |= 0X04; 
									key_trigger_value =KEY_LONG_LONG_TRIGGER(rtos_key.key_point);
									xQueueSend(key_queueHandle, &(key_trigger_value), 10);
								}
						}

				}
		}



	
	if(GPIO_PIN_SET == Read_KEY_1) 
		{
			if(rtos_key.key_ok[0])
				{
					rtos_key.key_ok[0] = 0;
					xQueueSend(key_queueHandle, &(rtos_key.key_value[0]), 10);
				}
			rtos_key.press_time[0] = 0;
		}
	
	if(GPIO_PIN_SET == Read_KEY_2) 
		{
			if(rtos_key.key_ok[1])
				{
					rtos_key.key_ok[1] = 0;
					xQueueSend(key_queueHandle, &(rtos_key.key_value[1]), 10);
				}
			rtos_key.press_time[1] = 0;
		}

	if(GPIO_PIN_SET == Read_KEY_3) 
		{
			if(rtos_key.key_ok[2])
				{
					rtos_key.key_ok[2] = 0;
					xQueueSend(key_queueHandle, &(rtos_key.key_value[2]), 10);
				}
			rtos_key.press_time[2] = 0;
		}

	if(GPIO_PIN_SET == Read_KEY_4) 
		{
			if(rtos_key.key_ok[3])
				{
					rtos_key.key_ok[3] = 0;
					xQueueSend(key_queueHandle, &(rtos_key.key_value[3]), 10);
				}
			rtos_key.press_time[3] = 0;
		}

	if(GPIO_PIN_SET == Read_KEY_5) 
		{
			if(rtos_key.key_ok[4])
				{
					rtos_key.key_ok[4] = 0;
					xQueueSend(key_queueHandle, &(rtos_key.key_value[4]), 10);
				}
			rtos_key.press_time[4] = 0;
		}

	if(GPIO_PIN_SET == Read_KEY_6) 
		{
			if(rtos_key.key_ok[5])
				{
					rtos_key.key_ok[5] = 0;
					xQueueSend(key_queueHandle, &(rtos_key.key_value[5]), 10);
				}
			rtos_key.press_time[5] = 0;
		}

	if(GPIO_PIN_SET == Read_KEY_7) 
		{
			if(rtos_key.key_ok[6])
				{
					rtos_key.key_ok[6] = 0;
					xQueueSend(key_queueHandle, &(rtos_key.key_value[6]), 10);
				}
			rtos_key.press_time[6] = 0;
		}
	
}

unsigned char deal_key_value(unsigned key_value)
{
	switch(key_value)
  		{
  			case(KEY_1_TRIGGER):
				//LED_5_TOG;
				break;
			case(KEY_2_TRIGGER):
				//LED_5_TOG;
				break;
			case(KEY_3_TRIGGER):
				//LED_5_TOG;
				break;
			case(KEY_4_TRIGGER):
				//LED_5_TOG;
				break;
			case(KEY_5_TRIGGER):
				//LED_5_TOG;
				break;
			case(KEY_6_TRIGGER):

				break;
			case(KEY_7_TRIGGER):

				break;
			case(KEY_8_TRIGGER):

				break;
			case(KEY_9_TRIGGER):
				//LED_5_TOG;
				break;
			case(KEY_10_TRIGGER):
				//LED_5_TOG;
				break;

			case(KEY_1_LONG_TRIGGER):
				spk_echo(1,200);
				break;

			case(KEY_2_LONG_TRIGGER):
				break;

			case(KEY_3_LONG_TRIGGER):
				break;

			case(KEY_4_LONG_TRIGGER):
				break;

			case(KEY_5_LONG_TRIGGER):
				spk_echo(1,80);
				break;

			case(KEY_6_LONG_TRIGGER):
				break;

			case(KEY_7_LONG_TRIGGER):
				break;

			case(KEY_8_LONG_TRIGGER):
				break;

			case(KEY_9_LONG_TRIGGER):
				break;

			case(KEY_10_LONG_TRIGGER):
				break;

			case(KEY_1_LONG_LONG_TRIGGER):
				spk_echo(2,80);
				break;
			
			case(KEY_2_LONG_LONG_TRIGGER):
				break;
			
			case(KEY_3_LONG_LONG_TRIGGER):
				break;
			
			case(KEY_4_LONG_LONG_TRIGGER):
				break;
			
			case(KEY_5_LONG_LONG_TRIGGER):
				spk_echo(2,200);
				break;

			case(KEY_6_LONG_LONG_TRIGGER):
				break;

			case(KEY_7_LONG_LONG_TRIGGER):
				break;

			case(KEY_8_LONG_LONG_TRIGGER):
				break;

			case(KEY_9_LONG_LONG_TRIGGER):
				break;

			case(KEY_10_LONG_LONG_TRIGGER):
				break;
				


				
  			case(key1_press):
				test();
				break;

			case(key1_long_press):
				
				break;

			case(key1_long_long_press):
								
				LED_1_TOG;

				break;
				
			case(key2_press):
				
				break;

			case(key2_long_press):
				
				LED_1_ON;
				break;
				
			case(key3_press):
				
				break;

			case(key3_long_press):
				
				LED_1_ON;
			
				break;
				
			case(key4_press):
				
				break;

			case(key4_long_press):
				
				break;
				
			case(key5_press):
				
				break;

			case(key5_long_press):
				
				break;

			case(key5_long_long_press):
				
				
				LED_1_TOG;

      
				break;
				
			case(key6_press):
				
				break;

			case(key6_long_press):
				
				break;

			case(key6_long_long_press):
				
				break;

			case(key7_press):
				
				break;

			case(key7_long_press):
				
				break;

			case(key7_long_long_press):
				
				break;
			
  		}
	return 1;
}




