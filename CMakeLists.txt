project(STM32_FREERTOS C CXX ASM)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR ARM)

set(ELF_FILE ${PROJECT_NAME}.elf)
set(HEX_FILE ${PROJECT_NAME}.hex)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

set(TARGET_NAME free_rtos_app)

set(COMMON_FLAGS "-DSTM32F303xC -DUSE_HAL_DRIVER -fno-common -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -fdata-sections -ffunction-sections")
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} ${COMMON_FLAGS})
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${COMMON_FLAGS})

set(linker_script ${PROJECT_SOURCE_DIR}/STM32F303VCTx_FLASH.ld)
set(CMAKE_EXE_LINKER_FLAGS "-T${linker_script} -Wl,--gc-sections")

include_directories(Inc)
include_directories(Drivers/STM32F3xx_HAL_Driver/Inc)
include_directories(Drivers/STM32F3xx_HAL_Driver/Inc/Legacy)
include_directories(Drivers/CMSIS/Device)
include_directories(Drivers/CMSIS/Include)
include_directories(FreeRtos)

add_subdirectory(Drivers)
add_subdirectory(FreeRtos)

file(GLOB_RECURSE SRC_FILES_C Src/*.c)

add_executable(${ELF_FILE} ${SRC_FILES_C} ${SRC_FILES_CXX} Startup/startup_stm32f303xc.s Startup/system_stm32f3xx.c)

target_compile_options(${ELF_FILE} PRIVATE -Wall -Wextra)
target_link_libraries(${ELF_FILE} stm32f3_hal freertos c m nosys)


add_custom_command(TARGET ${ELF_FILE} POST_BUILD
                   COMMENT "Creating hex file."
                   COMMAND arm-none-eabi-objcopy ${ELF_FILE} -Oihex ${HEX_FILE})

add_custom_target(flash COMMENT "Flashing binary to ${TARGET_FLASH_DEVICE_NAME} using ${TARGET_FLASH_INTERFACE} (${TARGET_FLASH_SPEED})"
                  COMMAND ${PROJECT_SOURCE_DIR}/flash.sh DEPENDS ${ELF_FILE})
