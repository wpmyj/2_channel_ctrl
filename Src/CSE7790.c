#include "CSE7790.h"

extern SPI_HandleTypeDef hspi1;


unsigned int read_cse7790(unsigned char address,unsigned char data_length)
{
	ENABLE_CSE7790;
	HAL_Delay(1);
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
	HAL_Delay(1);
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
	HAL_Delay(1);
	HAL_SPI_Transmit(&hspi1, &tmp_address,1, 0XFF);
	while(loopx--)
		{
			send_data = (value>>(loopx*8))&0XFF;
			HAL_SPI_Receive( &hspi1, &send_data, 1, 0XFF);
		}
	HAL_Delay(1);
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

/*void spi1_write_byte(unsigned char data)
{
	unsigned tmp_data = data;
	unsigned char loop8 = 8;
	ENABLE_CSE7790;
	while(loop8 --)
		{
			SPI1_CLK_0;
			SPI1_CLK_0;
			if(tmp_data & 0X80)
				{
					SPI1_MOSI_1;	
					SPI1_MOSI_1;	
				}
			else
				{
					SPI1_MOSI_0;
					SPI1_MOSI_0;
				}
			SPI1_CLK_1;
			SPI1_CLK_1;
			tmp_data <<= 1;
		}
	SPI1_CLK_0;
	SPI1_MOSI_0;
	DISABLE_CSE7790;
}

unsigned char spi1_read_byte(void)
{
	unsigned tmp_data = 0;
	unsigned char loop8 = 8;
	ENABLE_CSE7790;
	while(loop8 --)
		{
			SPI1_CLK_0;
			SPI1_CLK_0;
			if(GET_SPI1_MISO)
				{
					tmp_data |= 1;					
				}
			else
				{
					
				}
			SPI1_CLK_1;
			SPI1_CLK_1;
			tmp_data <<= 1;
		}
	SPI1_CLK_0;

	DISABLE_CSE7790;
	return tmp_data;
}*/

/*
unsigned int read_cse7790(unsigned char address,unsigned char data_length)
{
	ENABLE_CSE7790;
	HAL_Delay(10);
	unsigned short read_data = 0;
	unsigned char tmp_data = 0;
	unsigned char tmp_address = address;
	unsigned char loopx = data_length;
	
	spi1_write_byte(address);
	while(loopx --)
		{		
			tmp_data = spi1_read_byte();
			read_data |= tmp_data;
			if(loopx > 0)
				{
					read_data <<= 8;
				}
		}
	HAL_Delay(1);
	DISABLE_CSE7790;
	return read_data;
}*/

