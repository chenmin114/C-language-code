#include <stdio.h>
#include <stdlib.h>

// 定义物品结构体
typedef struct {
    long long b; // 卖给B的价格
    long long c; // 卖给C的价格
    long long diff; // 差值 b - c
} Item;

// 比较函数，用于qsort，按diff从大到小排序
int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    // 注意：为了防止溢出，最好使用if判断，但在本题long long范围内通常可以直接减
    // 这里使用标准减法逻辑，如果 diff 相等返回 0，A大返回负数（降序），B大返回正数
    if (itemA->diff < itemB->diff) return 1;
    if (itemA->diff > itemB->diff) return -1;
    return 0;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int total_items = 2 * n;
    Item *items = (Item *)malloc(total_items * sizeof(Item));

    // 读取B的出价
    for (int i = 0; i < total_items; i++) {
        scanf("%lld", &items[i].b);
    }

    // 读取C的出价并计算差值
    for (int i = 0; i < total_items; i++) {
        scanf("%lld", &items[i].c);
        items[i].diff = items[i].b - items[i].c;
    }

    // 按照差值从大到小排序
    qsort(items, total_items, sizeof(Item), compare);

    long long max_revenue = 0;

    // 前n个物品卖给B（差值最大的，即b远大于c的）
    for (int i = 0; i < n; i++) {
        max_revenue += items[i].b;
    }

    // 后n个物品卖给C（差值最小的，即c远大于b的）
    for (int i = n; i < total_items; i++) {
        max_revenue += items[i].c;
    }

    printf("%lld\n", max_revenue);

    free(items);
    return 0;
}
