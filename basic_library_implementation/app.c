/*
Tutorial for creating your own c library.
https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_C_libraries.html
*/

#include "mathlib.h"

int main()
{
	int a;
	a = add(5,6);
	printf("the sum is %d\n",a );
}