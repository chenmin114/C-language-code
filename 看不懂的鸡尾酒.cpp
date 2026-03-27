#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 998244353
#define MAX_BITS 31

long long dp[2][2], new_dp[2][2];
int count[2][2];

long long solve_pair(int i, int j, int* a, int n) {
    // 统计四种类型的数量
    memset(count, 0, sizeof(count));
    for (int k = 0; k < n; k++) {
        int bit_i = (a[k] >> i) & 1;
        int bit_j = (a[k] >> j) & 1;
        count[bit_i][bit_j]++;
    }
    
    // 动态规划
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;  // 空集
    
    for (int type_i = 0; type_i < 2; type_i++) {
        for (int type_j = 0; type_j < 2; type_j++) {
            int cnt = count[type_i][type_j];
            if (cnt == 0) continue;
            
            memcpy(new_dp, dp, sizeof(dp));
            
            // 对于当前类型的每个数，考虑选或不选
            // 但实际上我们可以批量处理：选奇数个或选偶数个
            // 选偶数个：不改变状态
            // 选奇数个：改变状态
            
            long long ways_even = 1;  // 选偶数个的方式数
            long long ways_odd = 0;   // 选奇数个的方式数
            
            // 计算组合数：C(n,0)+C(n,2)+... 和 C(n,1)+C(n,3)+...
            if (cnt > 0) {
                ways_even = ways_odd = 1;  // 对于n=1
                for (int k = 2; k <= cnt; k++) {
                    long long new_even = (ways_even + ways_odd) % MOD;
                    long long new_odd = (ways_even + ways_odd) % MOD;
                    ways_even = new_even;
                    ways_odd = new_odd;
                }
            }
            
            // 更新dp
            for (int x = 0; x < 2; x++) {
                for (int y = 0; y < 2; y++) {
                    if (dp[x][y] == 0) continue;
                    
                    // 选偶数个：状态不变
                    new_dp[x][y] = (new_dp[x][y] + dp[x][y] * ways_even) % MOD;
                    
                    // 选奇数个：状态改变
                    int new_x = x ^ type_i;
                    int new_y = y ^ type_j;
                    new_dp[new_x][new_y] = (new_dp[new_x][new_y] + dp[x][y] * ways_odd) % MOD;
                }
            }
            
            memcpy(dp, new_dp, sizeof(dp));
        }
    }
    
    return (dp[1][1] - 1 + MOD) % MOD;  // 减去空集
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        scanf("%d", &n);
        int* a = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        
        long long ans = 0;
        
        // 枚举所有位对
        for (int i = 0; i < MAX_BITS; i++) {
            for (int j = 0; j < MAX_BITS; j++) {
                long long count = solve_pair(i, j, a, n);
                long long power = (1LL << (i + j)) % MOD;
                ans = (ans + count * power) % MOD;
            }
        }
        
        printf("%lld\n", ans);
        free(a);
    }
    
    return 0;
}
