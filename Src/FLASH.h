#ifndef __FLASH_H__
#define __FLASH_H__
#include "Include.h"

typedef enum
{ 
  WRITE_FLASH = 0,
  READ_FLASH,
  UP_DATA
}FLASH_OPERATION;



//#define ADDR_FLASH_PAGE_100   ((uint32_t)0x08019000) /* Base @ of Page 100, 1 Kbytes */
//#define ADDR_FLASH_PAGE_101   ((uint32_t)0x08019400) /* Base @ of Page 101, 1 Kbytes */
//#define ADDR_FLASH_PAGE_102   ((uint32_t)0x08019800) /* Base @ of Page 102, 1 Kbytes */
//#define ADDR_FLASH_PAGE_103   ((uint32_t)0x08019C00) /* Base @ of Page 103, 1 Kbytes */
//#define ADDR_FLASH_PAGE_104   ((uint32_t)0x0801A000) /* Base @ of Page 104, 1 Kbytes */
//#define ADDR_FLASH_PAGE_105   ((uint32_t)0x0801A400) /* Base @ of Page 105, 1 Kbytes */
//#define ADDR_FLASH_PAGE_106   ((uint32_t)0x0801A800) /* Base @ of Page 106, 1 Kbytes */
//#define ADDR_FLASH_PAGE_107   ((uint32_t)0x0801AC00) /* Base @ of Page 107, 1 Kbytes */
//#define ADDR_FLASH_PAGE_108   ((uint32_t)0x0801B000) /* Base @ of Page 108, 1 Kbytes */
//#define ADDR_FLASH_PAGE_109   ((uint32_t)0x0801B400) /* Base @ of Page 109, 1 Kbytes */
//#define ADDR_FLASH_PAGE_110   ((uint32_t)0x0801B800) /* Base @ of Page 110, 1 Kbytes */
//#define ADDR_FLASH_PAGE_111   ((uint32_t)0x0801BC00) /* Base @ of Page 111, 1 Kbytes */
//#define ADDR_FLASH_PAGE_112   ((uint32_t)0x0801C000) /* Base @ of Page 112, 1 Kbytes */
//#define ADDR_FLASH_PAGE_113   ((uint32_t)0x0801C400) /* Base @ of Page 113, 1 Kbytes */
//#define ADDR_FLASH_PAGE_114   ((uint32_t)0x0801C800) /* Base @ of Page 114, 1 Kbytes */
//#define ADDR_FLASH_PAGE_115   ((uint32_t)0x0801CC00) /* Base @ of Page 115, 1 Kbytes */
#define ADDR_FLASH_PAGE_116   ((uint32_t)0x0803A000) /* Base @ of Page 116, 1 Kbytes */
#define ADDR_FLASH_PAGE_117   ((uint32_t)0x0803A800) /* Base @ of Page 117, 1 Kbytes */
#define ADDR_FLASH_PAGE_118   ((uint32_t)0x0803B000) /* Base @ of Page 118, 1 Kbytes */
#define ADDR_FLASH_PAGE_119   ((uint32_t)0x0803B800) /* Base @ of Page 119, 1 Kbytes */
#define ADDR_FLASH_PAGE_120   ((uint32_t)0x0803C000) /* Base @ of Page 120, 1 Kbytes */
#define ADDR_FLASH_PAGE_121   ((uint32_t)0x0803C800) /* Base @ of Page 121, 1 Kbytes */
#define ADDR_FLASH_PAGE_122   ((uint32_t)0x0803D000) /* Base @ of Page 122, 1 Kbytes */
#define ADDR_FLASH_PAGE_123   ((uint32_t)0x0803D800) /* Base @ of Page 123, 1 Kbytes */
#define ADDR_FLASH_PAGE_124   ((uint32_t)0x0803E000) /* Base @ of Page 124, 1 Kbytes */
#define ADDR_FLASH_PAGE_125   ((uint32_t)0x0803E800) /* Base @ of Page 125, 1 Kbytes */
#define ADDR_FLASH_PAGE_126   ((uint32_t)0x0803F000) /* Base @ of Page 126, 1 Kbytes */
#define ADDR_FLASH_PAGE_127   ((uint32_t)0x0803F800) /* Base @ of Page 127, 1 Kbytes */


#define ADDR_FLASH_PAGE_244   ((uint32_t)0x0807A000) /* Base @ of Page 116, 1 Kbytes */
#define ADDR_FLASH_PAGE_245   ((uint32_t)0x0807A800) /* Base @ of Page 117, 1 Kbytes */
#define ADDR_FLASH_PAGE_246   ((uint32_t)0x0807B000) /* Base @ of Page 118, 1 Kbytes */
#define ADDR_FLASH_PAGE_247   ((uint32_t)0x0807B800) /* Base @ of Page 119, 1 Kbytes */
#define ADDR_FLASH_PAGE_248   ((uint32_t)0x0807C000) /* Base @ of Page 120, 1 Kbytes */
#define ADDR_FLASH_PAGE_249   ((uint32_t)0x0807C800) /* Base @ of Page 121, 1 Kbytes */
#define ADDR_FLASH_PAGE_250   ((uint32_t)0x0807D000) /* Base @ of Page 122, 1 Kbytes */
#define ADDR_FLASH_PAGE_251  ((uint32_t)0x0807D800) /* Base @ of Page 123, 1 Kbytes */
#define ADDR_FLASH_PAGE_252  ((uint32_t)0x0807E000) /* Base @ of Page 124, 1 Kbytes */
#define ADDR_FLASH_PAGE_253   ((uint32_t)0x0807E800) /* Base @ of Page 125, 1 Kbytes */
#define ADDR_FLASH_PAGE_254   ((uint32_t)0x0807F000) /* Base @ of Page 126, 1 Kbytes */
#define ADDR_FLASH_PAGE_255   ((uint32_t)0x0807F800) /* Base @ of Page 127, 1 Kbytes */

//#define STM300_BASE_ADDRESS ADDR_FLASH_PAGE_127
//#define SWITCH_BASE_ADDRESS ADDR_FLASH_PAGE_126
//#define SENSOR_BASE_ADDRESS ADDR_FLASH_PAGE_125
//#define WINDOWS_BASE_ADDRESS ADDR_FLASH_PAGE_125
//#define PIR_BASE_ADDRESS ADDR_FLASH_PAGE_124

#define PRIORITY_SAVE_ADDR 		((app_base_addr)+(31*FLASH_PAGE_SIZE))
#define SWITCH_BASE_ADDRESS 	((app_base_addr)+(30*FLASH_PAGE_SIZE))
#define WINDOWS_BASE_ADDRESS 	((app_base_addr)+(29*FLASH_PAGE_SIZE))
#define PIR_BASE_ADDRESS 		((app_base_addr)+(28*FLASH_PAGE_SIZE))
#define APP_INFOR_SAVE_ADDR 	((app_base_addr)+(27*FLASH_PAGE_SIZE))


#define RTC_SAVE_ADDR			((app_base_addr)+(26*FLASH_PAGE_SIZE))



unsigned char write_flash(unsigned address,char* data,unsigned short len);
unsigned char read_flash(unsigned address,char* data,unsigned short len);
void erase_flash(unsigned int address);
void init_learn_space(void);
void check_learn_space(P_S_Save_Learned_Device_Data check_space);
void memcopy(char* from_addr,char* to_addr,unsigned short length);
void flash_r_w_from_queue(unsigned int message_addr);
void flash_operat(FLASH_OPERATION OPEART,unsigned char* addr,unsigned char page_num,unsigned short offset,unsigned short length,unsigned char owner,flash_message* flash_messages);

#endif

