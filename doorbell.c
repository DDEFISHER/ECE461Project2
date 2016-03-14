/*
 * doorbell.c
 *
 *  Created on: Mar 14, 2016
 *      Author: daniel
 */
/*
 * adc14.c
 *
 *  Created on: Mar 14, 2016
 *      Author: daniel
 */
#include "msp.h"

#define INT_ADC14_BIT (1<<24)
#define MCLK_FREQUENCY 1500000
#define PWM_PERIOD (MCLK_FREQUENCY/2000)

void bell(unsigned int);

void ring_doorbell()
{
	  uint32_t adcResult, dutyCycle;


	  ADC14CTL0 |= ADC14ENC |ADC14SC ;    // Start sampling/conversion
	  __wfi();                            // alternatively you can also use __sleep();

	  adcResult = ADC14MEM0;
	  dutyCycle = PWM_PERIOD * 8977 / 16384;


	  if (dutyCycle == 0)
		  dutyCycle  = 1;

		  bell(dutyCycle);


}

void bell(unsigned int dutyCycle)
{

	 TA0CCR0 = dutyCycle;                // Change PWM period based on ADC result
	 TA0CCR4 = TA0CCR0 / 2;

   volatile uint32_t i = 100000;

   //delay for bell 
   while(i > 0){
     i--;
   }

   i = 100000;

	 TA0CCR0 = 1;                // Change PWM period based on ADC result
	 TA0CCR4 = TA0CCR0 / 2;

   //delay for bell 
   while(i > 0){
     i--;
   }

	 TA0CCR0 = dutyCycle*2;                // Change PWM period based on ADC result
	 TA0CCR4 = TA0CCR0 / 2;

   i = 100000;

   //delay for bell 
   while(i > 0){
     i--;
   }

   i = 100000;

	 TA0CCR0 = 1;                // Change PWM period based on ADC result
	 TA0CCR4 = TA0CCR0 / 2;

   //delay for bell 
   while(i > 0){
     i--;
   }

	 TA0CCR0 = dutyCycle;                // Change PWM period based on ADC result
	 TA0CCR4 = TA0CCR0 / 2;

   i = 100000;

   //delay for bell 
   while(i > 0){
     i--;
   }

   i = 100000;

	 TA0CCR0 = 1;                // Change PWM period based on ADC result
	 TA0CCR4 = TA0CCR0 / 2;

   //delay for bell 
   while(i > 0){
     i--;
   }



}


