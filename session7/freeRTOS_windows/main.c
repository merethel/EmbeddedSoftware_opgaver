#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"

/* Priorities at which the tasks are created. */
#define TASK_MY_TASK_PRIORITY			( tskIDLE_PRIORITY + 1 )
#define	TASK_MY_SECOND_TASK_PRIORITY	( tskIDLE_PRIORITY + 2 )
#define	TASK_MY_THIRD_TASK_PRIORITY  	( tskIDLE_PRIORITY + 3 )
/* Task stack sizes*/
#define TASK_MY_TASK_STACK				( configMINIMAL_STACK_SIZE )
#define	TASK_MY_SECOND_TASK_STACK		( configMINIMAL_STACK_SIZE )
#define	TASK_MY_THIRD_TASK_STACK		( configMINIMAL_STACK_SIZE )


/* Task Handles */
TaskHandle_t _taskSecondHandle = NULL;
TaskHandle_t _taskThirdHandle = NULL;

// --------------------------------------------------------------------------------------
void taskMyTask(void* pvParameters)
{
	// Remove compiler warnings.
	(void)pvParameters;

	TickType_t xLastWakeTime;
	const TickType_t xFrequency = 10;

     // Initialise the xLastWakeTime variable with the current time.
     xLastWakeTime = xTaskGetTickCount();

	for (;;)
	{
		
		vTaskDelayUntil( &xLastWakeTime, xFrequency);

		printf("Task 1\n");
	}
}

// --------------------------------------------------------------------------------------
void taskMySeccondTask(void* pvParameters)
{
	
	TickType_t xLastWakeTime;
	const TickType_t xFrequency = 10;

     // Initialise the xLastWakeTime variable with the current time.
     xLastWakeTime = xTaskGetTickCount();
	
	// Remove compiler warnings.
	(void)pvParameters;

	for (;;)
	{
		vTaskDelayUntil( &xLastWakeTime, xFrequency);
		printf("\tTask 2\n");
	}
}

// --------------------------------------------------------------------------------------
void taskMyThirdTask(void* pvParameters)
{
	TickType_t xLastWakeTime;
	const TickType_t xFrequency = 10;

     // Initialise the xLastWakeTime variable with the current time.
     xLastWakeTime = xTaskGetTickCount();
	
	// Remove compiler warnings.
	(void)pvParameters;

	for (;;)
	{
		vTaskDelayUntil( &xLastWakeTime, xFrequency);
		printf("\t\tTask 3\n");
	}
}

// --------------------------------------------------------------------------------------
void main(void)
{
	/* Create the task, not storing the handle. */
	setbuf(stdout, NULL);

	xTaskCreate(
		taskMyTask,       /* Function that implements the task. */
		"MyTask",          /* Text name for the task. */
		TASK_MY_TASK_STACK,      /* Stack size in words, not bytes. */
		(void*)1,    /* Parameter passed into the task. */
		TASK_MY_TASK_PRIORITY,/* Priority at which the task is created. */
		NULL);      /* Used to pass out the created task's handle. */

		/* Create the task, storing the handle. */
	xTaskCreate(
		taskMySeccondTask,       /* Function that implements the task. */
		"MySecondTask",          /* Text name for the task. */
		TASK_MY_SECOND_TASK_STACK,      /* Stack size in words, not bytes. */
		(void*)2,    /* Parameter passed into the task. */
		TASK_MY_SECOND_TASK_PRIORITY,/* Priority at which the task is created. */
		&_taskSecondHandle);      /* Used to pass out the created task's handle. */

				/* Create the task, storing the handle. */
	xTaskCreate(
		taskMyThirdTask,       /* Function that implements the task. */
		"MyThirdTask",          /* Text name for the task. */
		TASK_MY_THIRD_TASK_STACK,      /* Stack size in words, not bytes. */
		(void*)3,    /* Parameter passed into the task. */
		TASK_MY_THIRD_TASK_PRIORITY,/* Priority at which the task is created. */
		&_taskThirdHandle);      /* Used to pass out the created task's handle. */

	// Let the operating system take over :)
	vTaskStartScheduler();

	//This position is never reached... 
}