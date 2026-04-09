#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define MAXN 1005
#define MAXK 105

// 邻接表存图结构
typedef struct Edge {
    int to;
    struct Edge* next;
} Edge;

Edge* adj[MAXN];
int a[MAXN];
long long dp[MAXN][MAXK];
int n, k;

// 添加边
void add_edge(int u, int v) {
    Edge* new_edge = (Edge*)malloc(sizeof(Edge));
    new_edge->to = v;
    new_edge->next = adj[u];
    adj[u] = new_edge;
}

// 深度优先搜索进行树形DP
void dfs(int u, int fa) {
    // 初始化：只选择当前节点 u 的方案数为 1
    if (a[u] <= k) {
        dp[u][a[u]] = 1;
    }

    // 遍历邻接点
    for (Edge* e = adj[u]; e != NULL; e = e->next) {
        int v = e->to;
        if (v == fa) continue; // 防止回溯到父节点

        dfs(v, u); // 先处理子节点

        // 树形背包合并过程
        // 倒序遍历当前累计的权值 i，确保使用的是上一层子树计算完的状态
        for (int i = k; i >= a[u]; i--) {
            // 遍历子树 v 可能贡献的权值 j
            // j 的范围不能超过 i - a[u]，因为 u 至少贡献 a[u]
            for (int j = 0; j <= i - a[u]; j++) {
                if (dp[v][j] > 0) {
                    // 状态转移：
                    // 当前 u 权值为 i 的方案 += (u 权值为 i-j 的方案 * 子树 v 权值为 j 的方案)
                    dp[u][i] = (dp[u][i] + dp[u][i - j] * dp[v][j]) % MOD;
                }
            }
        }
    }
}

int main() {
    // 读入 n 和 k
    if (scanf("%d %d", &n, &k) != 2) return 0;

    // 读入节点权值
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    // 读入边并建图
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    // 从任意节点（这里选 1）开始 DFS
    dfs(1, 0);
    // 统计所有节点作为连通块根节点且权值和为 k 的方案数
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[i][k]) % MOD;
    }

    printf("%lld\n", ans);

    return 0;
}
