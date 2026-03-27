#include <stdio.h>

int main()
{
	int n,m,s;
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			s=i*j*(i+j);
			if (j!=m)
			    printf("%d ",s);
			else
			{
				printf("%d\n",s);
			}    
		}
	}
	return 0;
}
