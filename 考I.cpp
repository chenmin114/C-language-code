#include <stdio.h>
int h[1005][005];
int a[1005][1005]={0};
int n,m;
int count=1;

int f(int x,int y)
{
	if (x<0 || x>=n || y<0 || y>=n) return 0;
    if (x<n-1 &&h[x+1][y]>h[x][y] && a[x+1][y]==0)
    {
		count++;
		a[x+1][y]=1;
	}
	if (x>0 &&h[x-1][y]>h[x][y]&&a[x-1][y]==0)
	{
		count++;
		a[x-1][y]==1;
	}
	if (y<n-1 &&h[x][y+1]>h[x][y]&&a[x][y+1]==0)
	{
		count++;
		a[x][y+1]==1;
	}
	if (y>0 &&h[x][y-1]>h[x][y]&&a[x][y-1]==0)
	{    
		count++;
		a[x][y-1]==1;
	}
	count+=f(x+1,y)+f(x-1,y)+f(x,y+1)+f(x,y-1);
	return count;
}

int main()
{
	int n,m,x,y;
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			scanf("%d",&h[i][j]);
		}
	}
	scanf("%d",&x,&y);
	a[x][y]=1;
	printf("%d",count);
	return 0;
	
}
