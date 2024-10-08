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

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif




int main(void)
{
    uint32_t *pClkRg = 		(uint32_t*)0x40021018; // APB2 EN NUCLEO STM32F103RB
    uint32_t *pPortAMode = 	(uint32_t*)0x40010800; // ESTO PARA EL MODO DEL PUERTO 5
    uint32_t *pPortDOut= 	(uint32_t*)0x4001080C; // ESTO PARA EL PUERTO 5

    //1.- Se parte a encender el GPIO CLOCK del Puerto A
    *pClkRg |= 0x04;
    // Forma alterna de escribirlo
    // *pClkRg |= (1<<2);
    //2.- Se configura el modo del puerto a SALIDA
    //Primero se limpian los elementos de CNF5 (22,23) y MODE5(20,21)
    *pPortAMode &= 0xFF0FFFFF;
    // Forma alterna de escribirlo
    // *pPortAMode &= ~ (8<<20);
    //Se activa el bit para modo de salida 01 (20MHZ bit 21) y Tipo General (00 bit 22 23)
    *pPortAMode |= 0x00100000;
    // Forma alterna de escribirlo
    // *pPortAMode |= (1<<21);
    //3.- Configurar como HIGH el pin5 en ODR
    *pPortDOut |= 0x00000020;

	while(1);
}
