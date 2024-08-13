/*
 * stm32f1xx.h
 *
 *  Created on: Aug 12, 2024
 *      Author: Darkknaitt
 */

#ifndef INC_STM32F1XX_H_
#define INC_STM32F1XX_H_

#include <stdint.h>


#define __vol volatile


#define FLASH_BASEADDR		0x80000000UL 	// Info obtenida del manual de referencia
#define SRAM1_BASEADDR		0x20000000UL 	// Info obtenida del manual de referencia
#define SRAM				SRAM1_BASEADDR 	// Solo tiene una memoria SRAM
#define ROM_BASEADDR		0x1FFFF000UL 	// Info obtenida del manual de referencia


//////////////////////////////////////////////
/* Direccion de memoria base de los buses */
#define PERIPH_BASEADDR		0x40000000UL
#define APB1_BASEADDR		PERIPH_BASEADDR
#define APB2_BASEADDR		0x40010000UL
#define AHB_BASEADDR		0x40018000UL 	// En la nucleo solo se encuentra un bus AHB


//////////////////////////////////////////////
/* Direccion de memoria base de los perifericos PUERTOS*/

#define GPIOA_BASEADDR		(APB2_BASEADDR + 0x0800)
#define GPIOB_BASEADDR		(GPIOA_BASEADDR + 0x0400)
#define GPIOC_BASEADDR		(GPIOB_BASEADDR + 0x0400)
#define GPIOD_BASEADDR		(GPIOC_BASEADDR + 0x0400)
#define GPIOE_BASEADDR		(GPIOD_BASEADDR + 0x0400)
#define GPIOF_BASEADDR		(GPIOE_BASEADDR + 0x0400)



//////////////////////////////////////////////
/* Direccion de memoria base de los I2C*/
#define I2C1_BASEADDR 		(APB1_BASEADDR + 0x5400)
#define I2C2_BASEADDR 		(I2C1_BASEADDR + 0x0400)


//////////////////////////////////////////////
/* Direccion de memoria base de los SPI*/
#define SPI1_BASEADDR		(APB2_BASEADDR + 0x3000)
#define SPI2_BASEADDR		(APB1_BASEADDR + 0x3800)
#define SPI3_BASEADDR		(APB1_BASEADDR + 0x3C00)


//////////////////////////////////////////////
/* Direccion de memoria base de los USART y UART y EXTI*/
#define USART1_BASEADDR		(APB2_BASEADDR + 0x3800)
#define USART2_BASEADDR		(APB1_BASEADDR + 0x4400)
#define USART3_BASEADDR		(APB1_BASEADDR + 0x4800)
#define UART4_BASEADDR		(APB1_BASEADDR + 0x4C00)
#define UART5_BASEADDR		(APB1_BASEADDR + 0x5000)
#define EXTI_BASEADDR		(APB2_BASEADDR + 0x0400)

//////////////////////////////////////////////
/* Direccion de memoria base del reloj RCC*/
#define RCC_BASEADDR		0x40021000UL


/* Estructura de los registros para los puertos GPIO*/

typedef struct
{
	__vol uint32_t MODERCNF0TO7;  	// Offset = 0x00	// En las placas nucleo se define el modo y la velocidad para pines 0 a 7
	__vol uint32_t MODERCNF8TO15;	// Offset = 0x04	// En las placas nucleo se define el modo y la velocidad para pines 8 a 15
	__vol uint32_t IDR;				// Offset = 0x08
	__vol uint32_t ODR;				// Offset = 0x0C
	__vol uint32_t BSRR;			// Offset = 0x10
	__vol uint32_t BRR;				// Offset = 0x14
	__vol uint32_t LCKR;			// Offset = 0x18
}
GPIO_RegDef_t;

/* Estructura para el clock*/

typedef struct
{
	__vol uint32_t	RCC_CR;			// Offset = 0x00
	__vol uint32_t	RCC_CFGR;		// Offset = 0x04
	__vol uint32_t	RCC_CIR;		// Offset = 0x08
	__vol uint32_t	RCC_APB2RSTR;	// Offset = 0x0C
	__vol uint32_t	RCC_APB1RSTR;	// Offset = 0x10
	__vol uint32_t	RCC_AHBENR;		// Offset = 0x14
	__vol uint32_t	RCC_APB2ENR;	// Offset = 0x18
	__vol uint32_t	RCC_APB1ENR;	// Offset = 0x1C
	__vol uint32_t	RCC_BDCR;		// Offset = 0x20
	__vol uint32_t	RCC_CSR;		// Offset = 0x24
}
Rcc_RegDef_t;


/* Definicion de macros para los puertos GPIO*/

#define GPIOA 				((GPIO_RegDef_t*) GPIOA_BASEADDR)
#define GPIOB				((GPIO_RegDef_t*) GPIOB_BASEADDR)
#define GPIOC 				((GPIO_RegDef_t*) GPIOC_BASEADDR)
#define GPIOD				((GPIO_RegDef_t*) GPIOD_BASEADDR)
#define GPIOE				((GPIO_RegDef_t*) GPIOE_BASEADDR)
#define GPIOF				((GPIO_RegDef_t*) GPIOF_BASEADDR)

/* Definicion de macros para el reloj */
#define RCC					((Rcc_RegDef_t*)rcc)


//////////////////////////////////////////////
/* Definicion de macro para activar el reloj de los puertos GPIOx*/
#define IOA_PCLK_EN()		(RCC->RCC_APB2ENR |= (1<<2))
#define IOB_PCLK_EN()		(RCC->RCC_APB2ENR |= (1<<3))
#define IOC_PCLK_EN()		(RCC->RCC_APB2ENR |= (1<<4))
#define IOD_PCLK_EN()		(RCC->RCC_APB2ENR |= (1<<5))
#define IO3_PCLK_EN()		(RCC->RCC_APB2ENR |= (1<<6))
#define IOF_PCLK_EN()		(RCC->RCC_APB2ENR |= (1<<7))

//////////////////////////////////////////////
/* Definicion de macro para activar el reloj para el uso de comunicacion I2C*/
#define I2C1_PCLK_EN()		(RCC->RCC_APB1ENR |= (1<<21))
#define I2C2_PCLK_EN()		(RCC->RCC_APB1ENR |= (1<<22))

//////////////////////////////////////////////
/* Definicion de macro para activar el reloj para el uso de comunicacion SPI*/
#define SPI1_PCLK_EN()		(RCC->RCC_APB2ENR |= (1<<12))
#define SPI2_PCLK_EN()		(RCC->RCC_APB1ENR |= (1<<14))
#define SPI3_PCLK_EN()		(RCC->RCC_APB1ENR |= (1<<15))


//////////////////////////////////////////////
/* Definicion de macro para activar el reloj para el uso de comunicacion USART/UART*/
#define USART1_PCLK_EN()	(RCC->RCC_APB2ENR |= (1<<14))
#define USART2_PCLK_EN()	(RCC->RCC_APB1ENR |= (1<<17))
#define USART3_PCLK_EN()	(RCC->RCC_APB1ENR |= (1<<18))
#define UART4_PCLK_EN()		(RCC->RCC_APB1ENR |= (1<<19))
#define UART5_PCLK_EN()		(RCC->RCC_APB1ENR |= (1<<20))
/* cabe mencinoar que el reloj para EXTI esta siempre activado */


/*-----------------  SECCION DE DESACTIVACION --------------------------*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Definicion de macro para desactivar el reloj de los puertos GPIOx*/
#define IOA_PCLK_DI()		(RCC->RCC_APB2ENR &=~ (1<<2))
#define IOB_PCLK_DI()		(RCC->RCC_APB2ENR &=~ (1<<3))
#define IOC_PCLK_DI()		(RCC->RCC_APB2ENR &=~ (1<<4))
#define IOD_PCLK_DI()		(RCC->RCC_APB2ENR &=~ (1<<5))
#define IO3_PCLK_DI()		(RCC->RCC_APB2ENR &=~ (1<<6))
#define IOF_PCLK_DI()		(RCC->RCC_APB2ENR &=~ (1<<7))

//////////////////////////////////////////////
/* Definicion de macro para desactivar el reloj para el uso de comunicacion I2C*/
#define I2C1_PCLK_DI()		(RCC->RCC_APB1ENR &=~ (1<<21))
#define I2C2_PCLK_DI()		(RCC->RCC_APB1ENR &=~ (1<<22))

//////////////////////////////////////////////
/* Definicion de macro para desactivar el reloj para el uso de comunicacion SPI*/
#define SPI1_PCLK_DI()		(RCC->RCC_APB2ENR &=~ (1<<12))
#define SPI2_PCLK_DI()		(RCC->RCC_APB1ENR &=~ (1<<14))
#define SPI3_PCLK_DI()		(RCC->RCC_APB1ENR &=~ (1<<15))


//////////////////////////////////////////////
/* Definicion de macro para desactivar el reloj para el uso de comunicacion USART/UART*/
#define USART1_PCLK_DI()	(RCC->RCC_APB2ENR &=~ (1<<14))
#define USART2_PCLK_DI()	(RCC->RCC_APB1ENR &=~ (1<<17))
#define USART3_PCLK_DI()	(RCC->RCC_APB1ENR &=~ (1<<18))
#define UART4_PCLK_DI()		(RCC->RCC_APB1ENR &=~ (1<<19))
#define UART5_PCLK_DI()		(RCC->RCC_APB1ENR &=~ (1<<20))






#endif /* INC_STM32F1XX_H_ */
