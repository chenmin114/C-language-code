#include <stdio.h>
int main()
{	
    long long h, p, q;
    while (scanf("%lld%lld%lld", &h, &p, &q) != EOF)
    {
        long long n;
        scanf("%lld", &n);
        long long i;
        long long s = 0;
        long long flag;
        for (i = 0; i < n; i++)
        {
            long long a;
            scanf("%lld", &a);
            s += a;
            if (h + s <= p && flag == 0)
            {
                flag = 1;
                printf("down\n");
            }
            if (h + s >= q && flag == 0)
            {
                flag = 1;
                printf("up\n");
            }
        }
        if (flag == 0)
        {
            if (s > 0)
                printf("up\n");
            else if (s < 0)
                printf("down\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
