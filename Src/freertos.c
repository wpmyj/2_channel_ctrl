/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

/* USER CODE BEGIN Includes */     
#include "include.h"
/* USER CODE END Includes */

/* Variables -----------------------------------------------------------------*/
osThreadId systemHandle;
osThreadId read_keyHandle;
osThreadId deal_keyHandle;
osThreadId serial_serverHandle;
osMessageQId key_queueHandle;
osMessageQId serial_queueHandle;

/* USER CODE BEGIN Variables */

/* USER CODE END Variables */

/* Function prototypes -------------------------------------------------------*/
void sys_task(void const * argument);
void read_key_task(void const * argument);
void deal_key_task(void const * argument);
void serial_task(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

/* Hook prototypes */
void vApplicationIdleHook(void);
void vApplicationTickHook(void);

/* USER CODE BEGIN 2 */
void vApplicationIdleHook(void)
{}
void vApplicationTickHook(void)
{}
/* USER CODE END 2 */

/* USER CODE BEGIN 3 */

/* USER CODE END 3 */

/* Init FreeRTOS */

void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
       
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the thread(s) */
  /* definition and creation of system */
  osThreadDef(system, sys_task, osPriorityNormal, 0, 300);
  systemHandle = osThreadCreate(osThread(system), NULL);

  /* definition and creation of read_key */
  osThreadDef(read_key, read_key_task, osPriorityNormal, 0, 128);
  read_keyHandle = osThreadCreate(osThread(read_key), NULL);

  /* definition and creation of deal_key */
  osThreadDef(deal_key, deal_key_task, osPriorityHigh, 0, 300);
  deal_keyHandle = osThreadCreate(osThread(deal_key), NULL);

  /* definition and creation of serial_server */
  osThreadDef(serial_server, serial_task, osPriorityRealtime, 0, 800);
  serial_serverHandle = osThreadCreate(osThread(serial_server), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* Create the queue(s) */
  /* definition and creation of key_queue */
  osMessageQDef(key_queue, 8, uint8_t);
  key_queueHandle = osMessageCreate(osMessageQ(key_queue), NULL);

  /* definition and creation of serial_queue */
  osMessageQDef(serial_queue, 5, uint8_t);
  serial_queueHandle = osMessageCreate(osMessageQ(serial_queue), NULL);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
}

/* sys_task function */
void sys_task(void const * argument)
{

  /* USER CODE BEGIN sys_task */
  /* Infinite loop */
  for(;;)
  {
	LED_1_TOG;
	LED_2_TOG;
	LED_5_TOG;
	LED_6_TOG;
	osDelay(300);
  }
  /* USER CODE END sys_task */
}

/* read_key_task function */
void read_key_task(void const * argument)
{
  /* USER CODE BEGIN read_key_task */
  /* Infinite loop */
  for(;;)
  {
	read_key();
	osDelay(40);
  }
  /* USER CODE END read_key_task */
}

/* deal_key_task function */
void deal_key_task(void const * argument)
{
  /* USER CODE BEGIN deal_key_task */
  unsigned char recv_key_value;
  /* Infinite loop */
  for(;;)
  {
	xQueueReceive(key_queueHandle, &recv_key_value, portMAX_DELAY);
	deal_key_value(recv_key_value);
  }
  /* USER CODE END deal_key_task */
}

/* serial_task function */
void serial_task(void const * argument)
{
  /* USER CODE BEGIN serial_task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END serial_task */
}

/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
