#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;  // 维度数
    scanf("%d", &n);

    int a[20], b[20];  // 定义数组的大小
    long long m = 1;   // m 是原数组元素的乘积

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        m *= a[i];  // 计算元素的乘积
    }

    int m_val;  // m 的限制
    scanf("%d", &m_val);
    
    for (int i = 0; i < m_val; i++) {
        scanf("%d", &b[i]);
    }
    
    int c[20];  // 存放优先级排序的数组
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    // 按优先级排序的逻辑
    // 假设 a, b, c 存放了不同的维度信息
    // 可根据任务具体需求实现优先级排序

    // 输出最终的排序结果
    // 可根据 c 数组中的优先级制作输出
    for (int i = 0; i < m_val; i++) {
        printf("%d ", b[i]);
    }

    return 0;
}
