/*
 * doorbell.c - functions for the doorbell
 *
 *  Created on: Mar 14, 2016
 *      Author: Daniel DeFisher
 */
#include "msp.h"
#include "alarm.h"

#define DUTY_CYCLE 410

//ring door bell tone, check in between if bad guy is breaking in (for edge case)
void ring_doorbell()
{

    unsigned int bell_count = 0;
    volatile uint32_t i = 75000;

    for(bell_count = 0; bell_count < 4; bell_count++){

        if( bell_count == 0 || bell_count == 1){
            TA0CCR0 = DUTY_CYCLE*2;                // Change PWM period based on ADC result
        }
        else if( bell_count == 2 || bell_count == 3 ){
            TA0CCR0 = DUTY_CYCLE;                // Change PWM period based on ADC result
        }

        TA0CCR4 = TA0CCR0/2;


        //delay for bell 
        while(i > 0){
         i--;
        }

        if( bell_count == 3 ){

            TA0CCR0 = 1;                // Change PWM period based on ADC result
        }

        sample_mic();
        i = 75000;
    }
}


