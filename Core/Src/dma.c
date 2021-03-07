/**
  ******************************************************************************
  * @file    dma.c
  * @brief   This file provides code for the configuration
  *          of all the requested memory to memory DMA transfers.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "dma.h"

/* USER CODE BEGIN 0 */
#include "main.h"
/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure DMA                                                              */
/*----------------------------------------------------------------------------*/

/* USER CODE BEGIN 1 */
void dma_init(void)
{
	   LL_DMA_ClearFlag_TC4(DMA1);
	    LL_DMA_ClearFlag_TE4(DMA1);
	LL_DMA_ConfigAddresses(DMA1, LL_DMA_STREAM_4, (uint32_t)mainBuff, LL_SPI_DMA_GetRegAddr(SPI2), LL_DMA_GetDataTransferDirection(DMA1, LL_DMA_STREAM_4));
	LL_DMA_SetDataLength(DMA1, LL_DMA_STREAM_4, B_SIZE);
	LL_DMA_EnableIT_TC(DMA1, LL_DMA_STREAM_4);
	LL_DMA_EnableIT_TE(DMA1, LL_DMA_STREAM_4);
	LL_SPI_EnableDMAReq_TX(SPI2);

	//LL_SPI_Enable(SPI2);
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_10);
	LL_DMA_EnableStream(DMA1, LL_DMA_STREAM_4);	//wysli dane z buffora
	//to w zasadzie poeinno juz dzialac i 1 raz wyslac po resecie uC
}
/* USER CODE END 1 */

/**
  * Enable DMA controller clock
  */
void MX_DMA_Init(void)
{

  /* Init with LL driver */
  /* DMA controller clock enable */
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA1);

  /* DMA interrupt init */
  /* DMA1_Stream4_IRQn interrupt configuration */
  NVIC_SetPriority(DMA1_Stream4_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(DMA1_Stream4_IRQn);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
