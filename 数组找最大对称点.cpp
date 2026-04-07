#include<stdio.h>
#include<string.h>
int dp[2][1005];
char a[1005];
char b[1005];

int main()
{
	scanf("%s",a);
	int n=strlen(a);
	for (int i=n-1;i>=0;i--)
	{
		b[n-1-i]=a[i];
	}
	dp[0][0]=0;
	for (int i=1;i<=n;i++)
	{
		int cur=i%2;
		int pre=(i-1)%2;
		for (int j=1;j<=n;j++)
		{
			if(a[i-1]==b[j-1])
			{
				dp[cur][j]=dp[pre][j-1]+1;
			}
			else{
				if(dp[pre][j]>dp[cur][j-1])
				{
					dp[cur][j]=dp[pre][j];
				}
				else dp[cur][j]=dp[cur][j-1];
			}
		}
	}
	printf("%d",n-dp[n%2][n]);
	return 0;
}
