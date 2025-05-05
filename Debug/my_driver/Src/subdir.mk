################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../my_driver/Src/my_rtos.c \
../my_driver/Src/my_struct.c \
../my_driver/Src/task.c 

OBJS += \
./my_driver/Src/my_rtos.o \
./my_driver/Src/my_struct.o \
./my_driver/Src/task.o 

C_DEPS += \
./my_driver/Src/my_rtos.d \
./my_driver/Src/my_struct.d \
./my_driver/Src/task.d 


# Each subdirectory must supply rules for building sources it contributes
my_driver/Src/%.o my_driver/Src/%.su my_driver/Src/%.cyclo: ../my_driver/Src/%.c my_driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"U:/projects/my_rtos/my_driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-my_driver-2f-Src

clean-my_driver-2f-Src:
	-$(RM) ./my_driver/Src/my_rtos.cyclo ./my_driver/Src/my_rtos.d ./my_driver/Src/my_rtos.o ./my_driver/Src/my_rtos.su ./my_driver/Src/my_struct.cyclo ./my_driver/Src/my_struct.d ./my_driver/Src/my_struct.o ./my_driver/Src/my_struct.su ./my_driver/Src/task.cyclo ./my_driver/Src/task.d ./my_driver/Src/task.o ./my_driver/Src/task.su

.PHONY: clean-my_driver-2f-Src

