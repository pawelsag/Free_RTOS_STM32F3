
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"

void init_task(void *params) {
  while (1) {
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}


int main(void)
{
  HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();

  xTaskCreate(init_task, "init_task", configMINIMAL_STACK_SIZE * 5, NULL, 1, NULL);
  vTaskStartScheduler();

  while (1)
  {
  }
}

