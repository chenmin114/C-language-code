#include <stdio.h>
#define lowbit(x) __builtin_ffsll(x)

int main(void) 
{
    int t;
    scanf("%d", &t);
    while (t--) 
	{
        int n;
        long long k;
        scanf("%d%lld", &n, &k);
        if (n < 63 && k >= (1LL << n))
            printf("-1\n");
        else if (n == 63 && k < 0) 
            printf("-1\n");
        else
            printf("%d\n", lowbit(k));
    }
    return 0;
}
