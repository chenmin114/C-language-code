#include<stdio.h>
#include<math.h>

int main()
{
	long long l,x;
	scanf("%lld",&l);
	double L=1.0*l;
	x=(long long)sqrt(L);
	while(1)
	{
		long long sum=(x+1)*x/2;
		if (sum>=l && (sum-l)%2==0)
		{
			break;
		}
		x++;
	}
	printf("%lld",x);
	return 0;
}
