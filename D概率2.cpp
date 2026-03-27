#include <stdio.h>

// 计算组合数 C(a, b)
long long combination(int a, int b) {
    if (b > a) return 0;
    if (b == 0 || b == a) return 1;
    b = (b < a - b) ? b : a - b; // 利用组合数的性质减少计算量
    long long res = 1;
    for (int i = 1; i <= b; i++) {
        res = res * (a - b + i) / i;
    }
    return res;
}

int main() {
    int N, M, n;
    scanf("%d %d %d", &N, &M, &n);

    for (int k = 0; k <= n; k++) {
        long long numerator = combination(M, k) * combination(N - M, n - k);
        long long denominator = combination(N, n);
        double probability = (double)numerator / denominator;
        printf("%.4lf ", probability);
    }

    return 0;
}
