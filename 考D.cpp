#include <stdio.h>
int a[1005][1005];


int main()
{
	int t,x,y;
	scanf("%d",&t);
	while (t--)
	{
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				scanf("%d",&a[i][j]);
				if (a[i][j]==2)
				{
					x=i,y=j;
				}
			}
		}
	
	int count=0;
	for (int i=x-1;i>0;i--)
	{
		if (i==0 || a[i][y]==1)
		    count++;
		count++;    
	}
	for (int i=x+1;i<=n;i++)
	{
		if (i>n || a[i][y]==1)
			break;
		count++;    
	}
	for (int i=y-1;i>0;i--)
	{
		if (i==0 || a[x][i]==1)
		    break;
		count++;    
	}
    for (int i=y+1;i<=n;i++)
	{
		if (i>n || a[x][i]==1)
			break;
		count++;    
	}
    for (int i=1;i<=n;i++)
    {
		if (x-i==0 || y-i==0 ||a[x-i][y-i]==1)
		    break;
		count++;
    }    
    for (int i=1;i<=n;i++)
    {
		if (x+i>n || y+i>n ||a[x+i][y+i]==1)
		    break;
		count++;
    } 
    for (int i=1;i<=n;i++)
    {
		if (x-i==0 || y+i>n ||a[x-i][y+i]==1)
		    break;
		count++;
    } 
    for (int i=1;i<=n;i++)
    {
		if (x+i>n || y-i==0 || a[x+i][y-i]==1)
		    break;
		count++;
    } 
	printf("%d\n",count);
	}
	return 0;
}
