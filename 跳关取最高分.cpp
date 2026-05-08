#include <stdio.h>
#include <limits.h>
#define MAX(a, b) (a>b ? a:b)
int a[105]; // 存储通道前进的关数
int b[10005]; // 存储每一关的分数
long long dp[10005]; // 存储动态规划结果，使用 long long 防止溢出

int main() 
{
    int N, M;
    scanf("%d %d",&N,&M);
    for (int i = 0; i < M; i++) 
	{
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &b[i]);
    }
    // 从后往前进行动态规划
    // i 表示当前所在的关卡
    for (int i=N-1;i>=0;i--) 
	{
        long long max_future_score = LLONG_MIN; // 初始化为最小值
        for (int j=0;j<M;j++) 
		{
            int next_pos=i+a[j];
            long long current_choice_score;
            // 如果下一步超出了关卡范围，说明直接通关，后续得分为 0
            if (next_pos>=N) 
			{
                current_choice_score = 0;
            } 
			else {
                current_choice_score = dp[next_pos];
            }
            // 更新当前关卡能获得的最大后续分数
            if (current_choice_score > max_future_score) {
                max_future_score = current_choice_score;
            }
        }
        // 当前关卡的总分 = 当前关卡的分数 + 最佳后续路径的分数
        dp[i] = b[i] + max_future_score;
    }
    // 输出从第 0 关开始的最大分数
    printf("%lld\n", dp[0]);
    return 0;
}
