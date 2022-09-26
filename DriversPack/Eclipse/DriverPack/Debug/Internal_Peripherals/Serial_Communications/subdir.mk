################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Internal_Peripherals/Serial_Communications/spi.c \
../Internal_Peripherals/Serial_Communications/uart.c 

OBJS += \
./Internal_Peripherals/Serial_Communications/spi.o \
./Internal_Peripherals/Serial_Communications/uart.o 

C_DEPS += \
./Internal_Peripherals/Serial_Communications/spi.d \
./Internal_Peripherals/Serial_Communications/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Internal_Peripherals/Serial_Communications/%.o: ../Internal_Peripherals/Serial_Communications/%.c Internal_Peripherals/Serial_Communications/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


