################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CommonStructures.cpp \
../src/ConfigReader.cpp \
../src/FileManager.cpp \
../src/GlobalMembers.cpp \
../src/MarketDataContainer.cpp \
../src/MarketDataTick.cpp \
../src/ThreadWorker.cpp \
../src/main.cpp 

CPP_DEPS += \
./src/CommonStructures.d \
./src/ConfigReader.d \
./src/FileManager.d \
./src/GlobalMembers.d \
./src/MarketDataContainer.d \
./src/MarketDataTick.d \
./src/ThreadWorker.d \
./src/main.d 

OBJS += \
./src/CommonStructures.o \
./src/ConfigReader.o \
./src/FileManager.o \
./src/GlobalMembers.o \
./src/MarketDataContainer.o \
./src/MarketDataTick.o \
./src/ThreadWorker.o \
./src/main.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++17 -I"/Users/pritam/git/FeedMerger/include" -I"/Users/pritam/git/FeedMerger/Tests" -I/Users/pritam/git-workspace/googletestlib/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/CommonStructures.d ./src/CommonStructures.o ./src/ConfigReader.d ./src/ConfigReader.o ./src/FileManager.d ./src/FileManager.o ./src/GlobalMembers.d ./src/GlobalMembers.o ./src/MarketDataContainer.d ./src/MarketDataContainer.o ./src/MarketDataTick.d ./src/MarketDataTick.o ./src/ThreadWorker.d ./src/ThreadWorker.o ./src/main.d ./src/main.o

.PHONY: clean-src

