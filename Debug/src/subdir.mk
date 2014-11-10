################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/allCode.cpp \
../src/game.cpp \
../src/main.cpp \
../src/shader.cpp 

OBJS += \
./src/allCode.o \
./src/game.o \
./src/main.o \
./src/shader.o 

CPP_DEPS += \
./src/allCode.d \
./src/game.d \
./src/main.d \
./src/shader.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/gv30/H_Drive/Simple OpenGL Image Library/src" -include"/home/gv30/H_Drive/Simple OpenGL Image Library/src/SOIL.h" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


