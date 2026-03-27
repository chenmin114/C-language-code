#include <stdio.h>

int main() 
{
	int n;
	unsigned int a,b;
	scanf("%d",&n);	
	for(int i=0;i<n;i++)
	{
		scanf("%u",&a);
		b=0;
		for (int j=0;j<32;j++)
		{
			b |= ((a >> j) & 1) << (31 - j);
		}
		printf("%u\n",b);
		
	}
	return 0;
}
