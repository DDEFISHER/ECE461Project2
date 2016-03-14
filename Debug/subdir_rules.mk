################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
alarm.obj: ../alarm.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/workspace2/driverlib/MSP432P4xx/ccs" --include_path="/home/daniel/Programs/ti/workspace2/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/workspace2/driverlib" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="alarm.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

doorbell.obj: ../doorbell.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/workspace2/driverlib/MSP432P4xx/ccs" --include_path="/home/daniel/Programs/ti/workspace2/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/workspace2/driverlib" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="doorbell.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/workspace2/driverlib/MSP432P4xx/ccs" --include_path="/home/daniel/Programs/ti/workspace2/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/workspace2/driverlib" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

msp432_startup_ccs.obj: ../msp432_startup_ccs.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/workspace2/driverlib/MSP432P4xx/ccs" --include_path="/home/daniel/Programs/ti/workspace2/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/workspace2/driverlib" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="msp432_startup_ccs.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


