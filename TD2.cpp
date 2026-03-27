#include <stdio.h>
int a[2000005]; 
int b[2000005]={0};

int main() 
{
	int n;
	scanf("%d",&n);	
	int x = 0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]==1) 
		{
		    x = x+1; 
		    b[i]=x;
		}
	}
	int m;
	scanf("%d",&m);
	for (int j=0;j<m;j++)
	{
		int k;
		scanf("%d",&k);
		if (k>x)
		{
			printf("No Way!\n");
		}
		else
		{
            for (int p=n;p>=1;p--)
			{
				if (k==x-b[p]+1)
				{
					printf("%d\n",p);
					n=p;
					break;
				}
			}
		}
	}
	return 0;
}
