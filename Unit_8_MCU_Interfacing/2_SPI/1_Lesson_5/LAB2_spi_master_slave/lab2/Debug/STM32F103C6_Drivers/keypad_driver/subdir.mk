################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/keypad_driver/keypad_Driver.c 

OBJS += \
./STM32F103C6_Drivers/keypad_driver/keypad_Driver.o 

C_DEPS += \
./STM32F103C6_Drivers/keypad_driver/keypad_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/keypad_driver/%.o STM32F103C6_Drivers/keypad_driver/%.su STM32F103C6_Drivers/keypad_driver/%.cyclo: ../STM32F103C6_Drivers/keypad_driver/%.c STM32F103C6_Drivers/keypad_driver/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"D:/00_Embedded System_ks/assignment(stm32cube&keil)/STM32_Cube_Assignment/Driver/STM32F103C6_Drivers/keypad_driver" -I"D:/00_Embedded System_ks/assignment(stm32cube&keil)/STM32_Cube_Assignment/Driver/STM32F103C6_Drivers/lcd_driver" -I"D:/00_Embedded System_ks/assignment(stm32cube&keil)/STM32_Cube_Assignment/Driver/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32F103C6_Drivers-2f-keypad_driver

clean-STM32F103C6_Drivers-2f-keypad_driver:
	-$(RM) ./STM32F103C6_Drivers/keypad_driver/keypad_Driver.cyclo ./STM32F103C6_Drivers/keypad_driver/keypad_Driver.d ./STM32F103C6_Drivers/keypad_driver/keypad_Driver.o ./STM32F103C6_Drivers/keypad_driver/keypad_Driver.su

.PHONY: clean-STM32F103C6_Drivers-2f-keypad_driver

