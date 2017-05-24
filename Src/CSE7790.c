#include "CSE7790.h"
#include <math.h>

extern SPI_HandleTypeDef hspi1;

S_Cse7790_Info cse7790_info = {
	.SYSCON.data_length=2,.SYSCON.address=0X00,
	.EMUCON.data_length=2,.EMUCON.address=0X01,
	.HFconst.data_length=2,.HFconst.address=0X02,
	.Pstart.data_length=2,.Pstart.address=0X03,
	
	.PAGain.data_length=2,.PAGain.address=0X05,
	.PBGain.data_length=2,.PBGain.address=0X06,
	.PhaseA.data_length=1,.PhaseA.address=0X07,
	.PhaseB.data_length=1,.PhaseB.address=0X08,
	
	.PAOS.data_length=2,.PAOS.address=0X0A,
	.PBOS.data_length=2,.PBOS.address=0X0B,
	
	.RmsIAOS.data_length=2,.RmsIAOS.address=0X0E,
	.RmsIBOS.data_length=2,.RmsIBOS.address=0X0F,
	.IBGain.data_length=2,.IBGain.address=0X10,
	.PSGain.data_length=2,.PSGain.address=0X11,	
	.PSOS.data_length=2,.PSOS.address=0X12,
	.SELCON.data_length=1,.SELCON.address=0X18,
	
	.PFCnt_p.data_length=2,.PFCnt_p.address=0X1E,	
	.PFCnt_N.data_length=2,.PFCnt_N.address=0X1F,
	.PFCnt.data_length=2,.PFCnt.address=0X20,
	
	.RmsIA.data_length=3,.RmsIA.address=0X22,
	.RmsIB.data_length=3,.RmsIB.address=0X23,
	.RmsU.data_length=3,.RmsU.address=0X24,
	.Ufreq.data_length=2,.Ufreq.address=0X25,
	.PowerA.data_length=4,.PowerA.address=0X26,
	.PowerB.data_length=4,.PowerB.address=0X27,
	
	.E_P.data_length=3,.E_P.address=0X29,
	.E_P2.data_length=3,.E_P2.address=0X2A,
	
	.EMUStatus.data_length=3,.EMUStatus.address=0X2D,
	.PowerFactor.data_length=3,.PowerFactor.address=0X2E,
	.PowerS.data_length=4,.PowerS.address=0X30,
	.EP_P.data_length=3,.EP_P.address=0X34,
	.EP_N.data_length=3,.EP_N.address=0X35,
	.InstanIA.data_length=3,.InstanIA.address=0X38,
	.InstanIB.data_length=3,.InstanIB.address=0X39,
	.InstanU.data_length=3,.InstanU.address=0X3A,
	
	.IE.data_length=1,.IE.address=0X40,
	.IF.data_length=1,.IF.address=0X41,
	.RIF.data_length=1,.RIF.address=0X42,
	
	.SysStatus.data_length=1,.SysStatus.address=0X43,
	.Rdata.data_length=4,.Rdata.address=0X44,
	.Wdata.data_length=2,.Wdata.address=0X45,
	.DeviceID.data_length=3,.DeviceID.address=0X7F,
	
	.define_reg_num=(offsetof(S_Cse7790_Info,define_reg_num))/(sizeof(S_Cse7790_Reg)),
};


unsigned int set_bit(unsigned int source,unsigned int bit_value)
{
	return (source | bit_value);
}
unsigned int clear_bit(unsigned int source,unsigned int bit_value)
{
	return (source & (~bit_value));
}




unsigned int read_cse7790(unsigned char address,unsigned char data_length)
{
	ENABLE_CSE7790;
	unsigned int read_data = 0;
	unsigned char tmp_data = 0;
	unsigned char tmp_address = address;
	unsigned char loopx = data_length;
	
	HAL_SPI_Transmit(&hspi1, &tmp_address,1, 0XFF);
	while(loopx --)
		{
			HAL_SPI_Receive( &hspi1, &tmp_data, 1, 0XFF);
			read_data |= tmp_data;
			if(loopx > 0)
				{
					read_data <<= 8;
				}
		}
	DISABLE_CSE7790;
	return read_data;
}

void write_cse7790(unsigned char address,unsigned int value,unsigned char data_length)
{
	unsigned char loopx = data_length;
	unsigned char send_data = 0;
	unsigned char tmp_address = address;
	if(address != 0XEA)
		{
			tmp_address = address + 0X80;
		}
	ENABLE_CSE7790;	
	HAL_SPI_Transmit(&hspi1, &tmp_address,1, 0XFF);
	while(loopx--)
		{
			send_data = (value>>(loopx*8))&0XFF;
			HAL_SPI_Receive( &hspi1, &send_data, 1, 0XFF);
		}
	DISABLE_CSE7790;
}

void enable_cse7790_write(void)
{
	write_cse7790(0XEA,0XE5,1);
}

void disable_cse7790_write(void)
{
	write_cse7790(0XEA,0XDC,1);
}


void enable_cse7790_channelA(void)
{
	write_cse7790(0XEA,0X5A,1);
}

void enable_cse7790_channelB(void)
{
	write_cse7790(0XEA,0XA5,1);
}

void reset_cse7790(void)
{
	write_cse7790(0XEA,0X96,1);
}



/********************************

函数封装

*********************************/

/********************************

设置cse7790寄存器的值
参数 1 cse7790寄存器
参数 2 要设置的值
*********************************/
void set_cse7790_reg_value(P_S_Cse7790_Reg reg,unsigned int value)
{
	enable_cse7790_write();
	write_cse7790(reg->address,value,reg->data_length);
	disable_cse7790_write();
}




/********************************

读取cse7790寄存器的值
参数  cse7790寄存器
*********************************/
void get_cse7790_reg_value(P_S_Cse7790_Reg reg)
{
	reg->data_value = read_cse7790(reg->address,reg->data_length);
}



/********************************

将cse7790 的全部数据读出
*********************************/
void get_cse7790_info(P_S_Cse7790_Info cse7790)
{
	unsigned loopx = cse7790->define_reg_num;
	P_S_Cse7790_Reg read_reg = NULL;
	read_reg = (P_S_Cse7790_Reg)cse7790;
	while(loopx--)
		{
			get_cse7790_reg_value(read_reg++);
		}
}



/********************************************

校准部分函数

********************************************/

void enable_PFout_EP(void)//开启PF脉冲输出和有功功率累加寄存器
{
	get_cse7790_reg_value(&cse7790_info.EMUCON);
	cse7790_info.EMUCON.data_value = set_bit(cse7790_info.EMUCON.data_value,BIT_0);
	set_cse7790_reg_value(&cse7790_info.EMUCON,cse7790_info.EMUCON.data_value);
}

void disable_PFout_EP(void)//关闭PF脉冲输出和有功功率累加寄存器
{
	get_cse7790_reg_value(&cse7790_info.EMUCON);
	cse7790_info.EMUCON.data_value = clear_bit(cse7790_info.EMUCON.data_value,BIT_0);
	set_cse7790_reg_value(&cse7790_info.EMUCON,cse7790_info.EMUCON.data_value);
}

void set_cse7790_HFconst(unsigned int hfconst)//设置HFconst寄存器的值
{
	set_cse7790_reg_value(&cse7790_info.HFconst,hfconst);
}

void set_Pstart_value(unsigned int value)//设置潜动寄存器
{
	set_cse7790_reg_value(&cse7790_info.Pstart,value);
}



void adjust_PAGain(float PAGin_err)
{
	float tmp = 0.0;
	int PAGain = 0;
	tmp = -PAGin_err/(1.0+PAGin_err);
	if(tmp < 0)
		{
			PAGain =(int)(tmp*32768 + 65536);
		}
	else
		{
			PAGain = (int)(tmp*32768);
		}
	set_cse7790_reg_value(&(cse7790_info.PAGain),PAGain);
}


void adjust_PBGain(float PBGin_err)
{
	float tmp = 0.0;
	int PBGain = 0;
	tmp = -PBGin_err/(1.0+PBGin_err);
	if(tmp < 0)
		{
			PBGain =(int)(tmp*32768 + 65536);
		}
	else
		{
			PBGain = (int)(tmp*32768);
		}
	set_cse7790_reg_value(&(cse7790_info.PBGain),PBGain);
}

void adjust_PAOS(float PAGin_err,float PAOS_err)
{
	int PAOS;
	unsigned char loop16 = 16;
	unsigned int sum_powerA = 0;
	while(loop16 --)
		{
			get_cse7790_reg_value(&(cse7790_info.PowerA));
			sum_powerA +=cse7790_info.PowerA.data_value;
			HAL_Delay(400);
		}
	sum_powerA = 0XF5AB7*16;
	PAOS = (int)(-((sum_powerA/16)*PAOS_err)/(1+PAGin_err));
	PAOS &= 0XFFFF;
	set_cse7790_reg_value(&cse7790_info.PAOS,PAOS);
}

void adjust_PBOS(float PBGin_err,float PBOS_err)
{
	int PBOS;
	unsigned char loop16 = 16;
	unsigned int sum_powerB = 0;
	while(loop16 --)
		{
			get_cse7790_reg_value(&(cse7790_info.PowerB));
			sum_powerB +=cse7790_info.PowerB.data_value;
			HAL_Delay(400);
		}
	sum_powerB = 0XF5AB7*16;
	PBOS = (int)(-((sum_powerB/16)*PBOS_err)/(1+PBGin_err));
	PBOS &= 0XFFFF;
	set_cse7790_reg_value(&cse7790_info.PBOS,PBOS);
}

void adjust_PhaseA(float PhaseA_err,unsigned char Phase_sel)
{
	unsigned char PhaseA = 0;
	unsigned char signal = 1;
	
	float tmp = 0.0;
	tmp = -(PhaseA_err)/1.7320508;
	PhaseA = (unsigned char)((DEGREES(asin(tmp)))/0.02);

	if(PhaseA_err > 0.0)
		{
			signal = 0;
		}
	
	if(Phase_sel == 0)
		{
			if(signal == 0)
				{
					PhaseA = (256 + PhaseA -96);
				}
			if(signal == 1)
				{
					PhaseA = (256 - PhaseA -96);
				}
		}
	if(Phase_sel == 1)
		{
			if(signal == 0)
				{
					PhaseA = (256 + PhaseA);
				}
			if(signal == 1)
				{
					PhaseA = (256 - PhaseA);
				}
		}
	
	set_cse7790_reg_value(&cse7790_info.PhaseA,PhaseA);	
}

void adjust_PhaseB(float PhaseB_err,unsigned char Phase_sel)
{
	unsigned char PhaseB = 0;
	unsigned char signal = 1;
	
	float tmp = 0.0;
	tmp = -(PhaseB_err)/1.7320508;
	PhaseB = (unsigned char)((DEGREES(asin(tmp)))/0.02);

	if(PhaseB_err > 0.0)
		{
			signal = 0;
		}
	
	if(Phase_sel == 0)
		{
			if(signal == 0)
				{
					PhaseB = (256 + PhaseB -96);
				}
			if(signal == 1)
				{
					PhaseB = (256 - PhaseB -96);
				}
		}
	if(Phase_sel == 1)
		{
			if(signal == 0)
				{
					PhaseB = (256 + PhaseB);
				}
			if(signal == 1)
				{
					PhaseB = (256 - PhaseB);
				}
		}
	
	set_cse7790_reg_value(&cse7790_info.PhaseB,PhaseB);	
}





void init_cse7790(void)
{
	set_cse7790_reg_value(&cse7790_info.SYSCON,0X02C4);//设置SYSCON寄存器0X02C4: 使能电流B通道 电流通道16倍增益电压通道2倍增益
}




