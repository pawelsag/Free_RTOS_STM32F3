
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName );

void init_task(void *params) {
  while (1) {
    HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_8|GPIO_PIN_9);
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}


int main(void)
{
  HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();

  xTaskCreate(init_task, "init_task", configMINIMAL_STACK_SIZE * 1, NULL, 1, NULL);
  vTaskStartScheduler();
  while (1)
  {
  }
}

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
  ( void ) pcTaskName;
  ( void ) pxTask;

  /* Run time stack overflow checking is performed if
  configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
  function is called if a stack overflow is detected. */
  taskDISABLE_INTERRUPTS();
  for( ;; );
}

void
HAL_Delay(volatile uint32_t millis)
{
  /* replace HAL library blocking delay function
  * with FreeRTOS thread aware equivalent */
  vTaskDelay(millis);
}