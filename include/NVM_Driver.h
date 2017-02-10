/*=======================================================================================*
 * @file    header.h
 * @author  Damian Pala
 * @version 0.5
 * @date    XX-XX-20XX
 * @brief   Header file for XXX module
 *
 *          This file contains API of XXX module
 *======================================================================================*/
/*----------------------- DEFINE TO PREVENT RECURSIVE INCLUSION ------------------------*/
#ifndef NVM_DRIVER_H_
#define NVM_DRIVER_H_

/**
 * @addtogroup XXX Description
 * @{
 * @brief Module for... .
 */

/*======================================================================================*/
/*                       ####### PREPROCESSOR DIRECTIVES #######                        */
/*======================================================================================*/
/*-------------------------------- INCLUDE DIRECTIVES ----------------------------------*/
#include "cmsis_device.h"
#include "stm32f0xx_flash.h"

/*----------------------------- LOCAL OBJECT-LIKE MACROS -------------------------------*/

/*---------------------------- LOCAL FUNCTION-LIKE MACROS ------------------------------*/

/*======================================================================================*/
/*                     ####### EXPORTED TYPE DECLARATIONS #######                       */
/*======================================================================================*/
/*-------------------------------- OTHER TYPEDEFS --------------------------------------*/

/*------------------------------------- ENUMS ------------------------------------------*/
typedef enum NVMD_Status_Tag
{
  NVMD_BUSY = 1,
  NVMD_ERROR_WRP,
  NVMD_ERROR_PROGRAM,
  NVMD_COMPLETE,
  NVMD_TIMEOUT
} NVMD_Status_T;

/*------------------------------- STRUCT AND UNIONS ------------------------------------*/

/*======================================================================================*/
/*                    ####### EXPORTED OBJECT DECLARATIONS #######                      */
/*======================================================================================*/

/*======================================================================================*/
/*                   ####### EXPORTED FUNCTIONS PROTOTYPES #######                      */
/*======================================================================================*/

/*======================================================================================*/
/*                          ####### INLINE FUNCTIONS #######                            */
/*======================================================================================*/
static inline void NVMD_MemUnlock(void)
{
  FLASH_Unlock();
}

static inline void NVMD_MemLock(void)
{
  FLASH_Lock();
}

static inline NVMD_Status_T NVMD_ReadWord(uint32_t address)
{
  return *((uint32_t *)address);
}

static inline NVMD_Status_T NVMD_WriteWord(uint32_t address, uint32_t data)
{
  return FLASH_ProgramWord(address, data);
}

static inline NVMD_Status_T NVMD_ErasePage(uint32_t pageAddress)
{
  return FLASH_ErasePage(pageAddress);
}

/**
 * @}
 */

#endif /* NVM_DRIVER_H_ */
