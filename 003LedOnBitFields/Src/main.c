/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "main.h"


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif




int main(void)
{
/*
    uint32_t *pClkRg = 		(uint32_t*)0x40021018; // APB2 EN NUCLEO STM32F103RB
    uint32_t *pPortAMode = 	(uint32_t*)0x40010800; // ESTO PARA EL MODO DEL PUERTO 5
    uint32_t *pPortDOut= 	(uint32_t*)0x4001080C; // ESTO PARA EL PUERTO 5
*/

    // 1.- Se activa el reloj APB2ENR
    RCC_APB2ENR_t volatile *const pClkRg = (RCC_APB2ENR_t*)0x40021018;
    pClkRg->gpioa_en = 1;

    GPIOX_CRL_MODE_t volatile *const pPortAMode = (GPIOX_CRL_MODE_t*)0x40010800;
    pPortAMode->pin5 = 0;
    pPortAMode->pin5 = 1;

    while(1)
    {
    	GPIO_ODR_t volatile *const pPortAOut = (GPIO_ODR_t*)0x4001080C;
		pPortAOut->pin_5 = 1;
//    	*pPortDOut |= (1<<5);
		// Se crea un pequeño delay con un ciclo
		for(uint32_t i = 0 ; i <100000; i++);

		// Ahora se apaga el LED
		pPortAOut->pin_5 = 0;
//		*pPortDOut &=~ (1<<5);

		for(uint32_t i = 0 ; i <100000; i++);
    }
/*
    //2.- Se configura el modo del puerto a SALIDA
    //Primero se limpian los elementos de CNF5 (22,23) y MODE5(20,21)
//    *pPortAMode &= 0xFF0FFFFF;
    // Forma alterna de escribirlo
     *pPortAMode &=~ (15<<20);
    //Se activa el bit para modo de salida 01 (20MHZ bit 21) y Tipo General (00 bit 22 23)
//    *pPortAMode |= 0x00100000;
    // Forma alterna de escribirlo
     *pPortAMode |= (1<<20);
    //3.- Configurar como HIGH el pin5 en ODR
//    *pPortDOut |= 0x00000020;
    while(1)
    {
		*pPortDOut |= (1<<5);
		// Se crea un pequeño delay con un ciclo
		for(uint32_t i = 0 ; i <10000000; i++);

		// Ahora se apaga el LED
		*pPortDOut &=~ (1<<5);

		for(uint32_t i = 0 ; i <10000000; i++);
    }
   */
}
