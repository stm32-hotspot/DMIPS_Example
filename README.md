# How to run Dhrystone/DMIPS benchmark on an STM32
Dhrystone is an old synthetic computing benchmark developed in 1984 by Reinhold P. Weicker to measure the combination of Computing and Compiler performance and gives result as a measured number of MIPS (Million Instructions per second).

## Example
The test is done on a STM32 NUCLEO-L552ZE-Q board and can be easily ported to other STM32 microcontrollers

## IDE Requirements and Software versions used:
-   NUCLEO-L552ZE-Q
-	KEIL uVision MDK ARM v5.38.0.0
-	ARM Compiler v6.16
-	STM32CubeMX v6.9.1 
-	Tera Term 4.105 
-	NUCLEO-L552ZE-Q_BSP
-	STM32L5xx_DFP for MDK ARM
-	STM32Cube MCU Package for STM32L5 series  v1.5.0 to generating the HAL/LL code using STM32CubeMX.
-   USB-A/USB-C to USB-C data cable


## Description of DMIPS_TEST directory
This directory contains a set of sources files and pre-configured projects that that describes how to build an application to perform DMIPS tests on an STM32 microcontroller


## Details
Please refer to the Knowledge Base Article for a full code explanation and implementation: 

**Caution** : Issues and the pull-requests are **not supported** to submit problems or suggestions related to the software delivered in this repository. The stm32 host programmer example is being delivered as-is, and not necessarily supported by ST.

**For any other question** related to the product, the hardware performance or characteristics, the tools, the environment, you can submit it to the **ST Community** on the STM32 MCUs related [page](https://community.st.com/s/topic/0TO0X000000BSqSWAW/stm32-mcus).
