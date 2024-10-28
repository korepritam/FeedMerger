################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/MarketDataTick.cpp \
../src/Merger.cpp 

CPP_DEPS += \
./src/MarketDataTick.d \
./src/Merger.d 

OBJS += \
./src/MarketDataTick.o \
./src/Merger.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/MarketDataTick.d ./src/MarketDataTick.o ./src/Merger.d ./src/Merger.o

.PHONY: clean-src

