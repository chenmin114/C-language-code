#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
	int z; 
} p;

int cmp(const void *a,const void *b)
{
	p *p1=(p*)a;
	p *p2=(p*)b;
	return p1->z-p2->z;
}

p factors[500005];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d %d %d",&factors[i].x,&factors[i].y,&factors[i].z);
	}
	qsort(factors,n,sizeof(p),cmp);
	double sum=0;
	for (int i=0;i<n-1;i++)
	{
		double dx=factors[i+1].x-factors[i].x;
		double dy=factors[i+1].y-factors[i].y;
		double dz=factors[i+1].z-factors[i].z;
		double s=sqrt(pow(dx,2)+pow(dy,2)+pow(dz,2));
		sum+=s;
	}
	printf("%.3lf",sum);
	return 0;
}

