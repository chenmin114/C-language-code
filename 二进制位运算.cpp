#include <stdio.h>

int main() 
{
    long long a,b;
    while (~scanf("%lld %lld",&a,&b))
	{
		long long n = 0,m = 1;
		for (int i =0;i < 63;i++)
		{
			int a1 = (a & m)!=0;
			int b1 = (b & m)==0;
			if (a1 && b1)
			{
				n |= m;
			}
			m <<=1;
		}
		printf("%lld\n",n);
	} 
	return 0;
}    
