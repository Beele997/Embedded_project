/*
******************* Date    : 5/11/2022              *********************************
******************* Name    : Ahmed & Fares          *********************************
******************* Version : 3.0                    *********************************
******************* SWC     : L293D_Config.h         *********************************
*/

#ifndef L293D_CONFIG_H_
#define L293D_CONFIG_H_



#define L293D_GroupENA     DIO_u8GroupB
#define L293D_PinENA       DIO_u8Pin3

#define L293D_GroupENB     DIO_u8GroupD
#define L293D_PinENB       DIO_u8Pin7

#define L293D_GroupIN1     DIO_u8GroupB
#define L293D_PinIN1       DIO_u8Pin0

#define L293D_GroupIN2     DIO_u8GroupB
#define L293D_PinIN2       DIO_u8Pin1

#define L293D_GroupIN3     DIO_u8GroupD
#define L293D_PinIN3       DIO_u8Pin0

#define L293D_GroupIN4     DIO_u8GroupD
#define L293D_PinIN4       DIO_u8Pin1


#define Right              7
#define Left               6
#define Forward            5
#define Backward           4

#define EnableA            100
#define EnableB            101

#define AVolt              5

#define CH1                151
#define CH2                155
#define Motor1             144
#define Motor2             145

#endif /* L293D_CONFIG_H_ */
