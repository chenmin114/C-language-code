#include <stdio.h>
#include <stdlib.h>
long long p[1000005]={0};

int cmp(const void *p, const void *q) 
{
 if(*(long long *)p > *(long long *)q) 
     return 1;
 else if(*(long long *)p < * (long long *)q) return -1;
 else return 0;
}


int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int t;
		scanf("%lld",&p[i]);
		
	}
	qsort(p,n,sizeof(long long),cmp);
	for (int i=0;i<n;i++)
	{
		if (i==0)
		{
			printf("%lld",p[0]);
		} 
		else if (p[i] != p[i-1])
		{
			printf(" %lld",p[i]);
		}
	} 
	return 0;
	
}
