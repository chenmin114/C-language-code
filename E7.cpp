#include <stdio.h>
#include <string.h>
int a[10005]={0};

int main()
{
	int n,count=0;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=0;i<n;i++)
	{
		unsigned char *p=(unsigned char *)&a[i];
		for (int j=0;j<4;j++)
		{
			if (p[j]==114)
			{
				count++;
			}
		}
		
	}
	printf("%d",count);
	return 0;
}
