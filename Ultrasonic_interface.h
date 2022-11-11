/*
******************* Date    : 10/11/2022               *********************************
******************* Name    : Ahmed & Fares            *********************************
******************* Version : 3.0                      *********************************
******************* SWC     : Ultrasonic_interface.h   *********************************
*/

#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_




ES_t Ultrasonic_enuInit(void);
ES_t Ultrasonic_enuTrigger(void);

int Ulterasonic_enuGetPulseWidth(void);


#endif /* ULTRASONIC_INTERFACE_H_ */
