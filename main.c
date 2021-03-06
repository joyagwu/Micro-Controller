/* Main.c file generated by New Project wizard
 *
 * Created:   Sat Sep 26 2015
 * Processor: PIC16F84A
 * Compiler:  MPLAB XC8
 */

#include <xc.h>

void main(void)
 {
   // Write your code here
   while (1)
      ;
 processor 16F873A ; Declaration of microcontroller configuration
#include "P16F873A.Inc"
_CONFIG_CP_OFF&_WDT_OFF&PWRITE_ON&_HS_OSC&DEBUG_ON&_LVP_OFF
; Declaration of variables 
CBLOCK 0x0c
d1
d2
d3
Endc ; no variabes 
; Program Memory Structure
ORG 0x00 ; Reset Vector
goto Main ; Afte reset jump to location
ORG 0x04 ; Interrupt 
goto Main ; no interrupt routine
Main: banksel Tris B ; Select the bank containing Tris B
      clrf    Tris B ; port B is output
      banksel Port B ; select the bank containing port B
      clrf    Port B ; clear port B
Loop: call    delay_1second ; call subroutine 
      comd    port B ; compliment port B (logical Not)
      goto    loop   ; loop
; loop for 1 million instruction cycles
     delay_1second   ; 1999996 cycles
     Movlw 0x11
     Movwf d1
     Movlw 0x5D
     Movlw d2
     Movwf d3
Delay_0
     decfs2 d2,f
     goto $ + 2
     decfs2 d2,f
     goto $ + 2
     decfs2 d3,f
     goto Delay,0 ; 4 cycles
   
     goto $ +1
     goto $ + 1
     Return
     END
  

   }
 