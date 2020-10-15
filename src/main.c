/**
******************************************************************************
* @file     main.c
* @author   AE team
* @version  V1.0.1
* @date     23/11/2018
* @brief    
******************************************************************************
* @copy
*
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
* TIME. AS A RESULT, MindMotion SHALL NOT BE HELD LIABLE FOR ANY
* DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
* FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
* CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*
* <h2><center>&copy; COPYRIGHT 2018 MindMotion</center></h2>
*/
#include "HAL_device.h"
#include "HAL_conf.h"
#include "stdio.h"

extern u32 SystemCoreClock;
void delay_init(void);
void delay_ms(__IO uint32_t nTime);
void TimingDelay_Decrement(void);
void LED_Init(void);

static __IO uint32_t TimingDelay;

#define LED1_Port  GPIOA
#define LED1_Pin   GPIO_Pin_4
#define LED1_ON()  GPIO_ResetBits(LED1_Port,LED1_Pin)	 
#define LED1_OFF()  GPIO_SetBits(LED1_Port,LED1_Pin)	 
#define LED1_TOGGLE()  (GPIO_ReadOutputDataBit(LED1_Port,LED1_Pin))?(GPIO_ResetBits(LED1_Port,LED1_Pin)):(GPIO_SetBits(LED1_Port,LED1_Pin))	 





int main(void)    
{
    delay_init();
    LED_Init();
    while(1)             
    {
        LED1_TOGGLE();
        delay_ms(1000);
    }
}


void delay_init(void)
{
    if (SysTick_Config(SystemCoreClock / 1000))
    { 
        /* Capture error */ 
        while (1);
    }
    /* Configure the SysTick handler priority */
    NVIC_SetPriority(SysTick_IRQn, 0x0);//SysTick�ж����ȼ�����
}


void SysTick_Handler(void)
{
    TimingDelay_Decrement();
}


void TimingDelay_Decrement(void)
{
    if (TimingDelay != 0x00)
    { 
        TimingDelay--;
    }
}


void delay_ms(__IO uint32_t nTime)
{ 
    TimingDelay = nTime;
    
    while(TimingDelay != 0);
}

/*******************************************************************************
* @name   : GPIO_Clock_Set
* @brief  : RCC clock set
* @param  : Portx , State
* @retval : void
*******************************************************************************/
void GPIO_Clock_Set(GPIO_TypeDef* GPIOx, FunctionalState NewState)
{

    if(GPIOx == GPIOA)
    {
        RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, NewState);                         //GPIO clock starts  
    }
    if(GPIOx == GPIOB)
    {
        RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, NewState);                         //GPIO clock starts  
    }
    if(GPIOx == GPIOC)
    {
        RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, NewState);                         //GPIO clock starts  
    }
    if(GPIOx == GPIOD)
    {
        RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD, NewState);                         //GPIO clock starts  
    }
}

void LED_Init(void)
{
    
    GPIO_InitTypeDef  GPIO_InitStructure;
   
    GPIO_Clock_Set(LED1_Port, ENABLE);  //����GPIOAʱ��
    
    GPIO_InitStructure.GPIO_Pin  =  LED1_Pin;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(LED1_Port, &GPIO_InitStructure);

    
    LED1_OFF();

}

/**
* @}
*/

/**
* @}
*/

/**
* @}
*/

/*-------------------------(C) COPYRIGHT 2018 MindMotion ----------------------*/

