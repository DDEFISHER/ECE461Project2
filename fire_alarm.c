/*
 * fire_alarm.c
 *
 *  Created on: Mar 14, 2016
 *      Author: daniel
 */

#include "msp.h"

#define DUTY_CYCLE 410

void fire_alarm()
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

}
int check_flux()
{

  float lux = OPT3001_getLux();

  if( lux > 200 ){
    return 1;
  }
  else{
    return 0;
  }

}
