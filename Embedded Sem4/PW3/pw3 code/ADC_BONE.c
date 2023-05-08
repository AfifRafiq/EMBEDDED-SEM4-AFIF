/*******************************************************************************
* This file provides the functions for the ADC module 
*
* Cytron Technologies Sdn. Bhd.
*******************************************************************************/
// This file is written for PIC16F887, if other model of PIC is uses, please modify accordingly

#include <p18f4580.h>
//#include "system.h"
#include "adc.h"

#define	_XTAL_FREQ	20000000

void MSDelay (unsigned int itime);
/*******************************************************************************
* PUBLIC FUNCTION: adc_initialize
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Initialize the ADC module.
*
*******************************************************************************/
void adc_init(void)
{
	ADCON1 = 0x0B;  // Vref- = Vss; Vref+ = VDD; AN3-AN0 for Analog 
	ADCON0 = 0x81;	// select AN0, OFF converter
	ADCON2 = 0x8A;  // right justified will take as 10-bit ADC,Acquisition Time = 2TAD, A/D Conversion Clock = FOSC/32.
}

	
/*******************************************************************************
* PUBLIC FUNCTION: adc_on
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Activate ADC module
*
*******************************************************************************/
void adc_on(void)
{
	// Turn On ADC module
	ADCON0bits.ADON=1;
}




/*******************************************************************************
* PUBLIC FUNCTION: adc_off
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Deactivate ADC module
*
*******************************************************************************/
void adc_off(void)
{
	// Turn Off ADC module, to save power
	ADCON0bits.ADON=0;
}



/*******************************************************************************
* PUBLIC FUNCTION: ui_adc_read
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ The ADC result in 16-bit
*
* DESCRIPTIONS:
* Convert and read the result of the ADC from ANO.
*
*******************************************************************************/
unsigned int ui_adc_read(void)
{
	unsigned int pot = 0;

	ADCON0bits.ADON=1;
	MSDelay(1);
	ADCON0bits.GO=1; 
	while(ADCON0bits.DONE) continue;
	pot = (unsigned int)ADRESH << 8;
	pot = pot + ADRESL;
	return pot;
}	

void MSDelay (unsigned int itime)
{
	unsigned int i;
    unsigned int j;
	for (i=0; i<itime; i++)
	for (j=0; j<165; j++);
}

