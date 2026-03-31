#include<stdio.h>
#include<stdlib.h>
int c[100005];

int cmp(const void *a ,const void *b)
{  
    return *(int *)a < *(int *)b; 
}

int main()
{
	int n;
	int sum=0;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&c[i]);
	}
	qsort(c,n,sizeof(int),cmp);
	for (int i=0;i<(n/3);i++)
	{
		sum+=c[3*i]+c[3*i+1];
	}
	if (n%3==1) sum+=c[n-1];
	if (n%3==2) sum+=c[n-2]+c[n-1];
	printf("%d",sum);
	return 0;
}
