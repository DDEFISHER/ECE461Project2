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

void alarm(unsigned int);

void sample_adc()
{
	  uint32_t adcResult, dutyCycle;
	  volatile uint32_t i;


	  ADC14CTL0 |= ADC14ENC |ADC14SC ;    // Start sampling/conversion
	  __wfi();                            // alternatively you can also use __sleep();

	  adcResult = ADC14MEM0;
	  dutyCycle = PWM_PERIOD * 8977 / 16384;


	  if (dutyCycle == 0)
		  dutyCycle  = 1;

	  if(ADC14MEM0 > 9000)
	  {
		  alarm(dutyCycle);
	  }


}

void alarm(unsigned int dutyCycle)
{
	 TA0CCR0 = dutyCycle;                // Change PWM period based on ADC result
	 TA0CCR4 = TA0CCR0 / 2;

}
