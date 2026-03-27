#include <stdio.h>
int c(int a,int b)
{
	if (b == a)
	    return 1;
	if (b < 0 || b > a)
	    return 0;
	int x=1,y=1;
	for (int i=1;i<=b;i++)
	{
		x *= (a-b+i);
		y *= i;
	} 
	return x/y;   
}
int main()
{
	int N,M,n;
	scanf("%d %d %d",&N,&M,&n);
	for (int i=0;i<=n;i++)
	{
		int c1 = c(M,i);
		int c2 = c(N-M,n-i); 
		int c3 = c(N,n);
		double p = (c1*c2)*1.0/c3;
		printf("%.4f ",p);
	}
	return 0;
}
