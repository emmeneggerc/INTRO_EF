################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/BitIoLdd1.c \
../Generated_Code/BitIoLdd2.c \
../Generated_Code/Cpu.c \
../Generated_Code/LED1.c \
../Generated_Code/LED2.c \
../Generated_Code/LEDpin1.c \
../Generated_Code/LEDpin2.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/Vectors.c \
../Generated_Code/WAIT1.c 

OBJS += \
./Generated_Code/BitIoLdd1.o \
./Generated_Code/BitIoLdd2.o \
./Generated_Code/Cpu.o \
./Generated_Code/LED1.o \
./Generated_Code/LED2.o \
./Generated_Code/LEDpin1.o \
./Generated_Code/LEDpin2.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/Vectors.o \
./Generated_Code/WAIT1.o 

C_DEPS += \
./Generated_Code/BitIoLdd1.d \
./Generated_Code/BitIoLdd2.d \
./Generated_Code/Cpu.d \
./Generated_Code/LED1.d \
./Generated_Code/LED2.d \
./Generated_Code/LEDpin1.d \
./Generated_Code/LEDpin2.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/Vectors.d \
./Generated_Code/WAIT1.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/Cornel/Documents/EF_INTRO_HS15/Debug_Test_Intro/Static_Code/PDD" -I"C:/Users/Cornel/Documents/EF_INTRO_HS15/Debug_Test_Intro/Static_Code/IO_Map" -I"C:/Users/Cornel/Documents/EF_INTRO_HS15/Debug_Test_Intro/Sources" -I"C:/Users/Cornel/Documents/EF_INTRO_HS15/Debug_Test_Intro/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


