#include "stm32f4xx.h"
#include "misc.h"
#include "LCD.h"
#include "dcmi_OV7670.h"
#include <stdio.h>

DAC_InitTypeDef  DAC_InitStructure;
void Delay(__IO uint32_t nCount);



int main(void)
{
  
LCD_Initializtion();
LCD_Clear(Blue2);
GUI_Text(100,100,"Mode Marche Arriere",Blue2,White);

Delay(0xFFFFFF);
LCD_Clear(White);

OV7670_IDTypeDef OV7670ID;
DCMI_OV7670_Init();
DCMI_OV7670_ReadID(&OV7670ID);
DMA_Cmd(DMA2_Stream1, ENABLE);//Activation du Dma Pour transmmettre les données Du DCMI(Caméra) au FSMC(Ecran Lcd)
DCMI_Cmd(ENABLE);

DCMI_CaptureCmd(ENABLE); //Activation du camera   

while (1)
{ 

}

}


//Declaration de la Fonction du Delay************************************************************************
void Delay(__IO uint32_t nCount)
{
  while(nCount--)
  {
  }
}

  
  
 
