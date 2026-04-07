#include<stdio.h>
int n,ans;
int a[105][105];      // 地图数组：AB为-1，+为1，-为0
int vis[105][105];    // 记忆化数组：记录到达(x,y)的最小步数
int start_x,start_y,end_x,end_y; // 起点和终点坐标
// 深度优先搜索
// x, y: 当前坐标
// cnt: 当前已走的步数
void dfs(int x,int y,int cnt)
{
    int tx,ty;
    // 剪枝1：如果当前步数已经超过已知最优解，没必要继续
    if(cnt>ans) return;
    // 剪枝2：如果到达当前点的步数比之前记录的还要多，没必要继续
    if(cnt>vis[x][y]) return;
    // 边界检查
    if(x<1 || x>n || y<1 || y>n) return;
    // 终止条件：到达终点B
    if(x==end_x && y==end_y)
    {
        ans=cnt;// 更新最优解
        return;
    }
    // 更新到达当前点的最小步数记录
    vis[x][y]=cnt;
    // 尝试向四个方向移动 (上、下、右、左)
    // 代码中使用了代码块 {} 包裹，虽然不是必须的，但增强了可读性
    // 上
    tx=x-1;ty=y;
    {
        // 核心逻辑：只有当目标区域与当前区域不同时（正负交替），才允许移动
        // A(-1) -> +/-(0/1) 成立
        // +/-(1/0) -> -/+(0/1) 成立
        if(a[tx][ty]!=a[x][y])
            dfs(tx,ty,cnt+1);
    }
    // 下
    tx=x+1;ty=y;
    {
        if(a[tx][ty]!=a[x][y])
            dfs(tx,ty,cnt+1);
    }
    // 右
    tx=x;ty=y+1;
    {
        if(a[tx][ty]!=a[x][y])
            dfs(tx,ty,cnt+1);
    }
    // 左
    tx=x;ty=y-1;
    {
        if(a[tx][ty]!=a[x][y])
            dfs(tx,ty,cnt+1);
    }
}

int main()
{
    int i,j;
    char x;
    scanf("%d",&n);
    getchar(); // 消化输入n后的换行符，防止影响后续字符读取
    ans=1e9; // 初始化答案为无穷大
    // 初始化vis数组为无穷大
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            vis[i][j]=1e9;
    // 输入处理
    for(i=1;i<=n;i++)
    {
        j=1;
        // 逐字符读取，直到换行
        while((x=getchar())!='\n')
        {
            if(x=='A')
            {
                start_x=i;start_y=j;
                a[i][j++]=-1;
            }
            else if(x =='B') 
            {
                end_x=i;end_y=j;
                a[i][j++]=-1;
            }
            else if(x=='+')
            {
                a[i][j++]=1;
            }
            else if(x=='-')
            {
                a[i][j++]=0;
            }
        }
    }
    // 从起点开始搜索，初始步数为0
    dfs(start_x,start_y,0);
    printf("%d",ans);
    return 0;
}
