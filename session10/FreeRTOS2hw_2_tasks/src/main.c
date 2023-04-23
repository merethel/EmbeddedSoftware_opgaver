/*
 * FreeRTOS_ATMEGA.c
 *
 * Created: 15/10/2018 13:08:53
 * Author : IHA
 */

// #define configCPU_CLOCK_HZ     ( ( uint32_t ) F_CPU )
#define BAUD 9600
// #define configTICK_RATE_HZ     ( ( TickType_t ) 1000 )

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/sfr_defs.h>
#include <stdio.h>

#include "semphr.h"

#include <ATMEGA_FreeRTOS.h>
#include <semphr.h>

#include "FreeRTOSTraceDriver.h"
#include "uart.h"

/*Mutex*/
SemaphoreHandle_t sharedMutex;

// define two Tasks
void task1(void *pvParameters);
void task2(void *pvParameters);

// define semaphore handle

/*-----------------------------------------------------------*/
void create_tasks_and_semaphores(void)
{
	sharedMutex = xSemaphoreCreateMutex();
	xSemaphoreGive(sharedMutex);
	xTaskCreate(
		task1, "Task1" // A name just for humans
		,
		configMINIMAL_STACK_SIZE // This stack size can be checked & adjusted by reading the Stack Highwater
		,
		NULL, 2 // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
		,
		NULL);

	xTaskCreate(
		task2, "Task2" // A name just for humans
		,
		configMINIMAL_STACK_SIZE // This stack size can be checked & adjusted by reading the Stack Highwater
		,
		NULL, 3 // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
		,
		NULL);
}

/*-----------------------------------------------------------*/
void task1(void *pvParameters)
{
	TickType_t xLastWakeTime = xTaskGetTickCount();

	uartInit(BAUD);
	for (;;)
	{
		// xSemaphoreTake(xTestSemaphore,portMAX_DELAY);
		xTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(5000));

		if (xSemaphoreTake(sharedMutex, pdMS_TO_TICKS(200)) == pdTRUE)
		{ // tjekker om vi må tage mutex, ellers venter vi
			USART_sendString("11111111111111111111111111111111111\n");
			xSemaphoreGive(sharedMutex);
		}
		else
		{
			/*We timed out and could not obtain the mutex and can
			therefor not access the shared resource safely*/
		}
	}
}

/*-----------------------------------------------------------*/
void task2(void *pvParameters)
{
	DDRB = 128;
	for (;;)
	{
		vTaskDelay(pdMS_TO_TICKS(300));
		if (xSemaphoreTake(sharedMutex, pdMS_TO_TICKS(200)) == pdTRUE)
		{ // tjekker om vi må tage mutex, ellers venter vi
			USART_sendString("22222222222222222222222222222222222222222\n");
			PORTB ^= 128;
			xSemaphoreGive(sharedMutex);
		}
		else
		{
			/*We timed out and could not obtain the mutex and can
			therefor not access the shared resource safely*/
		}
	}
}

/*-----------------------------------------------------------*/
int main(void)
{
	DDRA |= _BV(DDA0) | _BV(DDA7);
	_delay_ms(1000);
	create_tasks_and_semaphores();
	vTaskStartScheduler(); // initialise and run the freeRTOS scheduler. Execution should never return here.

	/* Replace with your application code */
	while (1)
	{
	}
}
