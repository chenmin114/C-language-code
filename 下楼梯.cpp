#include <stdio.h>
#include <math.h>
long long dp[65]={0};

int main()
{
	int n;
	scanf("%d",&n);
	dp[1]=1,dp[2]=2,dp[3]=4;
	if (n<=3){
		printf("%lld",dp[n]);
		return 0;
	}
	else{
		for (int i=4;i<=n;i++){
			dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
		}
		printf("%lld",dp[n]);
	}
	return 0;
}
