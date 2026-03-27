
#include <stdio.h>
int main()
{
    int n, i = 0, d_i;
    long long d[10010];
    d[0] = 0;
    scanf("%d", &n);
    while (n > 1)
    {
        scanf("%d", &d_i);
        d[i + 1] = d[i] + (long long)(d_i) + (long long)(190);
        i++;
        n--;
    }

    int q, s, t;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%d", &s, &t);
        printf("%lld\n", d[t - 1] - d[s - 1]);
    }
    return 0;
}