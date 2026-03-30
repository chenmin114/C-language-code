#include <stdio.h>
int p[1000005];

int find(int x)
{
	if (p[x]!=x)
	{
		int px=p[x];
		return find(px);
	}
	return p[x];
}
void he(int x,int y)
{
	int px=find(x);
	int py=find(y);
	p[py]=px;
}

int main()
{
	int m,n,k,x,y;
	scanf("%d %d",&m,&n);
	for (int i=0;i<=m*n;i++)
	{
		p[i]=i;
	}
	scanf("%d",&k);
	while (k--)
	{
		scanf("%d %d",&x,&y);
		he(x,y);
	}
	int sum=0;
	for (int i=1;i<=m*n;i++)
	{
		if (p[i]==i)
		{
			sum++;
		}
	}
	printf("%d",sum);
	return 0;
}

