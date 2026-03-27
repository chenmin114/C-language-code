#include <stdio.h>

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for (int i=0;i<n;i++)
	{
		for (int r=0;r<k;r++)
		{
			for (int j=0;j<n;j++)
			{
				for (int c=0;c<k;c++)
				{
				    printf("%c",(i+j)%2==0 ? '1' : ' '); 
				}
			}
			printf("\n");
		}
	}
	return 0;
}
