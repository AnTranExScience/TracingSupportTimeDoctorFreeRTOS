################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/TimeDoctor.c \
../Src/fatfs.c \
../Src/fatfs_platform.c \
../Src/freertos.c \
../Src/main.c \
../Src/sd_diskio.c \
../Src/stm32f7xx_hal_msp.c \
../Src/stm32f7xx_hal_timebase_tim.c \
../Src/stm32f7xx_it.c \
../Src/syscalls.c \
../Src/system_stm32f7xx.c \
../Src/usb_host.c \
../Src/usbh_conf.c \
../Src/usbh_platform.c 

OBJS += \
./Src/TimeDoctor.o \
./Src/fatfs.o \
./Src/fatfs_platform.o \
./Src/freertos.o \
./Src/main.o \
./Src/sd_diskio.o \
./Src/stm32f7xx_hal_msp.o \
./Src/stm32f7xx_hal_timebase_tim.o \
./Src/stm32f7xx_it.o \
./Src/syscalls.o \
./Src/system_stm32f7xx.o \
./Src/usb_host.o \
./Src/usbh_conf.o \
./Src/usbh_platform.o 

C_DEPS += \
./Src/TimeDoctor.d \
./Src/fatfs.d \
./Src/fatfs_platform.d \
./Src/freertos.d \
./Src/main.d \
./Src/sd_diskio.d \
./Src/stm32f7xx_hal_msp.d \
./Src/stm32f7xx_hal_timebase_tim.d \
./Src/stm32f7xx_it.d \
./Src/syscalls.d \
./Src/system_stm32f7xx.d \
./Src/usb_host.d \
./Src/usbh_conf.d \
./Src/usbh_platform.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -DUSE_HAL_DRIVER -DSTM32F746xx '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Inc" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Drivers/STM32F7xx_HAL_Driver/Inc" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Middlewares/Third_Party/FatFs/src" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Drivers/CMSIS/Include" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Drivers/BSP/Components" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Drivers/BSP/STM32746G-Discovery" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Utilities/Fonts" -I"/Users/atran/Testanwendungen/LCD_Priority_Inversion_Semaphore_3_PrintTasks/Utilities/Log"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


