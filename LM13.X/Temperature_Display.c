/*
    LM-35 Temperature Sensor Interfacing with PIC18f4550
    http://www.electronicwings.com
 
 */

#include <stdio.h>
#include <string.h>
#include <pic18f4550.h>
#include "Configuration_Header_File.h"          /* Header File for Configuration bits */
#include "LCD_16x2_8-bit_Header_File.h"                 /* Header File for LCD Functions */
#include "PIC18F4550_ADC_Header_File.h"

void main()
{    
    char Temperature[10];    
    float celsius;  
    OSCCON=0x72;                /* set internal Oscillator frequency to 8 MHz*/
    LCD_Init();                 /* initialize 16x2 LCD*/
    ADC_Init();                 /* initialize 10-bit ADC*/
    
    while(1)
    {   
        LCD_String_xy(0,0,"Temperature");     
        celsius = (ADC_Read(0)*4.88);
        celsius = (celsius/10.00);
        sprintf(Temperature,"%d C ",(int)celsius);               /* it is used to convert integer value to ASCII string */
        LCD_String_xy(1,0,Temperature);                /* send string data for printing */    
        MSdelay(10);
        memset(Temperature,0,10);
    }
    
}
