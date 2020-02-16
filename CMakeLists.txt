project(STM32_FREERTOS C CXX ASM)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR ARM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

set(TARGET_NAME free_rtos_app)

set(COMMON_FLAGS "-DSTM32F303xC -DUSE_HAL_DRIVER -DUSE_RTOS=1 -fno-common -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb ")