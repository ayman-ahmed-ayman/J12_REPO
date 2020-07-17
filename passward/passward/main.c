/*
 * passward.c
 *
 * Created: 7/17/2020 1:08:19 AM
 * Author : ahmad
 */ 


#include "Temp_Sensor.h"
#include "LCD.h"
#include "KeyPad.h"
#define  F_CPU   16000000
#include <util/delay.h>

void write_password(void);
int main()
{
	
	uint16 Temp = 0;
	uint8 str[]="ENTER PASSWORD";
	
	LCD_Init();
	KeyPad_Init();
	TempSensor_Init();
	LCD_Clear();
	LCD_WriteString(str);
	write_password();
	
	 
		
	while (1)
	{


		TempSensor_Read(&Temp);
		
		LCD_Clear();
		
		LCD_WriteInteger(Temp);
		
		_delay_ms(500);
	}
	
	return 0;
}
 write_password()
 {   uint8 N_1=0;
	 uint8 N_2=0;
	 uint8 N_3=0;
	 uint8 N_4=0;
	 uint8 str1[]="OK SYS START";
	 uint8 str2[]="NO TRY AGAIN";
     uint8 caoution[]="SYS LOCKED";
	 uint8 i=0;
	 
	 
	 
	  for (i=0 ; i<4 ; i++)
	  
 {
		   
	 while (1)
	 
	 {
		 N_1=KeyPad_GetValue();
		 if (N_1) 
		 {
			 LCD_Clear();
			 LCD_WriteChar('*');
			 break ;			 
		 }
		 
	 }
	 
	 
	 
	 while (1)
	 {
		 N_2=KeyPad_GetValue();
		 if (N_2)
		 {
			 
			 
			 LCD_WriteChar('*');
			 break ;
		 }
		
		
	 }
	 while (1)
	 {
		 N_3=KeyPad_GetValue();
		 if (N_3)
		 {
			 LCD_WriteChar('*');
			 break ;
			 
		 }
	 }
	 while (1)
	 {
		 N_4=KeyPad_GetValue();
		 if (N_4)
		 {
			 LCD_WriteChar('*');
			 break ;
			 
		 }
	 }
	 

	 if (N_1=='4'&&  N_2=='3' && N_3=='2' && N_4=='1')
	 {
		 LCD_WriteString(str1);
		 return;
	 }
	 else
	 { LCD_Clear();
		 LCD_WriteString(str2);
		
		 if (i==3)
		 {LCD_Clear();
			 LCD_WriteString(caoution);
			 _delay_ms(5000);
			 
		 }
		 else ;
		 
	 }
  }
	  LCD_OFF();
	  while(1)
	  {
		  
	  };
}
 


