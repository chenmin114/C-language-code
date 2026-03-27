#include <stdio.h>
int G[105][105];
int visited[105][105];
int sizes[10005];
int n, m;
int dfs(int i, int j){
    if (i < 0 || i >= n || j < 0 || j >= m){
        return 0;
    }
    if (G[i][j] != 1 || visited[i][j] == 1){
        return 0;
    }
    int size = 1;
    visited[i][j] = 1;
    size += dfs(i - 1, j);
    size += dfs(i + 1, j);
    size += dfs(i, j - 1);
    size += dfs(i, j + 1);
    return size;
}
int main(){
    int rst = 0, cnt = 0, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &G[i][j]);
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (G[i][j] == 1 && visited[i][j] == 0){
                sizes[cnt] = dfs(i, j);
                cnt++;
            }
        }
    }
    //Bubble-sort
    for (int i = 0; i < cnt - 1; i++){
        for (int j = 0; j < cnt - 1 - i; j++){
            if (sizes[j] < sizes[j + 1]){
                int temp = sizes[j];
                sizes[j] = sizes[j + 1];
                sizes[j + 1] = temp;
            }
        }
    }
    int take = (k < cnt) ? k : cnt;
    for (int i = 0; i < take; i++){
        rst += sizes[i];
    }
    printf("%d\n", rst);
    return 0;
}
