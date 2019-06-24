################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/otm8009a/otm8009a.c 

OBJS += \
./Drivers/BSP/Components/otm8009a/otm8009a.o 

C_DEPS += \
./Drivers/BSP/Components/otm8009a/otm8009a.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/otm8009a/%.o: ../Drivers/BSP/Components/otm8009a/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -DUSE_HAL_DRIVER -DSTM32F746xx '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Inc" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Drivers/STM32F7xx_HAL_Driver/Inc" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Middlewares/Third_Party/FatFs/src" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Drivers/CMSIS/Include" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Drivers/BSP/Components" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Drivers/BSP/STM32746G-Discovery" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Utilities/Fonts" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Utilities/Log"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


