/*
 * macroes.h
 *
 * Created: 1/27/2020 9:19:10 AM
 *  Author: Eng_omar
 */ 


#ifndef MACROES_H_
#define MACROES_H_
	#define SETBIT(R,B)			((R) |= (1<<(B)))
	#define CLEARBIT(R,B)		((R) &=~(1<<(B)))
	#define TOGGLEBIT(R,B)		((R) ^= (1<<(B)))
	#define READBIT(R,B)		(((R) & (1<<(B)))>>(B))
	/*the READBIT macro is very important as it returns zero or one,because
	  after the & operation with 1 the result will be zero or another number
	  but we left shifted the result to the sirtst bit to give us zero or one
	  only*/



#endif /* MACROES_H_ */