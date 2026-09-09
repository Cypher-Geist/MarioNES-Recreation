/*
 * Switch.c
 *
 *  Created on: Nov 5, 2023
 *      Author:
 */
#include <ti/devices/msp/msp.h>
#include "../inc/LaunchPad.h"
// LaunchPad.h defines all the indices into the PINCM table
void Switch_Init(void){
    // Assumes LaunchPad_Init has been called
    // I.e., PortB has already been reset and activated (do not reset PortB here again)
      // write this
       IOMUX->SECCFG.PINCM[32] = 0x00040081; // GPIO pb16 input Piano Key 0 (lowest frequency) //BUMP Button
       IOMUX->SECCFG.PINCM[42] = 0x00040081; // GPIO pb17 input Piano Key 1 //JUMP BUTTON
       IOMUX->SECCFG.PINCM[43] = 0x00040081; // GPIO pb18 input Piano Key 2 // STOMP Button
       //IOMUX->SECCFG.PINCM[44] = 0x00040081; // GPIO pb19 input Piano Key 3 (highest frequency)

}
// return current state of switches
uint32_t Switch_In(void){
    uint32_t input = 0;
    input = GPIOB->DIN31_0 & 0xF0000; //Bit 17
    return input; // replace this line
}
