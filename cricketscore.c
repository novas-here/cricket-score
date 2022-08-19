#include <at89c5131.h>
#include "lcd.h"
#include "serial.c"
#include <stdio.h>


void inc_ball(short *over_pointer,short *ball, unsigned char ch)
{
	*ball+=1;
	lcd_cmd(*over_pointer);
	lcd_write_char(ch);
	*over_pointer+=1;
}

void inc_over(short *over_pointer, short *over, unsigned char ch)
{
	*over+=1;
	lcd_cmd(*over_pointer);
	lcd_write_char(ch);
	*over_pointer=0xC0;
}

void end(void)
{
	lcd_cmd(0xC0);
	lcd_write_string("                ");
	lcd_cmd(0xC2);
	lcd_write_string("Innings Ends");
}

void reset(short *total_run,short *over,short *ball,short *wicket,short *over_pointer)
{
	*total_run=0;
	*over=0;
	*ball=0;
	*wicket=0;
	*over_pointer=0xC0;
}

void main(void)
{
	unsigned char ch=0;
	char str[16];
	short total_run=0;
	short over=0;
	short ball=0;
	short wicket=0;
	short over_pointer=0xC0;
	
	lcd_init();
	uart_init();
	
	sprintf(str, "%d/%d(%d.%d)", total_run,wicket,over,ball);
	lcd_cmd(0x80);
	lcd_write_string(str);
	
	while(1)
	{
		ch=receive_char();
		
		switch(ch)
		{
			case '1':
				total_run = total_run +1;
				if (over_pointer==0xC0)
				{
					lcd_cmd(over_pointer);
					lcd_write_string("                ");
				}
				if (ball<5)
				{
					inc_ball(&over_pointer,&ball,ch);
				}
				else
				{
					ball =0;
					if (over<19)
					{
						inc_over(&over_pointer,&over,ch);
					}
					else
					{
						over++;
						sprintf(str, "%d/%d(%d.%d)", total_run,wicket,over,ball);
						lcd_cmd(0x80);
						lcd_write_string("                ");
						lcd_cmd(0x80);
						lcd_write_string(str);
						end();
						msdelay(5000);
						reset(&total_run,&over,&ball,&wicket,&over_pointer);
						lcd_cmd(0xC0);
						lcd_write_string("                ");
					}
				}
				break;
				
				
			case '2':
				total_run = total_run +2;
				if (over_pointer==0xC0)
				{
					lcd_cmd(over_pointer);
					lcd_write_string("                ");
				}
				if (ball<5)
				{
					inc_ball(&over_pointer,&ball,ch);
				}
				else
				{
					ball =0;
					if (over<19)
					{
						inc_over(&over_pointer,&over,ch);
					}
					else
					{
						over++;
						sprintf(str, "%d/%d(%d.%d)", total_run,wicket,over,ball);
						lcd_cmd(0x80);
						lcd_write_string("                ");
						lcd_cmd(0x80);
						lcd_write_string(str);
						end();
						msdelay(5000);
						reset(&total_run,&over,&ball,&wicket,&over_pointer);
						lcd_cmd(0xC0);
						lcd_write_string("                ");
					}
				}
				break;
				
			case '3':
				total_run = total_run +3;
				if (over_pointer==0xC0)
				{
					lcd_cmd(over_pointer);
					lcd_write_string("                ");
				}
				if (ball<5)
				{
					inc_ball(&over_pointer,&ball,ch);
				}
				else
				{
					ball =0;
					if (over<19)
					{
						inc_over(&over_pointer,&over,ch);
					}
					else
					{
						over++;
						sprintf(str, "%d/%d(%d.%d)", total_run,wicket,over,ball);
						lcd_cmd(0x80);
						lcd_write_string("                ");
						lcd_cmd(0x80);
						lcd_write_string(str);
						end();
						msdelay(5000);
						reset(&total_run,&over,&ball,&wicket,&over_pointer);
						lcd_cmd(0xC0);
						lcd_write_string("                ");
					}
				}
				break;
			
			case '4':
				total_run = total_run +4;
				if (over_pointer==0xC0)
				{
					lcd_cmd(over_pointer);
					lcd_write_string("                ");
				}
				if (ball<5)
				{
					inc_ball(&over_pointer,&ball,ch);
				}
				else
				{
					ball =0;
					if (over<19)
					{
						inc_over(&over_pointer,&over,ch);
					}
					else
					{
						over++;
						sprintf(str, "%d/%d(%d.%d)", total_run,wicket,over,ball);
						lcd_cmd(0x80);
						lcd_write_string("                ");
						lcd_cmd(0x80);
						lcd_write_string(str);
						end();
						msdelay(5000);
						reset(&total_run,&over,&ball,&wicket,&over_pointer);
						lcd_cmd(0xC0);
						lcd_write_string("                ");
					}
				}
				break;
				
			case '5':
				total_run = total_run +5;
				if (over_pointer==0xC0)
				{
					lcd_cmd(over_pointer);
					lcd_write_string("                ");
				}
				if (ball<5)
				{
					inc_ball(&over_pointer,&ball,ch);
				}
				else
				{
					ball =0;
					if (over<19)
					{
						inc_over(&over_pointer,&over,ch);
					}
					else
					{
						over++;
						sprintf(str, "%d/%d(%d.%d)", total_run,wicket,over,ball);
						lcd_cmd(0x80);
						lcd_write_string("                ");
						lcd_cmd(0x80);
						lcd_write_string(str);
						end();
						msdelay(5000);
						reset(&total_run,&over,&ball,&wicket,&over_pointer);
						lcd_cmd(0xC0);
						lcd_write_string("                ");
					}
				}
				break;
			
			case '6':
				total_run = total_run +6;
				if (over_pointer==0xC0)
				{
					lcd_cmd(over_pointer);
					lcd_write_string("                ");
				}
				if (ball<5)
				{
					inc_ball(&over_pointer,&ball,ch);
				}
				else
				{
					ball =0;
					if (over<19)
					{
						inc_over(&over_pointer,&over,ch);
					}
					else
					{
						over++;
						sprintf(str, "%d/%d(%d.%d)", total_run,wicket,over,ball);
						lcd_cmd(0x80);
						lcd_write_string("                ");
						lcd_cmd(0x80);
						lcd_write_string(str);
						end();
						msdelay(5000);
						reset(&total_run,&over,&ball,&wicket,&over_pointer);
						lcd_cmd(0xC0);
						lcd_write_string("                ");
					}
				}
				break;
			
			case 'w':
				if (over_pointer==0xC0)
				{
					lcd_cmd(over_pointer);
					lcd_write_string("                ");
				}
				wicket=wicket+1;
				if (ball<5)
				{
					ball+=1;
					lcd_cmd(over_pointer);
					lcd_write_string("W");
					over_pointer+=1;
				}
				else
				{
					ball = 0;
					if (over<19)
					{
						over+=1;
						lcd_cmd(over_pointer);
						lcd_write_string("W");
						over_pointer=0xC0;
					}
					else
					{
						over++;
						sprintf(str, "%d/%d(%d.%d)", total_run,wicket,over,ball);
						lcd_cmd(0x80);
						lcd_write_string("                ");
						lcd_cmd(0x80);
						lcd_write_string(str);
						end();
						msdelay(5000);
						reset(&total_run,&over,&ball,&wicket,&over_pointer);
						lcd_cmd(0xC0);
						lcd_write_string("                ");
					}
				}
				if (wicket ==10)
				{
					sprintf(str, "%d/%d(%d.%d)", total_run,wicket,over,ball);
					lcd_cmd(0x80);
					lcd_write_string("                ");
					lcd_cmd(0x80);
					lcd_write_string(str);
					end();
					msdelay(5000);
					reset(&total_run,&over,&ball,&wicket,&over_pointer);
					lcd_cmd(0x01);
				}
				break;
				
			case 'e':
				if (over_pointer==0xC0)
				{
					lcd_cmd(over_pointer);
					lcd_write_string("                ");
				}
				total_run += 1;
				lcd_cmd(over_pointer);
				lcd_write_string("E");
				over_pointer++;
				break;
			
			case 'n':
				if (over_pointer==0xC0)
				{
					lcd_cmd(over_pointer);
					lcd_write_string("                ");
				}
				total_run +=1;
				lcd_cmd(over_pointer);
				lcd_write_string("N");
				over_pointer++;
				break;
			
			case '.':
				if (over_pointer==0xC0)
				{
					lcd_cmd(over_pointer);
					lcd_write_string("                ");
				}
				if (ball<5)
				{
					inc_ball(&over_pointer,&ball,ch);
				}
				else
				{
					ball = 0;
					if (over<19)
					{
						inc_over(&over_pointer,&over,ch);
					}
					else
					{
						over++;
						sprintf(str, "%d/%d(%d.%d)", total_run,wicket,over,ball);
						lcd_cmd(0x80);
						lcd_write_string("                ");
						lcd_cmd(0x80);
						lcd_write_string(str);
						end();
						msdelay(5000);
						reset(&total_run,&over,&ball,&wicket,&over_pointer);
						lcd_cmd(0xC0);
						lcd_write_string("                ");
					}
				}
				break;				
		}
		sprintf(str, "%d/%d(%d.%d)", total_run,wicket,over,ball);
		lcd_cmd(0x80);
		lcd_write_string("                ");
		lcd_cmd(0x80);
		lcd_write_string(str);
	}
}