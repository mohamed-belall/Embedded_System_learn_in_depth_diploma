################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/lcd_driver/lcd_driver.c 

OBJS += \
./HAL/lcd_driver/lcd_driver.o 

C_DEPS += \
./HAL/lcd_driver/lcd_driver.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/lcd_driver/%.o HAL/lcd_driver/%.su HAL/lcd_driver/%.cyclo: ../HAL/lcd_driver/%.c HAL/lcd_driver/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I"D:/00_Embedded System_ks/assignment(stm32cube&keil)/STM32_Cube_Assignment/Driver/STM32F103C6_Drivers/keypad_driver" -I../Inc -I"D:/00_Embedded System_ks/assignment(stm32cube&keil)/STM32_Cube_Assignment/Driver/HAL/includes" -I"D:/00_Embedded System_ks/assignment(stm32cube&keil)/STM32_Cube_Assignment/Driver/STM32F103C6_Drivers/lcd_driver" -I"D:/00_Embedded System_ks/assignment(stm32cube&keil)/STM32_Cube_Assignment/Driver/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL-2f-lcd_driver

clean-HAL-2f-lcd_driver:
	-$(RM) ./HAL/lcd_driver/lcd_driver.cyclo ./HAL/lcd_driver/lcd_driver.d ./HAL/lcd_driver/lcd_driver.o ./HAL/lcd_driver/lcd_driver.su

.PHONY: clean-HAL-2f-lcd_driver

