#include <stdio.h>
long long n,d;

long long f(long long a)
{
	if (a%2==0) return d+(a/2)*(n^d);
	if (a%1==0) return d*(d-1)+((a+1)/2)*(n^d);
}

long long g(long long n)
{
    return (n*(n+1)/2)*d*(d+1)+d*(1-2*n);
}

int main()
{
	while (scanf("%lld %lld",&n,&d)!=EOF)
	{
		printf("%lld ",f(n));
		printf("%lld\n",g(n));
	} 
	return 0;
}
