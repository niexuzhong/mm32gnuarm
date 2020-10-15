/**************************************************************************//**
 * @file     ARMCM0.h
 * @brief    CMSIS Core Peripheral Access Layer Header File for
 *           ARMCM0 Device
 * @version  V5.3.1
 * @date     09. July 2018
 ******************************************************************************/
/*
 * Copyright (c) 2009-2018 Arm Limited. All rights reserved.
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

#ifndef ARMCM0_H
#define ARMCM0_H

#ifdef __cplusplus
extern "C" {
#endif


/* -------------------------  Interrupt Number Definition  ------------------------ */

typedef enum IRQn
{
/* -------------------  Processor Exceptions Numbers  ----------------------------- */
  NonMaskableInt_IRQn           = -14,     /*  2 Non Maskable Interrupt */
  HardFault_IRQn                = -13,     /*  3 HardFault Interrupt */
  MemManage_Handlern             = -12,
  BusFault_Handlern              = -11,
  UsageFault_Handlern            = -10,

  SVCall_IRQn                   =  -5,     /* 11 SV Call Interrupt */
  DebugMon_Handlern              =  -4,
  PendSV_IRQn                   =  -2,     /* 14 Pend SV Interrupt */
  SysTick_IRQn                  =  -1,     /* 15 System Tick Interrupt */

/* -------------------  Processor Interrupt Numbers  ------------------------------ */
   WWDG_IRQn                     =  0,          // Window Watchdog
   PVD_IRQn                      =  1,                 // PVD through EXTI Line detect
   PWM_IRQn                      =  2,                     // RTC through EXTI Line & Tamper  ////change
   FLASH_IRQn                    =  3,                   // FLASH
   RCC_IRQn                      =  4,                     // RCC & CRS
   EXTI0_1_IRQn                  =  5,                 // EXTI Line 0 and 1
   EXTI2_3_IRQn                  =  6,                 // EXTI Line 2 and 3
   EXTI4_15_IRQn                 =  7,                // EXTI Line 4 to 15
   HWDIV_IRQn                    =  8,                   // HWDIV
   DMA_Channel1_IRQn             =  9,            // DMA Channel 1
   DMA_Channel2_3_IRQn           =  10,          // DMA Channel 2 and Channel 3
   DMA_Channel4_5_IRQn           =  11,          // DMA Channel 4 and Channel 5
   ADC_COMP_IRQn                 =  12,               // ADC and COMPARE				////change
   TIM1_BRK_UP_TRG_COM_IRQn      =  13,     // TIM1 Break, Update, Trigger and Commutation
   TIM1_CC_IRQn                  =  14,                 // TIM1 Capture Compare
   TIM2_IRQn                     =  15,                    // TIM2
   TIM3_IRQn                     =  16,                    // TIM3

   TIM14_IRQn                    =  17,                   // TIM14
  
   TIM16_IRQn                    =  18,                   // TIM16
   TIM17_IRQn                    =  19,                   // TIM17
   I2C_IRQn                      =  20,                     // I2C
                  
  /* Interrupts 10 .. 31 are left out */
} IRQn_Type;


/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* -------  Start of section using anonymous unions and disabling warnings  ------- */
#if   defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* --------  Configuration of Core Peripherals  ----------------------------------- */
#define __CM0_REV                 0x0000U   /* Core revision r0p0 */
#define __MPU_PRESENT             0U        /* no MPU present */
#define __VTOR_PRESENT            0U        /* no VTOR present */
#define __NVIC_PRIO_BITS          2U        /* Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig    0U        /* Set to 1 if different SysTick Config is used */

#include "core_cm0.h"                       /* Processor and core peripherals */
#include "system_ARMCM0.h"                  /* System Header */


/* --------  End of section using anonymous unions and disabling warnings  -------- */
#if   defined (__CC_ARM)
  #pragma pop
#elif defined (__ICCARM__)
  /* leave anonymous unions enabled */
#elif (defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
  #pragma clang diagnostic pop
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning restore
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


#ifdef __cplusplus
}
#endif

#endif  /* ARMCM0_H */
