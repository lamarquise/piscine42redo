#ifndef __FT_BOOLEAN_H__

	#define	__FT_BOOLEAN_H__
	#include <unistd.h>
	#define	EVEN_MSG "J'ai un nombre pair d'arguments.\n"
	#define ODD_MSG "J'ai un nombre impair d'arguments.\n"
	#define SUCCESS 0
	#define EVEN(x)	x % 2 == 0		//ok so if I use "" it fucks up
	#define TRUE 1
	#define FALSE 0
	typedef int t_bool;				//if no ; it fucks up, i think that's cuz typedefs are treated during the compilation, so need proper syntax

#endif
