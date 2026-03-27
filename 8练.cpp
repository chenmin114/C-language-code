#include <stdio.h>
#include <stdlib.h>
long long a[500005];
long long b[500005]={0};
long long p[500005];

int cmp(const void *x ,const void *y)
{
	int i1=*(const int *)x,i2=*(const int *)y;
    if (b[i1]!=b[i2]) return b[i1]<b[i2];
    return a[i1]<a[i2];
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		p[i]=i;
		for (int j=0;j<=31;j++)
		{
			b[i]+=(j+1)*((a[i]>>j)&1);
		} 
	} 
	qsort(p+1,n,sizeof(p[1]),cmp);
	for (int i=1;i<=n;i++)
	{
		printf("%lld\n",a[p[i]]);
	}
	return 0;
}
