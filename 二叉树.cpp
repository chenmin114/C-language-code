#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 邻接表存储树结构
int head[100005];
int to[100005];   // 子节点
int nxt[100005];  // 下一个兄弟节点
int edge_cnt = 0;

// 记录每个节点被直接操作的次数
int flip_count[100005];
// 存储初始颜色
char colors[100005];
// 存储结果
char result[100005];
// 添加边的函数
char temp_colors[100005];

void add_edge(int parent, int child) {
    edge_cnt++;
    to[edge_cnt]=child;
    nxt[edge_cnt]=head[parent];
    head[parent]=edge_cnt;
}

// 深度优先搜索
// u: 当前节点
// current_flip: 从根节点到当前节点（包含当前节点）的总翻转次数
void dfs(int u, int current_flip) {
    // 计算当前节点的最终颜色
    // 如果 current_flip 是奇数，颜色翻转；偶数则不变
    int is_flip = current_flip % 2;
    if (colors[u] == '0') {
        result[u] = is_flip ? '1' : '0';
    } else {
        result[u] = is_flip ? '0' : '1';
    }
    // 遍历子节点
    for (int i = head[u]; i > 0; i = nxt[i]) {
        int v = to[i];
        // 子节点的累积翻转次数 = 当前累积次数 + 子节点自身的操作次数
        dfs(v, current_flip + flip_count[v]);
    }
}

int main() 
{
    int n;
    if (scanf("%d", &n) != 1) return 0;
    // 初始化 head 数组
    memset(head, 0, sizeof(head));
    memset(flip_count, 0, sizeof(flip_count));
    // 读取父节点信息，构建树
    for (int i=2; i <= n;i++) {
        int p;
        scanf("%d", &p);
        add_edge(p, i);
    }
    // 读取初始颜色字符串
    // 使用 scanf 读取字符串到临时缓冲区，再复制到 1-indexed 数组中
    scanf("%s",temp_colors);
    for (int i = 0; i < n; i++) {
        colors[i + 1] = temp_colors[i];
    }
    // 读取操作
    int q;
    scanf("%d",&q);
    for (int i=0;i<q;i++) 
	{
        int a;
        scanf("%d",&a);
        flip_count[a]++;
    }
    // 从根节点 1 开始 DFS
    // 初始翻转次数包含根节点自身的操作次数
    dfs(1, flip_count[1]);
    // 输出结果
    for (int i=1;i<=n;i++) {
        printf("%c",result[i]);
    }
    printf("\n");
    return 0;
}
