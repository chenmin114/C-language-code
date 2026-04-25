#include <stdio.h>
long long a[100005];

int main()
{
	int n,m;
	long long max=0;
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		if (max<a[i]) max=a[i];
	}
	long long x;
	if (n>1){
	    for (int i=0;i<m;i++){
		    scanf("%lld",&x);
		    if (x>0) max+=x;
	    }
	}
	else {
		for (int i=0;i<m;i++){
		    scanf("%lld",&x);
		}
		    max+=x;
	}
	printf("%lld",max);
	return 0;
}
