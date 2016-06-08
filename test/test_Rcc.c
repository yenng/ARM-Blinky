#include "unity.h"
#include "malloc.h"
#include "Register.h"
#include "Rcc.h"
#include "Gpio.h"
#include "Host.h"

#define GPIO_MEM_MAPPED_SIZE 0x400

void setUp(void){
  HostRcc = malloc(sizeof(RCC_t));//have to manually allocated
	//GPIOA - GPIOK (11 GPIOs in total for STM32F429ZI)
	
	HostGpioA = malloc(GPIO_MEM_MAPPED_SIZE * 11);
	HostGpioB = HostGpioA + 0x400;
	HostGpioC = HostGpioB + 0x400;
	HostGpioD = HostGpioC + 0x400;
	HostGpioE = HostGpioD + 0x400;
	HostGpioF = HostGpioE + 0x400;
	HostGpioG = HostGpioF + 0x400;
	
}

void tearDown(void){}

void test_module_generator_needs_to_be_implemented(void)
{
	TEST_IGNORE_MESSAGE("Implement me!");
}

void test_notResetAndClockGpioA(void){
	rcc->RCC_AHB1ENR = 0;
	rcc->RCC_AHB1RSTR = 0xFFFFFFFF;
	
	//notResetAndClockGpioA();
	gpioUnresetEnableClock(PORTA);
	
	TEST_ASSERT_EQUAL(1,rcc->RCC_AHB1ENR & 1);
	TEST_ASSERT_EQUAL(0,rcc->RCC_AHB1RSTR & 1);
	
	TEST_ASSERT_EQUAL_HEX32(rcc, HostRcc);
	TEST_ASSERT_EQUAL_HEX32(PORTA, HostGpioA);
}

void test_writeOne(){
	TEST_ASSERT_EQUAL_HEX32(PORTG, HostGpioG);
	
	PORTG->BSRR = 0;
	writeOne(PIN_4,PORTG);
	TEST_ASSERT_EQUAL(1<<4, PORTG->BSRR);
	
}