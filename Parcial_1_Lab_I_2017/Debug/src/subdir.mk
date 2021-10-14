################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Contrataciones.c \
../src/Info.c \
../src/Menu.c \
../src/Pantalla.c \
../src/Parcial_1_Lab_I_2017.c \
../src/Pedir.c 

OBJS += \
./src/Contrataciones.o \
./src/Info.o \
./src/Menu.o \
./src/Pantalla.o \
./src/Parcial_1_Lab_I_2017.o \
./src/Pedir.o 

C_DEPS += \
./src/Contrataciones.d \
./src/Info.d \
./src/Menu.d \
./src/Pantalla.d \
./src/Parcial_1_Lab_I_2017.d \
./src/Pedir.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


