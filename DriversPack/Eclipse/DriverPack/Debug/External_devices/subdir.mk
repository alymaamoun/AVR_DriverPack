################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../External_devices/lcd.c \
../External_devices/motor.c \
../External_devices/sensors.c \
../External_devices/ultrasonic.c 

OBJS += \
./External_devices/lcd.o \
./External_devices/motor.o \
./External_devices/sensors.o \
./External_devices/ultrasonic.o 

C_DEPS += \
./External_devices/lcd.d \
./External_devices/motor.d \
./External_devices/sensors.d \
./External_devices/ultrasonic.d 


# Each subdirectory must supply rules for building sources it contributes
External_devices/%.o: ../External_devices/%.c External_devices/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


