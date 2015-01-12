################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/cube.cpp \
../src/game.cpp \
../src/main.cpp \
../src/shader.cpp \
../src/world.cpp 

OBJS += \
./src/cube.o \
./src/game.o \
./src/main.o \
./src/shader.o \
./src/world.o 

CPP_DEPS += \
./src/cube.d \
./src/game.d \
./src/main.d \
./src/shader.d \
./src/world.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=gnu++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


