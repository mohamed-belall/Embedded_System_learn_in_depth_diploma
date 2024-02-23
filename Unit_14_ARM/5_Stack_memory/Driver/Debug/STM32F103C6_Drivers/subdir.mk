################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/STM32F103C6_EXTI_Driver.c \
../STM32F103C6_Drivers/STM32F103C6_GPIO_Driver.c \
../STM32F103C6_Drivers/STM32F103C6_I2C_Driver.c \
../STM32F103C6_Drivers/STM32F103C6_RCC_Drivers.c \
../STM32F103C6_Drivers/STM32F103C6_SPI_Driver.c \
../STM32F103C6_Drivers/STM32F103C6_USART_Drivers.c 

OBJS += \
./STM32F103C6_Drivers/STM32F103C6_EXTI_Driver.o \
./STM32F103C6_Drivers/STM32F103C6_GPIO_Driver.o \
./STM32F103C6_Drivers/STM32F103C6_I2C_Driver.o \
./STM32F103C6_Drivers/STM32F103C6_RCC_Drivers.o \
./STM32F103C6_Drivers/STM32F103C6_SPI_Driver.o \
./STM32F103C6_Drivers/STM32F103C6_USART_Drivers.o 

C_DEPS += \
./STM32F103C6_Drivers/STM32F103C6_EXTI_Driver.d \
./STM32F103C6_Drivers/STM32F103C6_GPIO_Driver.d \
./STM32F103C6_Drivers/STM32F103C6_I2C_Driver.d \
./STM32F103C6_Drivers/STM32F103C6_RCC_Drivers.d \
./STM32F103C6_Drivers/STM32F103C6_SPI_Driver.d \
./STM32F103C6_Drivers/STM32F103C6_USART_Drivers.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/%.o STM32F103C6_Drivers/%.su STM32F103C6_Drivers/%.cyclo: ../STM32F103C6_Drivers/%.c STM32F103C6_Drivers/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I"D:/00_Embedded System_ks/assignment(stm32cube&keil)/STM32_Cube_Assignment/Driver/STM32F103C6_Drivers/keypad_driver" -I../Inc -I"D:/00_Embedded System_ks/assignment(stm32cube&keil)/STM32_Cube_Assignment/Driver/HAL/includes" -I"D:/00_Embedded System_ks/assignment(stm32cube&keil)/STM32_Cube_Assignment/Driver/STM32F103C6_Drivers/lcd_driver" -I"D:/00_Embedded System_ks/assignment(stm32cube&keil)/STM32_Cube_Assignment/Driver/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32F103C6_Drivers

clean-STM32F103C6_Drivers:
	-$(RM) ./STM32F103C6_Drivers/STM32F103C6_EXTI_Driver.cyclo ./STM32F103C6_Drivers/STM32F103C6_EXTI_Driver.d ./STM32F103C6_Drivers/STM32F103C6_EXTI_Driver.o ./STM32F103C6_Drivers/STM32F103C6_EXTI_Driver.su ./STM32F103C6_Drivers/STM32F103C6_GPIO_Driver.cyclo ./STM32F103C6_Drivers/STM32F103C6_GPIO_Driver.d ./STM32F103C6_Drivers/STM32F103C6_GPIO_Driver.o ./STM32F103C6_Drivers/STM32F103C6_GPIO_Driver.su ./STM32F103C6_Drivers/STM32F103C6_I2C_Driver.cyclo ./STM32F103C6_Drivers/STM32F103C6_I2C_Driver.d ./STM32F103C6_Drivers/STM32F103C6_I2C_Driver.o ./STM32F103C6_Drivers/STM32F103C6_I2C_Driver.su ./STM32F103C6_Drivers/STM32F103C6_RCC_Drivers.cyclo ./STM32F103C6_Drivers/STM32F103C6_RCC_Drivers.d ./STM32F103C6_Drivers/STM32F103C6_RCC_Drivers.o ./STM32F103C6_Drivers/STM32F103C6_RCC_Drivers.su ./STM32F103C6_Drivers/STM32F103C6_SPI_Driver.cyclo ./STM32F103C6_Drivers/STM32F103C6_SPI_Driver.d ./STM32F103C6_Drivers/STM32F103C6_SPI_Driver.o ./STM32F103C6_Drivers/STM32F103C6_SPI_Driver.su ./STM32F103C6_Drivers/STM32F103C6_USART_Drivers.cyclo ./STM32F103C6_Drivers/STM32F103C6_USART_Drivers.d ./STM32F103C6_Drivers/STM32F103C6_USART_Drivers.o ./STM32F103C6_Drivers/STM32F103C6_USART_Drivers.su

.PHONY: clean-STM32F103C6_Drivers

