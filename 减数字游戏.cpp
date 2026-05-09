#include <stdio.h>
#define MOD 1000000007
long long p[200005]={0};

int main()
{
	int n,a,b,c;
	scanf("%d %d %d %d",&n,&a,&b,&c);
	if (n==c){
		printf("1");
		return 0;
	}
	p[n]=1;
	long long ans=0;
	for (int i=n;i>c;i--)
	{
		if (i-a>c){
			p[i-a]=(p[i]+p[i-a])%MOD;
		}
		else ans+=p[i];
		if (i-b>c){
			p[i-b]=(p[i]+p[i-b])%MOD;
		}
		else ans+=p[i];
		ans=ans%MOD;
	}
	printf("%lld",ans);
	return 0;
}
