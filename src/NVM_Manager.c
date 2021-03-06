/*=======================================================================================*
 * @file    source.c
 * @author  Damian Pala
 * @version 0.4
 * @date    XX-XX-20XX
 * @brief   This file contains all implementations for XXX module.
 *======================================================================================*/

/**
 * @addtogroup XXX Description
 * @{
 * @brief Module for... .
 */

/*======================================================================================*/
/*                       ####### PREPROCESSOR DIRECTIVES #######                        */
/*======================================================================================*/
/*-------------------------------- INCLUDE DIRECTIVES ----------------------------------*/
#include <stdint.h>
#include <stdbool.h>

#include "NVM_Manager.h"
#include "cmsis_device.h"
#include "stm32f0xx_flash.h"
#include "NVM_Driver.h"

/*----------------------------- LOCAL OBJECT-LIKE MACROS -------------------------------*/
#define WORD_SIZE                             4 ///< bytes
#define PAGE_SIZE                             1024 ///< bytes
#define START_ADDRESS                         0x0800F400
#define MEM_WORKSPACE                         3 ///< pages

#define MEM_ROKSPACE_IN_BYTES                 MEM_WORKSPACE * PAGE_SIZE
#define MAX_OBJECT_NUMBER                     1024 / (2 + 4 + 2) // ?????????????

#define ID_FIELD_SIZE                         11 ///< bits
#define COUNTER_FIELD_SIZE                    11 ///< bits
#define SIZE_FIELD_SIZE                       10 ///< bits
#define OBJ_DATA_SIZE                         32 ///< bits

// ID + COUNTER + SIZE = 11bit + 11bit + 10bit

#if (MEM_WORKSPACE < 2)
  #error Memory space should be at least 2 pages!!!
#endif

/*---------------------------- LOCAL FUNCTION-LIKE MACROS ------------------------------*/
#define GET_ID(objectDataWord)                ( objectDataWord >> (OBJ_DATA_SIZE - ID_FIELD_SIZE) )
#define GET_COUNTER(objectDataWord)           ( (objectDataWord >> (OBJ_DATA_SIZE - ID_FIELD_SIZE - COUNTER_FIELD_SIZE)) && 0x7FF )
#define GET_SIZE(objectDataWord)              (objectDataWord && 0x3FF)

/*======================================================================================*/
/*                      ####### LOCAL TYPE DECLARATIONS #######                         */
/*======================================================================================*/
/*-------------------------------- OTHER TYPEDEFS --------------------------------------*/

/*------------------------------------- ENUMS ------------------------------------------*/

/*------------------------------- STRUCT AND UNIONS ------------------------------------*/


/*======================================================================================*/
/*                         ####### OBJECT DEFINITIONS #######                           */
/*======================================================================================*/
/*--------------------------------- EXPORTED OBJECTS -----------------------------------*/

/*---------------------------------- LOCAL OBJECTS -------------------------------------*/
uint32_t UsedBytesInMemory = 0;

/*======================================================================================*/
/*                    ####### LOCAL FUNCTIONS PROTOTYPES #######                        */
/*======================================================================================*/

/*======================================================================================*/
/*                   ####### LOCAL FUNCTIONS DEFINITIONS #######                        */
/*======================================================================================*/

/*======================================================================================*/
/*                  ####### EXPORTED FUNCTIONS DEFINITIONS #######                      */
/*======================================================================================*/
void NVMM_Init(void)
{
  FLASH_Status status;
  uint32_t address = 0x0800FC00 + 4 * 2;

//  FlagStatus flashStatus = FLASH_GetPrefetchBufferStatus();

//  FLASH_Unlock();

  status = FLASH_ProgramWord(address, 0xABCD5544);

  uint32_t readVal = NVMD_ReadWord(address);

  FLASH_Lock();

  trace_printf("status: %u\n", status);
  trace_printf("readed value: %x\n", readVal);
}

void NVMM_Handler(void)
{

}

// TODO: implement algorithm for searching ids

/**
 * @}
 */
