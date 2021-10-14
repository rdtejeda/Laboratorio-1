################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ArrayEmployees.c \
../src/Mi_ABM_GENERICO.c \
../src/Pedir.c 

OBJS += \
./src/ArrayEmployees.o \
./src/Mi_ABM_GENERICO.o \
./src/Pedir.o 

C_DEPS += \
./src/ArrayEmployees.d \
./src/Mi_ABM_GENERICO.d \
./src/Pedir.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


