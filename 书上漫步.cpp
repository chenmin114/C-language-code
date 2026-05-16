#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Edge {
    int to;
    struct Edge* next;
} Edge;

Edge* adj[200005];      // 邻接表头指针数组
int color[200005];      // 存储每个节点的颜色 (0 或 1)
int count[2];         // count[0] 存颜色0的个数, count[1] 存颜色1的个数
int n;

// 添加边的函数
void addEdge(int u, int v) 
{
    Edge* newEdge=(Edge*)malloc(sizeof(Edge));
    newEdge->to=v;
    newEdge->next=adj[u];
    adj[u]=newEdge;
}

// 深度优先搜索进行染色
void dfs(int u,int c) 
{
    color[u]=c;
    count[c]++;
    Edge* p=adj[u];
    while (p!= NULL) {
        int v=p->to;
        if (color[v]==-1) {
            dfs(v,1-c); // 相邻节点染成相反颜色
        }
        p=p->next;
    }
}

int main() 
{
    scanf("%d",&n);
    memset(adj,0,sizeof(adj));
    memset(color,-1,sizeof(color)); // -1 表示未访问
    count[0]=count[1]=0;
    for (int i=0;i<n-1;i++) 
	{
        int u,v;
        scanf("%d %d",&u,&v);
        addEdge(u,v);
        addEdge(v,u); // 无向图，双向添加
    }
    // 从节点 1 开始进行 DFS 染色
    // 树是连通图，一次 DFS 即可遍历所有节点
    dfs(1,0);
    // 输出结果
    for (int i=1;i<=n;i++) {
        // 如果节点 i 是颜色 0，答案是颜色 0 的总数
        // 如果节点 i 是颜色 1，答案是颜色 1 的总数
        printf("%d ",count[color[i]]);
    }
    printf("\n");
    // 释放内存 (在实际竞赛中通常不需要，但在工程中是好习惯)
    for (int i=1;i<=n;i++) 
	{
        Edge* p=adj[i];
        while (p!=NULL) 
		{
            Edge* temp=p;
            p=p->next;
            free(temp);
        }
    }
    return 0;
}
