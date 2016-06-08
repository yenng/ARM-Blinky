#include "unity.h"
#include "Register.h"
#include "Rcc.h"
#include "Gpio.h"
#include "Host.h"

void setUp(void){
  // RCC_reg->RCC_AHB1ENR  = 0;
  // RCC_reg->RCC_AHB1RSTR = 0xFFFFFFFF;
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
}
