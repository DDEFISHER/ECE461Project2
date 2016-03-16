/*
 * fire_alarm.c - functions for fire alarm
 *
 *  Created on: Mar 14, 2016
 *      Author: Daniel DeFisher
 */

#include "msp.h"
#include "HAL_I2C.h"
#include "HAL_OPT3001.h"

#define DUTY_CYCLE 410

unsigned int fire = 0;
extern int speed_analysis[5];

//fire alarm tone for buzzer
void fire_alarm()
{
    speed_analysis[3]++;
	 TA0CCR0 = DUTY_CYCLE;                // turn on sound
	 TA0CCR4 = TA0CCR0 / 2;

   volatile uint32_t i = 100000;

   //delay for bell 
   while(i > 0){
       i--;
   }

   i = 100000;

	 TA0CCR0 = 1;                // turn off sound
	 TA0CCR4 = TA0CCR0 / 2;

   //delay for bell 
   while(i > 0){
       i--;
   }

}
//check flux of light sensor and set fire bool based on that
void check_flux()
{

    speed_analysis[4]++;
  float flux = OPT3001_getLux();

  if(fire){
      return;
  }
  if( flux > 2200 ){

      fire = 1;
  }
  else{

      fire = 0;
  }
}
//check if on fire or not
int on_fire()
{

  if(!fire){
      check_flux();
  }
  
  return fire;

}
