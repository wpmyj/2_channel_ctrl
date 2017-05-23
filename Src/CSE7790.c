#include "CSE7790.h"

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

void get_cse7790_reg_value(P_S_Cse7790_Reg reg)
{
	reg->data_value = read_cse7790(reg->address,reg->data_length);
}

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

void set_cse7790_HFconst(unsigned int hfconst)
{
	enable_cse7790_write();
	write_cse7790(0X02,hfconst,2);
	disable_cse7790_write();
}
