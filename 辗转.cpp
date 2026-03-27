#include <stdio.h>
#include <math.h>
int main()
{
	int a=40,b=24,gcd;
	for (gcd = a%b; gcd != 0; gcd = a%b)
	{
	a = b;
	b = gcd;
	}
	gcd = b;
	printf("GCD is: %d\n", gcd);
}
