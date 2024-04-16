#include "LCD.h"
#include "KEYPAD.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

/****************************************************
 *  Constants and Definitions
 ****************************************************/
#define XDELAY		 500
#define QUEUE_LENGTH 5

/****************************************************
 *  Shared Resources
 ****************************************************/
QueueHandle_t App_queue_buffer;

/**
 * @brief Task that reads input from a keypad and sends it to a message queue.
 * 
 * This task continuously reads input from a keypad using the KEYPAD_getPressedKey() function.
 * The pressed key is then sent to a message queue using xQueueSend() function.
 * If the sending of data to the message queue fails, an error message is displayed on an LCD screen.
 * The task delays for a specified time period using vTaskDelay() before reading the next key.
 */
void keypad_task(void)
{
	char key;
	while (1)
	{
		key = KEYPAD_getPressedKey();
		if (xQueueSend(App_queue_buffer, &key, portMAX_DELAY) != pdTRUE) //send data to the messege queue
		{
			LCD_clearScreen();
			LCD_displayString("xQueueSend failed");
		}
		vTaskDelay(XDELAY);
	}
}

/**
 * @brief Task that handles displaying characters and integers on an LCD screen.
 * 
 * This task continuously waits for data to be received from a message queue and then
 * displays the received data on an LCD screen. If the received data is a digit (0-9),
 * it is displayed as an integer. Otherwise, it is displayed as a character.
 * If the task fails to receive data from the message queue, it clears the screen
 * and displays an error message.
 */
void LCD_task(void)
{
	char ch;
	while (1)
	{
		if (xQueueReceive(App_queue_buffer, &ch, portMAX_DELAY) == pdTRUE)
		{
			if (ch >= 0 && ch <= 9)
			{
				LCD_displayInteger(ch);
			}
			else
			{
				LCD_displayCharacter(ch);
			}
		}
		else
		{
			LCD_clearScreen();
			LCD_displayString("xQueueReceive failed");
		}
	}
}

int main(void)
{
	/* App Initialization */
	LCD_init();

	TaskHandle_t keypadTaskHandle = NULL;
	TaskHandle_t lcdTaskHandle = NULL;

	/* Create tasks */
	xTaskCreate(keypad_task, "k", configMINIMAL_STACK_SIZE, NULL, 2, &keypadTaskHandle);
	xTaskCreate(LCD_task, "L", configMINIMAL_STACK_SIZE, NULL, 1, &lcdTaskHandle);

	if (keypadTaskHandle == NULL || lcdTaskHandle == NULL)
	{
		LCD_clearScreen();
		LCD_displayString("Task creation failed");
	}

	/* Create a message queue */
	App_queue_buffer = xQueueCreate(QUEUE_LENGTH, sizeof(char));
	if (App_queue_buffer == NULL)
	{
		LCD_clearScreen();
		LCD_displayString("Queue creation failed");
	}

	/* Start the scheduler */
	vTaskStartScheduler();
}
