#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int min(int a, int b) 
{
    return a<b ? a:b;
}

int main() 
{
    int n;
    scanf("%d", &n);
    // 创建 dp 数组
    // dp[i] 表示组成数字 i 所需的最少完全平方数个数
    int *dp=(int *)malloc((n+1)*sizeof(int));
    // 初始化 dp 数组
    // 最坏情况是全部由 1 组成，所以初始化为 i
    for (int i=0;i<=n;i++) 
	{
        dp[i]=i;
    }
    for (int i=1;i<=n;i++) 
	{
        // 遍历所有可能的完全平方数 j*j，且 j*j <= i
        for (int j=1;j*j<=i;j++) 
		{
            // 状态转移方程：dp[i] = min(dp[i], dp[i - j*j] + 1)
            dp[i]=min(dp[i],dp[i-j*j]+1);
        }
    }
    printf("%d",dp[n]);
    free(dp);
    return 0;
}
