#include <stdio.h>
unsigned int F[14000005]={0};


int main() 
{
	int n,q,b;
	unsigned int F0;
	scanf("%d %u %d",&n,&F0,&q);
	for (int i=0;i<q;i++)
	{
		scanf("%d",&b);
		
		for(int j = 1; j <= b; j++) 
		{
			unsigned int x = F[j-1]; 
		    x ^= x << 13;
		    x ^= x >> 17;
		    x ^= x << 5;
		    F[j] = x;
		}
		printf("%u\n",F[i]);
	}
	return 0;
}
