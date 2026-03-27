#include <stdio.h>
long long a[105][105];
long long b[105][105];

int main()
{
	int m;
	scanf("%d",&m);
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<m;j++)
		{
			scanf("%lld",&a[i][j]);
		}
		
	}
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<m;j++)
		{
			b[i][j]=a[i][j]+a[j][i];
			printf("%lld ",b[i][j]); 
		}
		printf("\n");
	}
	return 0;			
}
