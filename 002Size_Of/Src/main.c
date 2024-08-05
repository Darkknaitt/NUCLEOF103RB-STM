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

#include <stdio.h>
int main(void)
{
	long long datalong = 900;
	char size = sizeof(datalong);
	printf("Size of char data type = %d\n",sizeof(char));
	printf("Size of short data type = %d\n",sizeof(short));
	printf("Size of int data type = %d\n",sizeof(int));
	printf("Size of long data type = %d\n",sizeof(long));
	printf("Size of long long data type = %d\n",sizeof(long long));
	printf("Size of datalong data type = %d\n",sizeof(datalong));
	printf("Size of char data type = %d\n",size);
	for(;;);
    /* Loop forever */
}
