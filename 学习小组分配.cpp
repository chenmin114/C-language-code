#include <stdio.h>
#include <stdlib.h>
long long max(long long a,long long b) {
    return a>b ? a:b;
}

int main() 
{
    int n;
    scanf("%d", &n);
    // 动态分配数组存储积极度，索引从 1 到 n
    int *a = (int *)malloc((n+1)*sizeof(int));
    // 动态分配数组存储 DP 状态
    long long *dp = (long long *)malloc((n + 1) * sizeof(long long));
    // 读取不同人数的积极度
    for (int i=1;i<=n;i++) 
	{
        scanf("%d",&a[i]);
    }
    // 初始化 DP 数组
    // dp[0] 表示 0 个人时的积极度为 0
    dp[0] = 0;
    // 开始动态规划
    // i 表示当前考虑的总人数，从 1 到 n
    for (int i=1;i<=n;i++) 
	{
        dp[i]=0; // 初始化当前状态，因为 a[i] 非负，最小值为 0
        // 尝试最后分出的一个小组的人数 j，从 1 到 i
        for (int j=1;j<=i;j++) 
		{
            // 状态转移方程：
            // 当前 i 个人的最大积极度 = max(当前值, 前 i-j 个人的最大积极度 + 一个 j 人小组的积极度)
            dp[i]=max(dp[i],dp[i-j]+a[j]);
        }
    }
    // 输出 n 个人的最大积极度
    printf("%lld\n",dp[n]);
    // 释放内存
    free(a);
    free(dp);
    return 0;
}
