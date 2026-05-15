#include <stdio.h>
#include <stdlib.h>
#define INF 2000000000
int items[505][2]; // items[i][0] = 攻击力, items[i][1] = 价格
long long min(long long a,long long b) {
    return a<b ? a:b;
}

int main() 
{
    int n;
    long long k; 
    scanf("%d %lld",&n,&k);
    int max=0;
    for (int i=0;i<n;i++) 
	{
        scanf("%d %d",&items[i][0],&items[i][1]);
        max+=items[i][0];
    }
    // dp[j] 表示获得 j 点攻击力所需的最小金币
    // 大小开到最大可能攻击力 + 1
    long long *dp=(long long *)malloc((max+1)*sizeof(long long));
    // 初始化
    for (int j =0;j<=max;j++) {
        dp[j]=INF;
    }
    dp[0]=0;
    // 0/1 背包动态规划
    for (int i=0;i<n;i++) 
	{
        int attack=items[i][0];
        int cost=items[i][1];
        // 必须倒序遍历，保证每件物品只被选一次
        for (int j=max;j>=attack;j--) 
		{
            if (dp[j-attack]!=INF) 
			{
                dp[j]=min(dp[j],dp[j-attack]+cost);
            }
        }
    }
    int ans=0;
    for (int j=max;j>=0;j--) 
	{
        if (dp[j]<=k) 
		{
            ans=j;
            break;
        }
    }
    printf("%d\n",ans);
    free(dp);
    return 0;
}
