#include <stdio.h>

int main() 
{
	long long a1,b1,a,b;
	long long lcm;
	scanf("%lld %lld",&a1,&b1);
	a=a1,b=b1;
	while (b!=0)
	{
		int t=a%b;
		a =b;
		b=t;
	}
	lcm =(a1 * b1)/a;
	printf("%lld",lcm);
	return 0; 
}	
