#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[15];
    int price;
    int priority;
    int bought; // 标记是否已购买
} Product;

int compare_strings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int M, N;
    if (scanf("%d %d", &M, &N) != 2) return 0;
    Product products[1005];
    for (int i = 0; i < N; i++) {
        scanf("%s %d %d", products[i].name, &products[i].price, &products[i].priority);
        products[i].bought = 0;
    }
    char *bought_names[1005];
    int bought_count = 0;
    int current_budget = M;
    while (1) {
        int best_idx = -1;
        for (int i = 0; i < N; i++) {
            if (products[i].bought || products[i].price > current_budget) {
                continue;
            }
            if (best_idx == -1) {
                best_idx = i;
            } else {
                if (products[i].priority < products[best_idx].priority) {
                    best_idx = i;
                }
                else if (products[i].priority == products[best_idx].priority) {
                    if (products[i].price < products[best_idx].price) {
                        best_idx = i;
                    }
                    else if (products[i].price == products[best_idx].price) {
                        if (strcmp(products[i].name, products[best_idx].name) < 0) {
                            best_idx = i;
                        }
                    }
                }
            }
        }
        if (best_idx == -1) {
            break;
        }
        products[best_idx].bought = 1;
        current_budget -= products[best_idx].price;
        bought_names[bought_count] = (char *)malloc(sizeof(char) *15);
        strcpy(bought_names[bought_count], products[best_idx].name);
        bought_count++;
    }
    qsort(bought_names, bought_count, sizeof(char *), compare_strings);
    for (int i = 0; i < bought_count; i++) {
        printf("%s\n", bought_names[i]);
        free(bought_names[i]); // 释放内存
    }
    return 0;
}
