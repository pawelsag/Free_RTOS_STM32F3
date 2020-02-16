
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"



int main(void)
{
  HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();

  while (1)
  {

  }
}

