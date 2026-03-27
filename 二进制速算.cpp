#include <stdio.h>

int main() 
{
	int n;
	scanf("%d",&n);	
		
	for(int i=0;i<n;i++)
	{
		long long a;
		scanf("%lld",&a);
		int b[64];
		for (int j = 0;j < 64;j++)
		{
			int h = 63 - j; 
			b[j] = (a >> h) & 1;
		}
		for (int k = 0;k < 64;k++)
		{
			printf("%d",b[k]);
			if ((k + 1) % 4 == 0 && k!= 63)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
