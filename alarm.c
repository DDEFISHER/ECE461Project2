/*
 * alarm.c - functions for burglar alarm 
 *
 *  Created on: Mar 14, 2016
 *      Author: Daniel DeFisher
 */
#include "msp.h"

#define DUTY_CYCLE 410

extern unsigned int alarm_status;
unsigned int badguy_here = 0;

//sample the mic with adc14 and set if bad guy is here
void sample_mic()
{

    if(!alarm_status){

        return;
    }

	  ADC14CTL0 |= ADC14ENC |ADC14SC ;    // Start sampling/conversion
	  __wfi();                            // alternatively you can also use __sleep();

	  if(ADC14MEM0 > 9000){
        badguy_here = 1;
	  }

}
//check if bad_guy was already here or is here now
int burglar_here()
{
    if(badguy_here){
        return 1;
    }

    sample_mic();

    if(badguy_here){
        return 1;
    }
    else{
        return 0;
    }
}
//set buzzer to alarm tone
void burglar_alarm()
{
   TA0CCR0 = DUTY_CYCLE*3;                // Change PWM period based on ADC result
	 TA0CCR4 = TA0CCR0 / 2;

}
//activate and deactive alarm with button and display on RGB led the status
unsigned int alarm_button(unsigned int alarm_status)
{

    if( alarm_status ){
        P2OUT &= ~BIT4;//turn off green rgb     
        P2OUT |= BIT6;//turn on red rgb
        alarm_status = 0;
        badguy_here = 0;
        TA0CCR0 = 1;                // Change PWM period based on ADC result
    }
    else{
        P2OUT &= ~BIT6;//turn off red rgb     
        P2OUT |= BIT4;//turn on green rgb
        alarm_status = 1;
        badguy_here = 0;
    }

    unsigned int i;

    for(i = 0; i < 100000;i++);

    return alarm_status;

}
