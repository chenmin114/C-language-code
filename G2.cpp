#include <stdio.h>
int main() 
{
	long long n,a,b;
	scanf("%lld",&n);
	if (n == 0)
	    printf("%lld",n);
	if (n > 0)
	    a = n;
	if (n < 0)
	{
	    a = 0 - n;
		printf("-");
	}
	b = a;
	int i=1,c=1;
	while (a >= 10)
	{
	    i++;
		a = a / 10;
	}
	if (b % 10 != 0)	
		 printf("%lld",b % 10);
	int d=c;
	while (d < i)
	{
	    while (d--)
		{
	        b = b / 10;
		}    
	    d = c + 1;
		c++;
		b = b % 10;
		if (b != 0)  
		    printf("%lld",b);
		if (n >= 0)	
		    b = n;
		if (n < 0)
		    b = 0 - n;
	}
	return 0;
}				  
