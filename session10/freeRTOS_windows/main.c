#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

/* Priorities at which the tasks are created. */
#define TASK_MY_TASK_PRIORITY (tskIDLE_PRIORITY + 1)
#define TASK_MY_SECOND_TASK_PRIORITY (tskIDLE_PRIORITY + 2) // denne har højest prioritet, og afbryder den anden, når det er
/* Task stack sizes*/
#define TASK_MY_TASK_STACK (configMINIMAL_STACK_SIZE)
#define TASK_MY_SECOND_TASK_STACK (configMINIMAL_STACK_SIZE)

/* Task Handles */
TaskHandle_t _taskSecondHandle = NULL;

/*Mutex*/
SemaphoreHandle_t sharedMutex;

/*Mutex sørger for, at en højere prioritetsopgave ikke afbryder en lavere men
igangværende opgave - ellers crasher programmet bare. Lavere prioritetsopgaven skal
derfor have lov til at gøre færdig, før den anden overtager, og det hjælper
Mutex med
- lidt ala en lock, og vi afgiver låsen, når vi er færdig med opgaven
*/

// --------------------------------------------------------------------------------------
void taskMyTask(void *pvParameters)
{
	// Remove compiler warnings.
	(void)pvParameters;

	for (;;)
	{
		vTaskDelay(pdMS_TO_TICKS(100));
		if (xSemaphoreTake(sharedMutex, pdMS_TO_TICKS(200)) == pdTRUE) // tjekker om vi må bruge sharedMutex, eller om den er i brug - ellers venter vi 200ms og prøver igen
		{
			printf("Task 1\n");
			xSemaphoreGive(sharedMutex); // her afgiver vi låsen, da vi er færdig med opgaven
		}
		else
		{
			/*We timed out and could not obtain the mutex and can
			therefor not access the shared resource safely*/
		}
	}
}

// --------------------------------------------------------------------------------------
void taskMySeccondTask(void *pvParameters)
{
	// Remove compiler warnings.
	(void)pvParameters;

	for (;;)
	{
		vTaskDelay(pdMS_TO_TICKS(200));
		if (xSemaphoreTake(sharedMutex, pdMS_TO_TICKS(200)) == pdTRUE)
		{ // tjekker om vi må tage mutex, ellers venter vi
			printf("\tTask 2\n");
			xSemaphoreGive(sharedMutex); // her afgiver vi låsen, da vi er færdige med opgaven
		}
		else
		{
			/*We timed out and could not obtain the mutex and can
			therefor not access the shared resource safely*/
		}
	}
}

// --------------------------------------------------------------------------------------
void main(void)
{
	/* Create the task, not storing the handle. */
	setbuf(stdout, NULL);
	sharedMutex = xSemaphoreCreateMutex();
	xSemaphoreGive(sharedMutex);

	xTaskCreate(
		taskMyTask,			   /* Function that implements the task. */
		"MyTask",			   /* Text name for the task. */
		TASK_MY_TASK_STACK,	   /* Stack size in words, not bytes. */
		(void *)1,			   /* Parameter passed into the task. */
		TASK_MY_TASK_PRIORITY, /* Priority at which the task is created. */
		NULL);				   /* Used to pass out the created task's handle. */

	/* Create the task, storing the handle. */
	xTaskCreate(
		taskMySeccondTask,			  /* Function that implements the task. */
		"MySecondTask",				  /* Text name for the task. */
		TASK_MY_SECOND_TASK_STACK,	  /* Stack size in words, not bytes. */
		(void *)2,					  /* Parameter passed into the task. */
		TASK_MY_SECOND_TASK_PRIORITY, /* Priority at which the task is created. */
		&_taskSecondHandle);		  /* Used to pass out the created task's handle. */

	// Let the operating system take over :)
	vTaskStartScheduler();

	// This position is never reached...
}