//*****************************************************************************
//
// MSP432 main.c template - Empty main
//
//****************************************************************************

#include "msp.h"
#include "stdint.h"
#include "alarm.h"
#include "driverlib.h"

#define INT_ADC14_BIT (1<<24)
#define MCLK_FREQUENCY 1500000
#define PWM_PERIOD (MCLK_FREQUENCY/2000)


int main(void)
{

    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer


    /* GPIO Setup */
    P4SEL1 |= BIT3;                         // Configure P4.3 for ADC mic
    P4SEL0 |= BIT3;

    //P6SEL1 |= BIT0;                         // Configure P6.0 for ADC
    //P6SEL0 |= BIT0;


    P2SEL0 |= BIT7;						    // Configure P2.7 as Timer A PWM output for buzzer
    P2SEL1 &= ~BIT7;
    P2DIR |= BIT7;

    /* Configure TimerA0 */

    //TA0CCR0 = PWM_PERIOD;                   // PWM Period
    TA0CCTL4 = OUTMOD_7;                    // CCR1 reset/set
    //TA0CCR4 = PWM_PERIOD/2;                 // CCR1 PWM duty cycle
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

    while (1)
    {
    	//sample_adc();
      ring_doorbell();
    }

}

void ADC14IsrHandler(void)
{
    /* Clear ADC14 IFG */
    ADC14CLRIFGR0 = CLRADC14IFG0;

}
