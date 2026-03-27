#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		int n,a1,d;
		scanf("%d %d %d",&n,&a1,&d);
		int a=a1,b=d;
		//可以证明等差数列a1,a1+d,......的所有项的最大公约数就是gcd(a1,d) 
		while(b!=0)
		{
			int t=a%b;
			a=b;
			b=t; 
		}
		printf("%d\n",a);
	}
	return 0;
}
