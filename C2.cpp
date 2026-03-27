#include<stdio.h>

int main()
{
	int x0,y0,vx,vy,t,x1,y1;
	scanf("%d%d",&x0,&y0);
	scanf("%d%d",&vx,&vy);
	scanf("%d",&t);
	x1 = x0 + vx * t;
	y1 = y0 + vy * t;
	printf("%d %d",x1,y1);
	return 0;
}	
