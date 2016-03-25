
#include "interruptvectors.h"

#ifndef F_CPU
#define F_CPU 16000000
#endif

#include <avr/interrupt.h>
#include "../usart/usart.h"
#include "../utils/bit_tools.h"

volatile uint8_t nReceivedBytes;
volatile char  usartBuffer[USART_BUFFER_LENGHT];
volatile  uint8_t flagNewMessage;
//extern uint8_t flagTimerReadSensors=0;
//extern uint8_t flagTimerFireSensors=0;



volatile uint16_t timerCount=0; 
#define SCHEDULER_BASE_PERIOD 0.1
#define SCHEDULER_MAX_COUNT 60/SCHEDULER_BASE_PERIOD


/************************************************************************/
/* @Clear Buffer                                                        */
/************************************************************************/
void clearBuffer(void){
	uint8_t i;
	for(i=0; i< USART_BUFFER_LENGHT; i++) usartBuffer[i]=0;

}

/************************************************************************/
/* INTERRUPT HANDLER ACCORDING 128 MANUAL ORDER                                                                     */
/************************************************************************/




/************************************************************************/
/* EXTERNAL INTERRUPTS                                                                     */
/************************************************************************/

/************************************************************************/
/* handler External Interrupt Request 0                                                                     */
/************************************************************************/
ISR(INT0_vect){
	
}


/************************************************************************/
/* handler External Interrupt Request 1                                                                   */
/************************************************************************/
ISR(INT1_vect){
	
}


/************************************************************************/
/* handler External Interrupt Request 2                                                                    */
/************************************************************************/
ISR(INT2_vect){
	
}


/************************************************************************/
/* handler External Interrupt Request 3                                                                    */
/************************************************************************/
ISR(INT3_vect){
	
}


/************************************************************************/
/* handler External Interrupt Request 4                                                                   */
/************************************************************************/
ISR(INT4_vect){
	
}

/************************************************************************/
/* handler External Interrupt Request 5                                                                    */
/************************************************************************/
ISR(INT5_vect){
	
}


/************************************************************************/
/* handler External Interrupt Request 6                                                                  */
/************************************************************************/
ISR(INT6_vect){
	
}


/************************************************************************/
/* handler External Interrupt Request 7                                                                   */
/************************************************************************/
ISR(INT7_vect){
	
}




/************************************************************************/
/* TIMER INTERRUPTS                                                                   */
/************************************************************************/

/************************************************************************/
/* handler Timer/Counter2 Compare Match                                                                  */
/************************************************************************/
ISR(TIMER2_COMP_vect){
	
}


/************************************************************************/
/* handler Timer/Counter2 Overflow                                                                 */
/************************************************************************/
ISR(TIMER2_OVF_vect){
	
	
	
}


/************************************************************************/
/* handler Timer/Counter1 Capture Event                                                               */
/************************************************************************/
ISR(TIMER1_CAPT_vect){
	
}


/************************************************************************/
/* handler Timer/Counter1 Compare Match A                                                              */
/************************************************************************/
ISR(TIMER1_COMPA_vect){
	
}


/************************************************************************/
/* handler Timer/Counter1 Compare Match B                                                             */
/************************************************************************/
ISR(TIMER1_COMPB_vect){
	
}


/************************************************************************/
/* handler Timer/Counter1 Overflow                                                            */
/************************************************************************/
ISR(TIMER1_OVF_vect){
	
}

extern uint16_t schedulerMaxCount;

// Task periocity 1ms base tick
extern uint16_t taskReadButtonsPeriod;
extern uint16_t taskReadSensorsPeriod;
extern uint16_t taskStateUpdatePeriod;
extern uint16_t taskLcdPeriod;
extern uint16_t taskUpdateOutputPeriod;
extern uint16_t taskBlinkLightsPeriod;

// flag
extern uint8_t flagTaskReadButtons;
extern uint8_t flagTaskReadSensors;
extern uint8_t flagTaskStateUpdate;
extern uint8_t flagTaskLcd;
extern uint8_t flagTaskUpdateOutputs;
extern uint8_t flagTaskBlinkLights;

extern uint8_t flagTaskUsartMessage;

/************************************************************************/
/* handler Timer/Counter0 Compare Match                                                           */
/************************************************************************/
ISR(TIMER0_COMP_vect){
	
		static uint16_t tickCounter;
		// scheduling period
		// control enabled
		tickCounter++;
		
		if(tickCounter % taskReadButtonsPeriod == 0) flagTaskReadButtons++;
		if(tickCounter % taskReadSensorsPeriod == 0) flagTaskReadSensors++;
		if(tickCounter % taskStateUpdatePeriod == 0) flagTaskStateUpdate++;
		if(tickCounter % taskLcdPeriod ==0 )flagTaskLcd++;
		if(tickCounter % taskBlinkLightsPeriod == 0) flagTaskBlinkLights++;
		if(tickCounter % taskUpdateOutputPeriod == 0) flagTaskUpdateOutputs++;
		
		
		// reload values // deve dar uns 5segundos
		if(tickCounter > schedulerMaxCount) tickCounter=0;
	
}


/************************************************************************/
/* handler Timer/Counter0 Overflow     CHECK                            */
/************************************************************************/
ISR(TIMER0_OVF_vect){
		
}



/************************************************************************/
/* SERIALS INTERRUPT                                                                   */
/************************************************************************/

/************************************************************************/
/* handler SPI Serial Transfer Complete                                                         */
/************************************************************************/
ISR(SPI_STC_vect){
	
}


/************************************************************************/
/* handler USART0, Rx Complete                                                        */
/************************************************************************/
ISR(USART0_RX_vect){
	char c;
	c =USART0_receiveChar();
	// manda caracter para usart 0
	USART1_sendChar(c);
}


/************************************************************************/
/* handler USART0 Data Register Empty                                                       */
/************************************************************************/
ISR(USART0_UDRE_vect){

}


/************************************************************************/
/* handler USART0, Tx Complete                                                       */
/************************************************************************/
ISR(USART0_TX_vect){

}





/************************************************************************/
/* ANALOG CONVERTER                                                                   */
/************************************************************************/

/************************************************************************/
/* handler ADC Conversion Complete                                                    */
/************************************************************************/
ISR(ADC_vect){

}




/************************************************************************/
/* EEPROM                                                                   */
/************************************************************************/

/************************************************************************/
/* handler EEPROM Ready                                                   */
/************************************************************************/
ISR(EE_READY_vect){

}


/************************************************************************/
/* ANALOG COMPARATOR                                                                   */
/************************************************************************/

/************************************************************************/
/* handler Analog Comparator                                                  */
/************************************************************************/
ISR(ANALOG_COMP_vect){

}



/************************************************************************/
/* TIMER INTERRUPTS                                                                */
/************************************************************************/

/************************************************************************/
/* handler  Timer/Counter1 Compare Match C                                               */
/************************************************************************/
ISR(TIMER1_COMPC_vect){

}


/************************************************************************/
/* handler Timer/Counter3 Capture Event                                             */
/************************************************************************/
ISR(TIMER3_CAPT_vect){

}


/************************************************************************/
/* handler Timer/Counter3 Compare Match A                                             */
/************************************************************************/
ISR(TIMER3_COMPA_vect){

}


/************************************************************************/
/* handler Timer/Counter3 Compare Match B                                             */
/************************************************************************/
ISR(TIMER3_COMPB_vect){

}


/************************************************************************/
/* handler Timer/Counter3 Compare Match C                                           */
/************************************************************************/
ISR(TIMER3_COMPC_vect){

}


/************************************************************************/
/* handler Timer/Counter3 Overflow                                           */
/************************************************************************/
ISR(TIMER3_OVF_vect){

}




/************************************************************************/
/* SERIAL INTERRUPTS                                                                */
/************************************************************************/

/************************************************************************/
/* handler USART1, Rx Complete                                                                    */
/************************************************************************/
ISR(USART1_RX_vect){
	char c;

	
	c =USART1_receiveChar();
	USART0_sendChar(c); // reply with received char
	if(c== MSG_END_CARACTER){
		nReceivedBytes=0;
		flagNewMessage=1;
		return;
	}
	// save caracter to buffer
	usartBuffer[nReceivedBytes]=c;
	nReceivedBytes++;

	// test if buffer underrun	
	if(nReceivedBytes> USART_BUFFER_LENGHT+1){
		nReceivedBytes=0;
		clearBuffer();
	}
}


/************************************************************************/
/* handler USART1 Data Register Empty                                          */
/************************************************************************/
ISR(USART1_UDRE_vect){

}


/************************************************************************/
/* handler USART1, Tx Complete                                         */
/************************************************************************/
ISR(USART1_TX_vect){

}


/************************************************************************/
/* handler Two-wire Serial Interface                                       */
/************************************************************************/
ISR(TWI_vect){

}


/************************************************************************/
/* handler Store Program Memory Ready                                       */
/************************************************************************/
ISR(SPM_READY_vect){

}

