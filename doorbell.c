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

#define DUTY_CYCLE 410

void ring_doorbell()
{

	 TA0CCR0 = DUTY_CYCLE;                // Change PWM period based on ADC result
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

	 TA0CCR0 = DUTY_CYCLE*2;                // Change PWM period based on ADC result
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

	 TA0CCR0 = DUTY_CYCLE;                // Change PWM period based on ADC result
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


