/*
Tutorial for creating your own c library.
https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_C_libraries.html
*/

#include "mathlib.h"

int main()
{
	int a , i , j;

	printf("enter 1st value \n");
	scanf("%d",&i);

	printf("enter 2st value \n");
	scanf("%d",&j);

	a = add(i,j);
	printf("the sum is %d\n",a );
	
	a = sub(i,j);
	printf("the subtraction is %d\n",a);

	a = mul(i,j);
	printf("the product is %d\n",a);

	a= div(i,j);
	printf("the div is %d\n",a);
	
	double b;
	b=pow(i,j);
	printf("the power is %f\n",b);

	b=cos(PI/2);
	printf("the cosine of PI/2 is %f\n",b);
	
	b=sin(PI/2);
	printf("the sine of PI/2  is %f\n",b);

}
