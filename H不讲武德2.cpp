#include <stdio.h>
#define ll long long

void write(ll n)
{
	if (n/9)
	    write(n/9);
	int m=n%9;
	if (m<5)
	    putchar('0'+m);
	else
		putchar('0'+m+1);    
}
int main(void)
{
	ll n;
	while (scanf("%lld",&n)!= EOF)
	{
		write(n);
		putchar('\n');
	}
	return 0;
}
