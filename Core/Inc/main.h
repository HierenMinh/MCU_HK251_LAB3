/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define tsst_Pin GPIO_PIN_0
#define tsst_GPIO_Port GPIOA
#define RED_WAY_1_Pin GPIO_PIN_2
#define RED_WAY_1_GPIO_Port GPIOA
#define GREEN_WAY_1_Pin GPIO_PIN_3
#define GREEN_WAY_1_GPIO_Port GPIOA
#define AMBER_WAY_1_Pin GPIO_PIN_4
#define AMBER_WAY_1_GPIO_Port GPIOA
#define TEST_LED_Pin GPIO_PIN_5
#define TEST_LED_GPIO_Port GPIOA
#define BTN1_Pin GPIO_PIN_0
#define BTN1_GPIO_Port GPIOB
#define BTN2_Pin GPIO_PIN_1
#define BTN2_GPIO_Port GPIOB
#define BTN3_Pin GPIO_PIN_2
#define BTN3_GPIO_Port GPIOB
#define EN2_Pin GPIO_PIN_10
#define EN2_GPIO_Port GPIOB
#define EN3_Pin GPIO_PIN_11
#define EN3_GPIO_Port GPIOB
#define SEG3_WAY1_Pin GPIO_PIN_12
#define SEG3_WAY1_GPIO_Port GPIOB
#define SEG4_WAY1_Pin GPIO_PIN_13
#define SEG4_WAY1_GPIO_Port GPIOB
#define SEG5_WAY1_Pin GPIO_PIN_14
#define SEG5_WAY1_GPIO_Port GPIOB
#define SEG6_WAY1_Pin GPIO_PIN_15
#define SEG6_WAY1_GPIO_Port GPIOB
#define RED_WAY_2_Pin GPIO_PIN_8
#define RED_WAY_2_GPIO_Port GPIOA
#define GREEN_WAY_2_Pin GPIO_PIN_9
#define GREEN_WAY_2_GPIO_Port GPIOA
#define AMBER_WAY_2_Pin GPIO_PIN_10
#define AMBER_WAY_2_GPIO_Port GPIOA
#define SEG0_WAY2_Pin GPIO_PIN_11
#define SEG0_WAY2_GPIO_Port GPIOA
#define SEG1_WAY2_Pin GPIO_PIN_12
#define SEG1_WAY2_GPIO_Port GPIOA
#define SEG2_WAY2_Pin GPIO_PIN_13
#define SEG2_WAY2_GPIO_Port GPIOA
#define SEG3_WAY2_Pin GPIO_PIN_14
#define SEG3_WAY2_GPIO_Port GPIOA
#define SEG4_WAY2_Pin GPIO_PIN_15
#define SEG4_WAY2_GPIO_Port GPIOA
#define SEG0_WAY1_Pin GPIO_PIN_3
#define SEG0_WAY1_GPIO_Port GPIOB
#define SEG1_WAY1_Pin GPIO_PIN_4
#define SEG1_WAY1_GPIO_Port GPIOB
#define SEG2_WAY1_Pin GPIO_PIN_5
#define SEG2_WAY1_GPIO_Port GPIOB
#define SEG5_WAY2_Pin GPIO_PIN_6
#define SEG5_WAY2_GPIO_Port GPIOB
#define SEG6_WAY2_Pin GPIO_PIN_7
#define SEG6_WAY2_GPIO_Port GPIOB
#define EN0_Pin GPIO_PIN_8
#define EN0_GPIO_Port GPIOB
#define EN1_Pin GPIO_PIN_9
#define EN1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
