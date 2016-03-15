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
#include "alarm.h"

#define DUTY_CYCLE 410

void ring_doorbell()
{

    unsigned int bell_count = 0;

    for(bell_count = 0; bell_count < 5; bell_count++){

        if( bell_count == 0 ){
            TA0CCR0 = DUTY_CYCLE;                // Change PWM period based on ADC result
        }
        else if( bell_count == 1 ){
            TA0CCR0 = 1;                // Change PWM period based on ADC result
        }
        else if( bell_count == 2 ){
            TA0CCR0 = DUTY_CYCLE*2;                // Change PWM period based on ADC result
        }
        else if( bell_count == 3 ){
            TA0CCR0 = 1;                // Change PWM period based on ADC result
        }
        else if( bell_count == 4 ){
            TA0CCR0 = DUTY_CYCLE;                // Change PWM period based on ADC result
        }

        TA0CCR4 = TA0CCR0 / 2;  //square wave

        volatile uint32_t i = 100000;

        //delay for bell 
        while(i > 0){
         i--;
        }

        if( bell_count == 4 ){

            TA0CCR0 = 1;                // Change PWM period based on ADC result
        }

        sample_mic();
        i = 100000;
    }
}


