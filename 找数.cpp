#include <stdio.h>
#include <stdlib.h>
int a[1000005],b[100005];

int cmp(const void *a ,const void *b)
{
    return *(int *)a>*(int *)b;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
	}	
	qsort(a,n,sizeof(a[0]),cmp);
	qsort(b,m,sizeof(b[0]),cmp);
	int i=0,j=0,ans=0;
	while(i<n && j<m)
	{
		if (a[i]==b[j]){
			ans++;
			i++;
			j++;
		}
		else if(a[i]>b[j]){
			j++;
		}
		else i++;
	}
	printf("%d",ans);
	return 0;
}
