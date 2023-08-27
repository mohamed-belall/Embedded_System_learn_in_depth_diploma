/*
 * atmega32_register.h
 *
 * Created: 8/26/2023 1:01:01 PM
 *  Author: mohamed belal
 */ 


#ifndef ATMEGA32_REGISTER_H_
#define ATMEGA32_REGISTER_H_


/* ==================== PORTA ==================== */
#define PARTA *((volatile unsigned char *)(0x3B))
#define DDRA  *((volatile unsigned char *)(0x3A))
#define PINA  *((volatile unsigned char *)(0x39))

/* ==================== PORTC ==================== */
#define PARTC *((volatile unsigned char *)(0x35))
#define DDRC  *((volatile unsigned char *)(0x34))
#define PINC  *((volatile unsigned char *)(0x33))

#endif /* ATMEGA32_REGISTER_H_ */