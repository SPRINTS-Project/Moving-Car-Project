
#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include <avr/io.h>

/* External Interrupt Request 0 */
#define EXT_INT_0	__vector_1

/* External Interrupt Request 1 */
#define EXT_INT_1	__vector_2

/* External Interrupt Request 2 */
#define EXT_INT_2	__vector_3


// Interrupt Service Routine
#define ISR(INT_VECT)	void INT_VECT(void)	__attribute__ ((signal,used));\
void INT_VECT(void)


// Enable Global Interrupts
#define ENABLE_GLOBAL_INTERRUPTS()		__asm__ __attribute__ ("sei" ::: "memory")


// Disable Global Interrupts
#define DISABLE_GLOBAL_INTERRUPTS()		__asm__ __attribute__ ("cli" ::: "memory")




