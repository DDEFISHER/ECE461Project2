//*****************************************************************************
// Daniel DeFisher dedefish@ncsu.edu
// MSP432 main.c - ECE461 project 2
//          MSP432p401rpz
//                 ---------------
//                |               |
//                |               |
//          SW1 --|P1.1           |
//          SW2 --|P1.4           |
//   Microphone --|P4.3       P2.7|-->Buzzer
//Ambient light --|P4.6       P2.6|-->RGB RED
//                |           P2.5|-->RGB BLUE
//****************************************************************************

#include "msp.h"
#include "alarm.h"
#include "doorbell.h"
#include "fire_alarm.h"
#include "driverlib.h"
#include "init.h"

unsigned int alarm_status = 0;

//main function that contains allmight while loop then completes the tasks of project 2 based on priority
int main(void)
{
    init();
    
    while (1)
    {

        //fire is first priority call fire alarm if there is a fire
        if( on_fire() ){
            fire_alarm();
        }
        //alarm is second priority call alarm if there is a break in and first event did not happen
        //activate or deactive burglar alarm - last priority
        else if( (P1IN & BIT1 ) == 0){ 

            alarm_status = alarm_button(alarm_status);

        }
        else if( burglar_here() ){
            burglar_alarm();
        }
        //door bell is third priority ring if button is pushed and first two events did not happen
        else if( (P1IN & BIT4 ) == 0){ 

            ring_doorbell();
        }

        MAP_WDT_A_clearTimer(); //service watch dog timer 
    }

}
//clear adc14 interupt flag
void ADC14IsrHandler(void)
{
    ADC14CLRIFGR0 = CLRADC14IFG0;

}
