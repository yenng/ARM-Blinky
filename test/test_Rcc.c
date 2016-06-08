#include "unity.h"
#include "Register.h"
#include "Rcc.h"
#include "Gpio.h"
#include "HostRcc.h"

void setUp(void){
  RCC_reg->RCC_AHB1ENR  = 0;
  RCC_reg->RCC_AHB1RSTR = 0xFFFFFFFF;
}

void tearDown(void){}

void test_Rcc_not_reset_and_clock_GpioA(void){
  gpioUnresetEnableClock(PORTA);
  
  TEST_ASSERT_EQUAL(1, RCC_reg->RCC_AHB1ENR & 1);
  TEST_ASSERT_EQUAL(0, RCC_reg->RCC_AHB1RSTR & 1);
  
  TEST_ASSERT_EQUAL(&HostGpioA, PORTA);
}
