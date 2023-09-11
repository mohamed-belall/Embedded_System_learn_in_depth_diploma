/*
 * bitwise.h
 *
 * Created: 8/26/2023 12:58:23 PM
 *  Author: mohamed belal
 */ 


#ifndef BITWISE_H_
#define BITWISE_H_

#define SETBIT(register,bit)      (register |= (1<<bit))
#define CLEARBIT(register,bit)    (register &= ~(1<<bit))
#define TOGGLEBIT(register,bit)   (register ^= (1<<bit))
#define READBIT(register,bit)     ((register >> bit )&1)



#endif /* BITWISE_H_ */