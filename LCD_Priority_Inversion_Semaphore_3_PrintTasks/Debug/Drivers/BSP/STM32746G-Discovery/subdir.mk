################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/STM32746G-Discovery/stm32746g_discovery.c \
../Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_audio.c \
../Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_camera.c \
../Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_eeprom.c \
../Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_lcd.c \
../Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_qspi.c \
../Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sd.c \
../Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sdram.c \
../Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_ts.c 

OBJS += \
./Drivers/BSP/STM32746G-Discovery/stm32746g_discovery.o \
./Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_audio.o \
./Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_camera.o \
./Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_eeprom.o \
./Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_lcd.o \
./Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_qspi.o \
./Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sd.o \
./Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sdram.o \
./Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_ts.o 

C_DEPS += \
./Drivers/BSP/STM32746G-Discovery/stm32746g_discovery.d \
./Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_audio.d \
./Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_camera.d \
./Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_eeprom.d \
./Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_lcd.d \
./Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_qspi.d \
./Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sd.d \
./Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sdram.d \
./Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_ts.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32746G-Discovery/%.o: ../Drivers/BSP/STM32746G-Discovery/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -DUSE_HAL_DRIVER -DSTM32F746xx '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Inc" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Drivers/STM32F7xx_HAL_Driver/Inc" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Middlewares/Third_Party/FatFs/src" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Drivers/CMSIS/Include" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Drivers/BSP/Components" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Drivers/BSP/STM32746G-Discovery" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Utilities/Fonts" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Utilities/Log"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


