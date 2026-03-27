#include <stdio.h>
long long g(long long n)
{
	if (n <= 1)
	    return 1;
    return n*g(n-1);
}
long long f(long long n)
{
	if (n==1)
	    return 1;
	if ((g(n)+1)%n==0)
	    return 1;  
	return 0;   
}
int main()
{
	long long n,count=0;
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)
	{
		if (f(i)==1)
		    count++;
	}
	printf("%lld",count);
	return 0;
}
