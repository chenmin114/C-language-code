#include <stdio.h>
#include <stdlib.h>

long long max_ll(long long a, long long b) {
    return a>b ? a:b;
}

int main()
 {
    int n;
    scanf("%d",&n);
    // 使用动态分配内存，防止栈溢出，且适应 n 的范围
    long long *a = (long long *)malloc((n + 1) * sizeof(long long));
    int *b = (int *)malloc((n + 1) * sizeof(int));
    long long *dp = (long long *)malloc((n + 1) * sizeof(long long));
    long long *best = (long long *)malloc((n + 2) * sizeof(long long));
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    // 初始化 best 数组为 -1，表示不可达
    for (int i = 0; i <= n + 1; i++) {
        best[i] = -1;
    }
    // 虚拟起点 0：价值为 0，能到达位置 1 (0 + b[0]=1)
    best[1] = 0;
    long long ans = 0;
    long long current_max_val = 0; // 维护当前时刻能到达 i 的最大 dp[j]
    for (int i = 1; i <= n; i++) {
        // 1. 更新 current_max_val
        // 检查是否有从之前的某个位置跳过来的更新记录
        if (best[i] != -1) {
            current_max_val = max_ll(current_max_val, best[i]);
        }
        // 2. 计算 dp[i]
        // 如果 current_max_val 仍为 0 且 best[i] 为 -1，说明只能从虚拟起点(价值0)过来，或者就是第一个元素
        // 这里的逻辑天然支持：如果前面没路过来，current_max_val 会保持之前的状态。
        // 但要注意：我们需要的是 "所有 j < i 且 j+b[j] <= i" 的最大 dp[j]。
        // 上面的 current_max_val 维护的是全局扫描线最大值。
        // 由于我们是从左往右扫，best[i] 存的是刚好能跳到 i 或者更早跳过来的最大值。
        // 实际上，只要 best[i] 被更新了，current_max_val 就会包含它。
        dp[i] = a[i] + current_max_val;
        // 更新全局答案
        ans = max_ll(ans, dp[i]);
        // 3. 将 dp[i] 注册到未来的可达位置
        int next_pos = i + b[i];
        if (next_pos <= n) {
            if (best[next_pos] == -1) {
                best[next_pos] = dp[i];
            } else {
                best[next_pos] = max_ll(best[next_pos], dp[i]);
            }
        }
        // 如果 next_pos > n，说明这个点选完后后面没法选了，不需要注册，或者注册了也没用
    }
    printf("%lld\n", ans);
    // 释放内存
    free(a);
    free(b);
    free(dp);
    free(best);
    return 0;
}
