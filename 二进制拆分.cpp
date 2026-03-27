#include <stdio.h>

int main() 
{
    int n;
    scanf("%d", &n);
    for (int i=1;i<=n;i++)
	{
        long long a;
        scanf("%lld", &a);
        int t = 1;
        for (int i = 30; i >= 0; i--) 
		{
            if (a & (1LL << i)) 
			{
                if (t != 1)
			    {
                    printf(" ");
                }
                printf("%lld", 1LL << i);
                t = 0;
            }
        }
        printf("\n");
    }
    return 0;
}
