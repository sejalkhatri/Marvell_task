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
	
	a = sub(14,4);
	printf("the subtraction is %d\n",a);

	a = mul(6,2);
	printf("the product is %d\n",a);

	a= div(12,4);
	printf("the div is %d\n",a);
}
