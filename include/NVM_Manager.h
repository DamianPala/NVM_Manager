/*=======================================================================================*
 * @file    header.h
 * @author  Damian Pala
 * @version 0.4
 * @date    XX-XX-20XX
 * @brief   Header file for XXX module
 *
 *          This file contains API of XXX module
 *======================================================================================*/
/*----------------------- DEFINE TO PREVENT RECURSIVE INCLUSION ------------------------*/
#ifndef NVM_MANAGER_H_
#define NVM_MANAGER_H_

/**
 * @defgroup XXX Description
 * @{
 * @brief Module for... .
 */

/*======================================================================================*/
/*                       ####### PREPROCESSOR DIRECTIVES #######                        */
/*======================================================================================*/
/*-------------------------------- INCLUDE DIRECTIVES ----------------------------------*/

/*----------------------------- LOCAL OBJECT-LIKE MACROS -------------------------------*/

/*---------------------------- LOCAL FUNCTION-LIKE MACROS ------------------------------*/

/*======================================================================================*/
/*                     ####### EXPORTED TYPE DECLARATIONS #######                       */
/*======================================================================================*/
/*-------------------------------- OTHER TYPEDEFS --------------------------------------*/
typedef uint16_t NVM_ObjectId;

/*------------------------------------- ENUMS ------------------------------------------*/
typedef enum NVMM_Status_Tag
{
  NVMM_BUSY           = 1,
  NVMM_READ_ERROR,
  NVMM_WRITE_ERROR,
  NVMM_COMPLETE,
  NVMM_TIMEOUT
} NVMM_Status_T;

/*------------------------------- STRUCT AND UNIONS ------------------------------------*/
typedef struct NVMM_Object_Tag
{
  uint32_t address;
  uint32_t id;
  uint16_t dataSize;
  uint32_t crc;
} NVMM_Object_T;

/*======================================================================================*/
/*                    ####### EXPORTED OBJECT DECLARATIONS #######                      */
/*======================================================================================*/

/*======================================================================================*/
/*                   ####### EXPORTED FUNCTIONS PROTOTYPES #######                      */
/*======================================================================================*/
void NVMM_Init(void);
void NVMM_Handler(void);
NVM_ObjectId NVMM_WriteObject(uint32_t *inputDataAddress);
NVMM_Status_T NVMM_ReadObject(NVM_ObjectId id, uint32_t *outputDataAdress);
uint16_t NVMM_GetObjectSize(NVM_ObjectId id);
void NVMM_ErrorCheck(void);

/*======================================================================================*/
/*                          ####### INLINE FUNCTIONS #######                            */
/*======================================================================================*/
static inline uint32_t NVMM_ReadWord(uint32_t address)
{
  return *((uint32_t *)address);
}


/**
 * @}
 */

#endif /* NVM_MANAGER_H_ */
