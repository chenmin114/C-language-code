#include <stdio.h>
#include <stdint.h>
const int mod = 993244853;
int32_t fib[10005];
void f()
{
    fib[0]=0;
    fib[1]=1;
    for (int i = 2;i < 10005;i++)
        fib[i] = (fib[i-1] + fib[i-2]) % mod;
}
int main(void)
{
	f();
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int32_t a, b, n;
        scanf("%d%d%d", &a, &b, &n);
        if (n == 1)
            printf("%d\n", (a+b) % mod);
        else printf("%lld\n", (((long long)a * fib[n+1]) % mod + ((long long)b * fib[n]) % mod));
    }
    return 0;
}
