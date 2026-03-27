#include <stdio.h>

int main() {
    int n, q;
    // 读取数组长度和操作数
    scanf("%d %d", &n, &q);
    int arr[1005];
    // 读取数组初始值
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }
    while (q--) {
        int op, x, y;
        scanf("%d %d %d", &op, &x, &y);
        switch (op) {
            case 1:
                if (x != y) {
                    arr[x] = arr[y];
                }
                break;
            case 2:
                if (x != y) {
                    int temp = arr[x];
                    arr[x] = arr;
                    arr = temp;
                }
                break;
            case 3:
                arr[x] += y;
                break;
            case 4:
                arr[x] = y;
                break;
            case 5:
                printf("%d\n", arr[x] - arr[y]);
                break;
            case 6:
                int sum = 0;
                for (int i = x; i <= y; ++i) {
                    sum += arr[i];
                }
                printf("%d\n", sum);
                break;
        }
    }
    return 0;
}
