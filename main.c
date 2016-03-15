//*****************************************************************************
//
// MSP432 main.c template - Empty main
//
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
    
    //variable to store if fire happened
    unsigned int fire = 0;

    while (1)
    {

        if( fire ){
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

        //check noise level if alarm active
        sample_mic();

        //if a fire has not happened then check the flux level
        if( !fire ){
        fire = check_flux();
        }
        
        MAP_WDT_A_clearTimer(); 
    }

}
void ADC14IsrHandler(void)
{
    /* Clear ADC14 IFG */
    ADC14CLRIFGR0 = CLRADC14IFG0;

}
