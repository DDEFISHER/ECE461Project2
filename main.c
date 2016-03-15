//*****************************************************************************
//
// MSP432 main.c template - Empty main
//
//****************************************************************************

#include "msp.h"
#include "stdint.h"
#include "alarm.h"
#include "doorbell.h"
#include "driverlib.h"
#include "HAL_I2C.h"
#include "HAL_OPT3001.h"

#define INT_ADC14_BIT (1<<24)

int main(void)
{

    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer


    /* GPIO Setup */
    P4SEL1 |= BIT3;                         // Configure P4.3 for ADC mic
    P4SEL0 |= BIT3;

    //set up switch 1
    P1DIR &= ~BIT1;			// make P1.1 and input
    P1REN |= BIT1;			// enable pull resistor on P1.1
    P1OUT |= BIT1;			// make it a pull-up resistor

    //set up switch 2
    P1DIR &= ~BIT4;			// make P1.4 and input
    P1REN |= BIT4;			// enable pull resistor on P1.4
    P1OUT |= BIT4;			// make it a pull-up resistor

    //set up LED1 and LED2
    P1OUT &= ~BIT0;     //start off
    P2OUT &= ~BIT1;     //start off
    P1DIR |= BIT0;			// make P1.0 an output
    P2DIR |= BIT1;			// make P2.1 an output

    P2SEL0 |= BIT7;						    // Configure P2.7 as Timer A PWM output for buzzer
    P2SEL1 &= ~BIT7;
    P2DIR |= BIT7;

    /* Configure TimerA0 */

    TA0CCTL4 = OUTMOD_7;                    // CCR1 reset/set
    TA0CTL = TASSEL__SMCLK | MC__UP | TACLR;  // SMCLK, up mode, clear TAR

    /* Configure ADC14
     * Sampling time, S&H=96, ADC14 on
     * Use sampling timer, 14-bit conversion results
     */
    ADC14CTL0 = ADC14SHT0_5 | ADC14SHP |  ADC14SSEL_1 | ADC14ON ;
    ADC14CTL1 = ADC14RES_3;

    ADC14MCTL0 |= ADC14INCH_10;             // A10 ADC input select; Vref=AVCC
    ADC14IER0 |= ADC14IE0;                  // Enable ADC conv complete interrupt

    NVIC_ISER0 |= INT_ADC14_BIT;         // Enable ADC interrupt in NVIC module

    __enable_interrupt();                   // Enable NVIC global/master interrupt
    SCB_SCR &= ~SCB_SCR_SLEEPONEXIT;        // Wake up on exit from ISR

    /* Initialize I2C communication */
    Init_I2C_GPIO();
    I2C_init();

    /* Initialize OPT3001 digital ambient light sensor */
    OPT3001_init();


    //variable to store ambient light lux in
    float lux;

    while (1)
    {
        lux = OPT3001_getLux();

        if( lux > 200 ){
        }
        else if( burglar_here() ){
          burglar_alarm();
        }
        else if( (P1IN & BIT4 ) == 0){

        P2OUT |= BIT1;//turn on led2     
        ring_doorbell();
        }

        sample_mic();
    }

}

void ADC14IsrHandler(void)
{
    /* Clear ADC14 IFG */
    ADC14CLRIFGR0 = CLRADC14IFG0;

}
