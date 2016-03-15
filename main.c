//*****************************************************************************
// Daniel DeFisher dedefish@ncsu.edu
// MSP432 main.c - ECE461 project 2
//          MSP432p401rpz
//                 ---------------
//                |               |
//                |               |
//   bell buton --|P1.1           |
//    Alarm set --|P1.4           |
//   Microphone --|P4.3       P2.7|-->Buzzer
// Ambiet light --|P4.6       P2.6|-->RGB RED
//                |           P2.5|-->RGB BLUE
//****************************************************************************

#include "msp.h"
#include "alarm.h"
#include "doorbell.h"
#include "fire_alarm.h"
#include "driverlib.h"
#include "init.h"

unsigned int alarm_status = 0;

#define INT_ADC14_BIT (1<<24)

int main(void)
{
    init();
    
    while (1)
    {

        if( on_fire() ){
            fire_alarm();
        }
        else if( alarm_status && burglar_here() ){
            burglar_alarm();
        }
        else if( (P1IN & BIT4 ) == 0){ 

            ring_doorbell();
        }
        else if( (P1IN & BIT1 ) == 0){ 

            alarm_status = alarm_button(alarm_status);

        }

        MAP_WDT_A_clearTimer(); 
    }

}
void ADC14IsrHandler(void)
{
    /* Clear ADC14 IFG */
    ADC14CLRIFGR0 = CLRADC14IFG0;

}
