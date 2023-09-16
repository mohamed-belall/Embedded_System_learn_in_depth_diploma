################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/keypad_driver/keypad_Driver.c 

OBJS += \
./HAL/keypad_driver/keypad_Driver.o 

C_DEPS += \
./HAL/keypad_driver/keypad_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/keypad_driver/%.o HAL/keypad_driver/%.su HAL/keypad_driver/%.cyclo: ../HAL/keypad_driver/%.c HAL/keypad_driver/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I"D:/00_Embedded System_ks/assignment(stm32cube&keil)/STM32_Cube_Assignment/Driver/STM32F103C6_Drivers/keypad_driver" -I../Inc -I"D:/00_Embedded System_ks/assignment(stm32cube&keil)/STM32_Cube_Assignment/Driver/HAL/includes" -I"D:/00_Embedded System_ks/assignment(stm32cube&keil)/STM32_Cube_Assignment/Driver/STM32F103C6_Drivers/lcd_driver" -I"D:/00_Embedded System_ks/assignment(stm32cube&keil)/STM32_Cube_Assignment/Driver/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL-2f-keypad_driver

clean-HAL-2f-keypad_driver:
	-$(RM) ./HAL/keypad_driver/keypad_Driver.cyclo ./HAL/keypad_driver/keypad_Driver.d ./HAL/keypad_driver/keypad_Driver.o ./HAL/keypad_driver/keypad_Driver.su

.PHONY: clean-HAL-2f-keypad_driver

