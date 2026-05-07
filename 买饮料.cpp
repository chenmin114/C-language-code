#include <stdio.h>
#include <stdlib.h>
#define max 100000000
#define min(a, b) ((a) < (b) ? (a) : (b))
int c[505];
int l[505];
int dp[2005];

int main() 
{
    int N, L;
    scanf("%d %d", &N, &L);
    for (int i = 0; i < N; i++) 
	{
        scanf("%d %d",&c[i],&l[i]);
	}
    // 初始化 dp 数组
    for (int j = 0; j <= L; j++) {
        dp[j] =max;
    }
    dp[0] = 0;
    // 0/1 背包动态规划
    for (int i=0;i<N;i++) {
        // 必须从后往前遍历，保证每种饮料只被计算一次
        for (int j=L;j>=0;j--) {
            if (dp[j]!=max) 
			{
                // 如果购买第 i 种饮料
                int n=j+l[i];
                // 截断容量：超过 L 的部分没有意义，直接归为 L
                if (n>L) 
				{
                    n=L;
                }
                // 更新状态
                dp[n]=min(dp[n],dp[j]+c[i]);
            }
        }
    }
    if (dp[L]==max) {
        printf("no solution\n");
    } 
	else {
        printf("%d\n", dp[L]);
    }
    return 0;
}
