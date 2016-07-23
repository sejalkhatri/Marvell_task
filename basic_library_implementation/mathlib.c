#include "mathlib.h"

int add(int a , int b)
{
	return a+b;

}
int sub(int a, int b)
{
	return a-b;
}
int mul(int a, int b)
{
	return a*b;
}
int div(int a, int b)
{
	if (b == 0)
		return 0;
	else
		return a/b;
}

double exp(double a)
{
double f=1.00000;

while(a>0)
{f*=e;
a--;}

return f;
}

double pow(double a,double b)
{
double f=1.00000;

while(b>0)
{f*=a;
b--;
}

return f;
}

double factorial(double a)
{
if(a==1)
	return 1;
else
	return a*factorial(a-1);
}

double cos(double a)
{
double c=1;
int i=1;
for(;i<=5;i++)
{
c+=((pow(-1,i)*pow(a,2*i))/factorial(2*i));
}
return c;
}

double sin(double a)
{
double c=a;
int i=1;
for(;i<=5;i++)
{
c+=((pow(-1,i)*pow(a,((2*i)+1)))/factorial((2*i)+1));
}
return c;

}
