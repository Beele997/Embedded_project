/*
******************* Date    : 10/11/2022             *********************************
******************* Name    : Ahmed & Fares          *********************************
******************* Version : 3.0                    *********************************
******************* SWC     : Ultrasonic_private.h   *********************************
*/


#ifndef ULTRASONIC_PRIVATE_H_
#define ULTRASONIC_PRIVATE_H_



/*****************SENSOR PORT GROUPS******/


#define   Trigger_Group       DIO_u8GroupC
#define   Echo_Group          DIO_u8GroupC


/*******SENSOR PINS****/

#define   Trigger_Pin         DIO_u8Pin0
#define   Echo_Pin            DIO_u8Pin1

/**********POSITIONS*******/

#define US_TRIG_POS	PC0
#define US_ECHO_POS	PC1

#define US_PORT PORTC           // we have connected the Ultrasonic sensor on port C. to use the ultrasonic we need two pins of the ultrasonic to be connected on port C
#define	US_PIN	PINC            // we need to initialize the pin resistor when we want to take input.
#define US_DDR 	DDRC
/********ERROR HANDLERS******/

#define US_ERROR		      -1
#define	US_NO_OBSTACLE        -2

#define TCNT1L                *((volatile u8*)0x4C)
#define TCNT1H                *((volatile u8*)0x4D)


#endif /* ULTRASONIC_PRIVATE_H_ */
