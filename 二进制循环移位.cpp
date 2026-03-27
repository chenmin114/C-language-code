#include <stdio.h>

int main()
{
	int N,k;
	unsigned long long a;
	while (scanf("%d %d %llu",&N,&k,&a)!=EOF)
	{
		unsigned long long x = a,m;
			m = (x >> (N-k))&((1 << k)-1);
			x = (x << k)&((1 << N)-1);
			x = x | m;
		printf("%llu\n",x);
	} 
	return 0;
} 
