#ifndef __CSE7790_H__
#define __CSE7790_H__
#include "include.h"

#define PI 3.141592653f
#define DEGREES(X)	((X/PI)*180)
#define RADIAN(x) 	((x/180)*PI)

#define BIT_0	0X01
#define BIT_1	0X02
#define BIT_2	0X04
#define BIT_3	0X08
#define BIT_4	0X10
#define BIT_5	0X20
#define BIT_6	0X40
#define BIT_7	0X80
#define BIT_8	0X100
#define BIT_9	0X200
#define BIT_10	0X400
#define BIT_11	0X800
#define BIT_12	0X1000
#define BIT_13	0X2000
#define BIT_14	0X4000
#define BIT_15	0X8000
#define BIT_16	0X10000
#define BIT_17	0X20000
#define BIT_18	0X40000
#define BIT_19	0X80000
#define BIT_20	0X100000
#define BIT_21	0X200000
#define BIT_22	0X400000
#define BIT_23	0X800000
#define BIT_24	0X1000000
#define BIT_25	0X2000000
#define BIT_26	0X4000000
#define BIT_27	0X8000000
#define BIT_28	0X10000000
#define BIT_29	0X20000000
#define BIT_30	0X40000000
#define BIT_31	0X80000000


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
	S_Cse7790_Reg PFCnt_P;
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

typedef struct
{
	unsigned char PhaseA;
	unsigned char PhaseB;
	unsigned char SELCON;
	
	unsigned short HFconst;
	unsigned short PAGain;
	unsigned short PBGain;
	unsigned short PSGain;
	unsigned short PAOS;
	unsigned short PBOS;
	unsigned short PSOS;

	unsigned short RmsIAOS;
	unsigned short RmsIBOS;
	
	unsigned short IBGain;

	unsigned short Pstart;

	unsigned short SYSCON;
	unsigned short EMUCON;

	unsigned short PFCnt_P;
	unsigned short PFCnt_N;
	unsigned short PFCnt;
	
}S_Adjust_Info,*P_S_Adjust_Info;
extern S_Adjust_Info adjust_info;






#define ENABLE_CSE7790	HAL_GPIO_WritePin(SPI1_CS_GPIO_Port,SPI1_CS_Pin,GPIO_PIN_RESET)
#define DISABLE_CSE7790	HAL_GPIO_WritePin(SPI1_CS_GPIO_Port,SPI1_CS_Pin,GPIO_PIN_SET)

unsigned int set_bit(unsigned int source,unsigned int bit_value);
unsigned int clear_bit(unsigned int source,unsigned int bit_value);

void init_cse7790(P_S_Adjust_Info info);

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


void adjust_PAGain(float PAGin_err);//校准A通道功率增益
void adjust_PBGain(float PBGin_err);//校准B通道功率增益
void adjust_PAOS(float PAGin_err,float PAOS_err);//校准A通道offset小功率校准
void adjust_PBOS(float PBGin_err,float PBOS_err);//校准B通道offset小功率校准
void adjust_PhaseA(float PhaseA_err,unsigned char Phase_sel);//校准A通道相位
void adjust_PhaseB(float PhaseB_err,unsigned char Phase_sel);//校准B通道相位
void adjust_RmsIAOS(void);

#endif

