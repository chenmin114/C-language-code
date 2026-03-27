#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100010

int cnt[MAX_N];  // 计数每张牌的数量
int temp[MAX_N]; // 临时数组用于检查
int n, m, total_cards;
int result[MAX_N], result_count = 0;

// 检查加入一张牌t后是否能和牌
int check_win(int t) {
    memcpy(temp, cnt, sizeof(int) * (n + 5));
    temp[t]++;

    // 枚举对子
    for (int pair = 1; pair <= n; pair++) {
        if (temp[pair] < 2) continue;
        
        int tmp[MAX_N];
        memcpy(tmp, temp, sizeof(int) * (n + 5));
        tmp[pair] -= 2;

        // 检查剩下的牌能否组成m+1个面子
        for (int i = 1; i <= n; i++) {
            // 先消刻子
            if (tmp[i] >= 3) {
                tmp[i] %= 3; // 刻子可以多个，但这里我们一次消3个，其实用除法和取余更高效
            }
            // 消顺子
            if (tmp[i] > 0) {
                if (i + 2 > n) { // 无法形成顺子
                    if (tmp[i] != 0) break;
                }
                if (tmp[i] <= tmp[i+1] && tmp[i] <= tmp[i+2]) {
                    tmp[i+1] -= tmp[i];
                    tmp[i+2] -= tmp[i];
                    tmp[i] = 0;
                } else {
                    break;
                }
            }
            if (i == n) {
                // 检查是否全部消完
                int ok = 1;
                for (int j = 1; j <= n; j++) {
                    if (tmp[j] != 0) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) return 1;
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);
    total_cards = 3 * m + 1;

    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < total_cards; i++) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }

    result_count = 0;
    for (int t = 1; t <= n; t++) {
        if (check_win(t)) {
            result[result_count++] = t;
        }
    }

    if (result_count == 0) {
        printf("Noten\n");
    } else {
        for (int i = 0; i < result_count; i++) {
            printf("%d", result[i]);
            if (i < result_count - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
