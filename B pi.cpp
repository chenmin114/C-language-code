#include <stdio.h>

int main()
{
	int n,x=1;
	double sum=0.0;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		sum += (x/(2*i+1.0))*1.0;
		x=-x;
	}
	double pi=4*sum;
	printf("%.9f",pi);
	return 0;
}
