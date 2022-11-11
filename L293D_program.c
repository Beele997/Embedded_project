/*
 * L293D_program.c
 *
 *  Created on: Oct 9, 2022
 *      Author: USER
 */
#include"avr/io.h"

#include "../Libraries/stdtypes.h"
#include "../Libraries/ERROR_STATE.h"

#include"../DIO/DIO_interface.h"
#include"L293D_interface.h"
#include"L293D_config.h"
#include"L293D_private.h"

ES_t L293D_enuInit(void){

u8 LocalErrorState= ES_NOK;

// Set them all low to initiate stop state on motor

//DDRC= 0b00000000; // Direction of Inputs of H-Bridge and direction of the Enables


/*********DIRECTION**********/

DDRB = 0xFF;

 //DDRB |= (1<<3); //DIO_enuSetDir(DIO_u8GroupB,DIO_u8Pin3, DIO_u8SetHigh   );
DDRD = 0b11111111;

/*TIMER0 AND TIMER2 INITS*/

MCUCR = ((1<<ISC00)|(1<<ISC01));/* Trigger INT0 on Rising Edge triggered */
TCNT0 = 0;			/* Set timer0 count zero */
TCCR0 = (1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00)|(1<<CS01);/* Set Fast PWM with Fosc/64 Timer0 clock */
TCNT2 = 0;			/* Set timer0 count zero */
TCCR2 = (1<<WGM20)|(1<<WGM21)|(1<<COM21)|(1<<CS20)|(1<<CS21);/* Set Fast PWM with Fosc/64 Timer0 clock */

 /*********Values**********/

LocalErrorState= ES_OK;
	return LocalErrorState;
}


ES_t L293D_enuSetDirection( u8 Copy_u8Direction  ){

u8 LocalErrorState= ES_NOK;


	switch(Copy_u8Direction){
	case(Forward):
		OCR0= 150;
	OCR2 = 150;
	PORTB |= (1<<0);  //IN2
PORTD |=(1<<0); //IN4


	PORTB &=~ (1<<1); //IN1
    PORTD &=~ (1<<1);  //IN3
break;


	case(Backward ):
		OCR0= 150;

      OCR2= 150;
  	PORTB &=~ (1<<0); //IN2
  PORTD &=~(1<<0);  //IN4


      PORTB |= (1<<1);  //IN1

      PORTD |=(1<<1); //IN3
break;}
//  	DIO_enuSetDir(L293D_GroupIN4 , l293d_PinIN4 , DIO_u8SetHigh   );




	LocalErrorState= ES_OK;
			return LocalErrorState;
}

//ES_t L293D_enuSetSpeed(u8 Copy_u8Enable, u8 Copy_u8Speed){ //Analogwrite

	//DDRC= 0b00000000; // Direction of Inputs of H-Bridge
// DDRD= 0b00000000;

/*
 u8 LocalErrorState=ES_NOK;
DDRB &= ~(1<<3);
DDRD &= ~(1<<7);

 DIO_enuSetPinDir( L293D_GroupENA , L293D_PinENA , DIO_u8SetOutput  );
 DIO_enuSetPinDir( L293D_GroupENB , L293D_PinENB , DIO_u8SetOutput  );

 MCUCR = ((1<<ISC00)|(1<<ISC01)); Trigger INT0 on Rising Edge triggered */

 //TCNT0 = 0;			/* Set timer0 count zero */

 //TCCR0 = (1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00)|(1<<CS01);/* Set Fast PWM with Fosc/64 Timer0 clock */
// TCNT2 = 0;			/* Set timer0 count zero */

// TCCR2 = (1<<WGM20)|(1<<WGM21)|(1<<COM21)|(1<<CS20)|(1<<CS21);/* Set Fast PWM with Fosc/64 Timer0 clock */



//if(Copy_u8Enable==EnableA){


/*
 Local_DutyCycle=sqrt((Copy_u8Speed/AVolt));    // Linking/Translating Speed to duty cycle

 	TCCR1A= 0x23;
 	TCCR1B= 0x1C;  // PRESCALAR 256
 //50 Hz and 10 percent duty
 u16 top = (16*1024*1024UL /(50*256UL))-1;
 OCR1AH = (top>>8);   //write high first
 OCR1AL =(u8)top;   //OCRA IS THE TOP BECAUSE COMPARING TO OCRB..WHICH MEANS OCRA IS THE TOP 3AML NFSO TOP..
  u16 ocr = ((top+1)/Local_DutyCycle)-1;
 OCR1BH= (ocr>>8);
 OCR1BL = (u8)ocr;
 */

//OCR0= Copy_u8Speed;
//}
//else if(Copy_u8Enable==EnableB){

/*

OCR2=Copy_u8Speed;


} else LocalErrorState= ES_OUTRANGE;
LocalErrorState= ES_OK;
		return LocalErrorState;

}
*/

 /*else if (Copy_u8Enable==EnableB){
	 DIO_enuSetPin(  L293D_GroupENA , L293D_PinENA, DIO_u8SetLow  );
	 DIO_enuSetPin(  L293D_GroupENB , L293D_PinENB, DIO_u8SetHigh  );

	 Local_DutyCycle=sqrt((Copy_u8Speed/AVolt));    // Linking/Translating Speed to duty cycle

 TCCR1A=0b10000010;
				 TCCR1B=0b00010100;
				  u16 top2 = (16*1024*1024UL /(50*256UL))-1;
				 		 ICR1 = top2;   //write high first
				 		 //OCR1AL =(u8)top;   //OCRA IS THE TOP BECAUSE COMPARING TO OCRB..WHICH MEANS OCRA IS THE TOP 3AML NFSO TOP..
				 		  u16 ocr2 = ((top2+1)/Local_DutyCycle)-1;
				 		 OCR1A= ocr2;
				 		 //OCR1BL = (u8)ocr;
*/
//}






// 1. PWM---> EN
// 2. 2 H-bridge on same MCU



