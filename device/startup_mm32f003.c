/******************************************************************************
 * @file     startup_ARMCM0.c
 * @brief    CMSIS-Core(M) Device Startup File for a Cortex-M0 Device
 * @version  V2.0.3
 * @date     31. March 2020
 ******************************************************************************/
/*
 * Copyright (c) 2009-2020 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define ARMCM0
#if defined (ARMCM0)
  #include "ARMCM0.h"
#else
  #error device not specified!
#endif

/*----------------------------------------------------------------------------
  External References
 *----------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;

extern __NO_RETURN void __PROGRAM_START(void);

/*----------------------------------------------------------------------------
  Internal References
 *----------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler  (void);
            void Default_Handler(void);

/*----------------------------------------------------------------------------
  Exception / Interrupt Handler
 *----------------------------------------------------------------------------*/
/* Exceptions */
void NMI_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler      (void) __attribute__ ((weak));
void SVC_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler         (void) __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler     (void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));

void DebugMon_Handler     (void) __attribute__ ((weak, alias("Default_Handler")));
void WWDG_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void PVD_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void PWM_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void FLASH_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void RCC_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI0_1_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI2_3_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI4_15_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void HWDIV_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_Channel1_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_Channel2_3_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_Channel4_5_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC_COMP_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_BRK_UP_TRG_COM_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM2_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM3_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM14_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM16_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM17_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void SPI_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void UART2_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined ( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

extern const VECTOR_TABLE_Type __VECTOR_TABLE[48];
       const VECTOR_TABLE_Type __VECTOR_TABLE[48] __VECTOR_TABLE_ATTRIBUTE = {
  (VECTOR_TABLE_Type)(&__INITIAL_SP),       /*     Initial Stack Pointer */
  Reset_Handler,                            /*     Reset Handler */
  NMI_Handler,                        /* -14 NMI Handler */
  HardFault_Handler,                  /* -13 Hard Fault Handler */
  MemManage_Handler,                  /*     MPU Fault */
  BusFault_Handler,                  /*     Bus Fault */
  UsageFault_Handler,                 /*     usage fault */
  0,                                  /*     Reserved */
  0,                                  /*     Reserved */
  0,                                  /*     Reserved */
  0,                                  /*     Reserved */
  SVC_Handler,                        /*  -5 SVCall Handler */
  DebugMon_Handler,                                  /*     Reserved */
  0,                                 /*     Reserved */
  PendSV_Handler,                     /*  -2 PendSV Handler */
  SysTick_Handler,                    /*  -1 SysTick Handler */

                /* Interrupts */
   WWDG_IRQHandler,                // Window Watchdog
   PVD_IRQHandler,                 // PVD through EXTI Line detect
   PWM_IRQHandler,                 // RTC through EXTI Line & Tamper  ////change
   FLASH_IRQHandler,               // FLASH
   RCC_IRQHandler,                 // RCC & CRS
   EXTI0_1_IRQHandler,             // EXTI Line 0 and 1
   EXTI2_3_IRQHandler,             // EXTI Line 2 and 3
   EXTI4_15_IRQHandler ,           // EXTI Line 4 to 15
   HWDIV_IRQHandler,               // HWDIV
   DMA_Channel1_IRQHandler ,       // DMA Channel 1
   DMA_Channel2_3_IRQHandler ,     // DMA Channel 2 and Channel 3
   DMA_Channel4_5_IRQHandler  ,    // DMA Channel 4 and Channel 5
   ADC_COMP_IRQHandler  ,          // ADC and COMPARE				////change
   TIM1_BRK_UP_TRG_COM_IRQHandler, // TIM1 Break, Update, Trigger and Commutation
   TIM1_CC_IRQHandler ,            // TIM1 Capture Compare
   TIM2_IRQHandler ,               // TIM2
   TIM3_IRQHandler,                // TIM3
   0,                              // Reserved
   0 ,                             // Reserved
   TIM14_IRQHandler ,              // TIM14
   0   ,                           // Reserved
   TIM16_IRQHandler,               // TIM16
   TIM17_IRQHandler,               // TIM17
   I2C_IRQHandler ,                // I2C
                                            /* Interrupts 10..31 are left out */
};

#if defined ( __GNUC__ )
#pragma GCC diagnostic pop
#endif

/*----------------------------------------------------------------------------
  Reset Handler called on controller reset
 *----------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void)
{
  SystemInit();                             /* CMSIS System Initialization */
  __PROGRAM_START();                        /* Enter PreMain (C library entry point) */
}


#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wmissing-noreturn"
#endif

/*----------------------------------------------------------------------------
  Hard Fault Handler
 *----------------------------------------------------------------------------*/
void HardFault_Handler(void)
{
  while(1);
}

/*----------------------------------------------------------------------------
  Default Handler for Exceptions / Interrupts
 *----------------------------------------------------------------------------*/
void Default_Handler(void)
{
  while(1);
}

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic pop
#endif

