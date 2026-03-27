#include <stdio.h>
#include <stdint.h>
const int mod = 998244353;
int32_t fib[10005] = {1, 1};
int32_t f(int x)
{
    if (fib[x])
        return fib[x];
    return (f(x - 2) + f(x - 1)) % mod;
}
int main(void)
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int32_t a, b, n;
        scanf("%d%d%d", &a, &b, &n);
        printf("%lld\n", (long long)(a * f(n))%mod + (b * f(n - 1)) % mod);
    }
    return 0;
}
