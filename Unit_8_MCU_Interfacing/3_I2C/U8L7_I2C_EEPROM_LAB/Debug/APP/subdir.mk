################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/U8L5_spi.c \
../APP/U8L7_I2C_EEPROM.c 

OBJS += \
./APP/U8L5_spi.o \
./APP/U8L7_I2C_EEPROM.o 

C_DEPS += \
./APP/U8L5_spi.d \
./APP/U8L7_I2C_EEPROM.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o APP/%.su APP/%.cyclo: ../APP/%.c APP/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I"D:/00_Embedded System_ks/assignment(stm32cube&keil)/STM32_Cube_Assignment/Driver/STM32F103C6_Drivers/keypad_driver" -I../Inc -I"D:/00_Embedded System_ks/assignment(stm32cube&keil)/STM32_Cube_Assignment/Driver/HAL/includes" -I"D:/00_Embedded System_ks/assignment(stm32cube&keil)/STM32_Cube_Assignment/Driver/STM32F103C6_Drivers/lcd_driver" -I"D:/00_Embedded System_ks/assignment(stm32cube&keil)/STM32_Cube_Assignment/Driver/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-APP

clean-APP:
	-$(RM) ./APP/U8L5_spi.cyclo ./APP/U8L5_spi.d ./APP/U8L5_spi.o ./APP/U8L5_spi.su ./APP/U8L7_I2C_EEPROM.cyclo ./APP/U8L7_I2C_EEPROM.d ./APP/U8L7_I2C_EEPROM.o ./APP/U8L7_I2C_EEPROM.su

.PHONY: clean-APP

