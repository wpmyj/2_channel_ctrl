#ifndef __CSE7790_H__
#define __CSE7790_H__
#include "include.h"


typedef struct{
	unsigned char address;
	unsigned char data_length;
	unsigned int data_value;
}S_Cse7790_Reg,*P_S_Cse7790_Reg;

typedef struct
{
	S_Cse7790_Reg SYSCON;
	S_Cse7790_Reg EMUCON;
	S_Cse7790_Reg HFconst;
	S_Cse7790_Reg Pstart;
	S_Cse7790_Reg PAGain;
	S_Cse7790_Reg PBGain;
	S_Cse7790_Reg PhaseA;
	S_Cse7790_Reg PhaseB;
	S_Cse7790_Reg PAOS;
	S_Cse7790_Reg PBOS;
	S_Cse7790_Reg RmsIAOS;
	S_Cse7790_Reg RmsIBOS;
	S_Cse7790_Reg IBGain;
	S_Cse7790_Reg PSGain;
	S_Cse7790_Reg PSOS;
	S_Cse7790_Reg SELCON;
	S_Cse7790_Reg PFCnt_p;
	S_Cse7790_Reg PFCnt_N;
	S_Cse7790_Reg PFCnt;
	S_Cse7790_Reg RmsIA;
	S_Cse7790_Reg RmsIB;
	S_Cse7790_Reg RmsU;
	S_Cse7790_Reg Ufreq;
	S_Cse7790_Reg PowerA;
	S_Cse7790_Reg PowerB;
	S_Cse7790_Reg E_P;
	S_Cse7790_Reg E_P2;
	S_Cse7790_Reg EMUStatus;
	S_Cse7790_Reg PowerFactor;
	S_Cse7790_Reg PowerS;
	S_Cse7790_Reg EP_P;
	S_Cse7790_Reg EP_N;
	S_Cse7790_Reg InstanIA;
	S_Cse7790_Reg InstanIB;
	S_Cse7790_Reg InstanU;
	S_Cse7790_Reg IE;
	S_Cse7790_Reg IF;
	S_Cse7790_Reg RIF;
	S_Cse7790_Reg SysStatus;
	S_Cse7790_Reg Rdata;
	S_Cse7790_Reg Wdata;
	S_Cse7790_Reg DeviceID;
	unsigned char define_reg_num;


	
}S_Cse7790_Info,*P_S_Cse7790_Info;
extern S_Cse7790_Info cse7790_info;

#define ENABLE_CSE7790	HAL_GPIO_WritePin(SPI1_CS_GPIO_Port,SPI1_CS_Pin,GPIO_PIN_RESET)
#define DISABLE_CSE7790	HAL_GPIO_WritePin(SPI1_CS_GPIO_Port,SPI1_CS_Pin,GPIO_PIN_SET)



unsigned int read_cse7790(unsigned char address,unsigned char data_length);
void write_cse7790(unsigned char address,unsigned int value,unsigned char data_length);
void enable_cse7790_write(void);
void disable_cse7790_write(void);
void enable_cse7790_channelA(void);
void enable_cse7790_channelB(void);
void reset_cse7790(void);



void set_cse7790_HFconst(unsigned int hfconst);

void get_cse7790_info(P_S_Cse7790_Info cse7790);
void get_cse7790_reg_value(P_S_Cse7790_Reg reg);

#endif

