#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int cmp(const void *a ,const void *b)
{
    return *(int *)a - *(int *)b;
}

int min(int *s,int m,int a)
{
	int l=0,r=m-1;
	while(l<r){
	int mid=(l+r)/2;
	if(s[mid]<a){
		l=mid+1;
	}
	else r=mid;
	}
	int ans;
	if (l==0){
		ans=abs(s[0]-a);
	}else{
		int m1=abs(s[l-1]-a);
		int m2=abs(a-s[l]);
		ans=(m1<m2) ? m1:m2;
	}
	return ans;
}
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	int *s=(int *)malloc(m*sizeof(int));
	for (int i=0;i<m;i++){
		scanf("%d",&s[i]);
	}
	qsort(s,m,sizeof(int),cmp);
	int sum=0;
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		int x=min(s,m,a);
		sum+=x;
	}
	printf("%d",sum);
	return 0;
}
