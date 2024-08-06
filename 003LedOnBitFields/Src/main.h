/*
 * main.h
 *
 *  Created on: Aug 5, 2024
 *      Author: Darkknaitt
 */


#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>

typedef struct
{
	uint32_t afio_en	:1;
	uint32_t reserved1	:1;
	uint32_t gpioa_en	:1;
	uint32_t gpiob_en	:1;
	uint32_t gpioc_en	:1;
	uint32_t gpiod_en	:1;
	uint32_t gpioe_en	:1;
	uint32_t gpiof_en	:1;
	uint32_t gpiog_en	:1;
	uint32_t adc1_en 	:1;
	uint32_t adc2_en 	:1;
	uint32_t tim1_en 	:1;
	uint32_t spi1_en 	:1;
	uint32_t tim8_en 	:1;
	uint32_t usart1_en 	:1;
	uint32_t adc3_en 	:1;
	uint32_t reserved2 	:3;
	uint32_t tim9_en 	:1;
	uint32_t tim10_en 	:1;
	uint32_t tim11_en 	:1;
	uint32_t reserved3	:10;
}RCC_APB2ENR_t;

/*
			Address: 0x18
			Reset value: 0x0000 0000
*/

// CONTIENE A LOS PINES DEL 0 AL 7
typedef struct
{
	uint32_t pin0	:4;
	uint32_t pin1	:4;
	uint32_t pin2	:4;
	uint32_t pin3	:4;
	uint32_t pin4	:4;
	uint32_t pin5	:4;
	uint32_t pin6	:4;
	uint32_t pin7	:4;
}GPIOX_CRL_MODE_t;

/*
		Address offset: 0x00
		Reset value: 0x4444 4444
		//Bits 31:30, 27:26,
		//23:22, 19:18, 15:14,
		//11:10, 7:6, 3:2
		//CNFy[1:0]: Port x configuration bits (y= 0 .. 7)
		//These bits are written by software to configure the corresponding I/O port.
		//Refer to Table 20: Port bit configuration table.
		//In input mode (MODE[1:0]=00):
		//00: Analog mode
		//01: Floating input (reset state)
		//10: Input with pull-up / pull-down
		//11: Reserved
		//In output mode (MODE[1:0] >00):
		//00: General purpose output push-pull
		//01: General purpose output Open-drain
		//10: Alternate function output Push-pull
		//11: Alternate function output Open-drain
		//Bits 29:28, 25:24,
		//21:20, 17:16, 13:12,
		//9:8, 5:4, 1:0
		//MODEy[1:0]: Port x mode bits (y= 0 .. 7)
		//These bits are written by software to configure the corresponding I/O port.
		//Refer to Table 20: Port bit configuration table.
		//00: Input mode (reset state)
		//01: Output mode, max speed 10 MHz.
		//10: Output mode, max speed 2 MHz.
		//11: Output mode, max speed 50 MHz.
*/




// CONTIENE A LOS PINES DEL 8 AL 15
typedef struct
{
	uint32_t pin8	:4;
	uint32_t pin9	:4;
	uint32_t pin10	:4;
	uint32_t pin11	:4;
	uint32_t pin12	:4;
	uint32_t pin13	:4;
	uint32_t pin14	:4;
	uint32_t pin15	:4;
}GPIOX_CRH_MODE_t;

		/*
		Address offset: 0x04
		Reset value: 0x4444 4444
		Bits 31:30, 27:26,
		23:22, 19:18, 15:14,
		11:10, 7:6, 3:2
		CNFy[1:0]: Port x configuration bits (y= 8 .. 15)
		These bits are written by software to configure the corresponding I/O port.
		Refer to Table 20: Port bit configuration table.
		In input mode (MODE[1:0]=00):
		00: Analog mode
		01: Floating input (reset state)
		10: Input with pull-up / pull-down
		11: Reserved
		In output mode (MODE[1:0] >00):
		00: General purpose output push-pull
		01: General purpose output Open-drain
		10: Alternate function output Push-pull
		11: Alternate function output Open-drain
		Bits 29:28, 25:24,
		21:20, 17:16, 13:12,
		9:8, 5:4, 1:0
		MODEy[1:0]: Port x mode bits (y= 8 .. 15)
		These bits are written by software to configure the corresponding I/O port.
		Refer to Table 20: Port bit configuration table.
		00: Input mode (reset state)
		01: Output mode, max speed 10 MHz.
		10: Output mode, max speed 2 MHz.
		11: Output mode, max speed 50 MHz.
		*/



typedef struct
{
	uint32_t pin_0		:1;
	uint32_t pin_1		:1;
	uint32_t pin_2		:1;
	uint32_t pin_3		:1;
	uint32_t pin_4		:1;
	uint32_t pin_5		:1;
	uint32_t pin_6		:1;
	uint32_t pin_7		:1;
	uint32_t pin_8		:1;
	uint32_t pin_9		:1;
	uint32_t pin_10		:1;
	uint32_t pin_11		:1;
	uint32_t pin_12		:1;
	uint32_t pin_13		:1;
	uint32_t pin_14		:1;
	uint32_t pin_15		:1;
	uint32_t reserved 	:16;
}GPIO_ODR_t;

/*
		Address offset: 0x0C
		Reset value: 0x0000 0000
		Bits 31:16 Reserved, must be kept at reset value.
		Bits 15:0 ODRy: Port output data (y= 0 .. 15)
		These bits can be read and written by software and can be accessed in Word mode only.
		Note: For atomic bit set/reset, the ODR bits can be individually set and cleared by writing to
		the GPIOx_BSRR register (x = A .. G).
*/

#endif /* MAIN_H_ */
