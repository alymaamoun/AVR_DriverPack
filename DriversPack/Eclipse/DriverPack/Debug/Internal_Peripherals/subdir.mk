################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Internal_Peripherals/adc.c \
../Internal_Peripherals/gpio.c \
../Internal_Peripherals/icu.c \
../Internal_Peripherals/timer.c 

OBJS += \
./Internal_Peripherals/adc.o \
./Internal_Peripherals/gpio.o \
./Internal_Peripherals/icu.o \
./Internal_Peripherals/timer.o 

C_DEPS += \
./Internal_Peripherals/adc.d \
./Internal_Peripherals/gpio.d \
./Internal_Peripherals/icu.d \
./Internal_Peripherals/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Internal_Peripherals/%.o: ../Internal_Peripherals/%.c Internal_Peripherals/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


