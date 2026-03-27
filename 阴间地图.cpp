#include <stdio.h>

int main() 
{
    long long n, m, x0, y0, x1, y1;
    scanf("%lld %lld", &n, &m);
    scanf("%lld %lld", &x0, &y0);
    scanf("%lld %lld", &x1, &y1);
    for (long long i = x1 - 2; i <= x1 + 2; ++i) 
	{
        for (long long j = y1 - 2; j <= y1 + 2; ++j) 
		{
            long long x = i - x0;
            long long y = j - y0;

            if (x == 0 && y == 0) 
                printf("+");
            else if (x == 0) 
                printf("-");
            else if (y == 0) 
                printf("|");
            else if (x == y) 
                printf("\\");
            else if (x == -y) 
                printf("/");
            else if (x < 0 && y > 0 && x < -y) 
                printf("A");
            else if (x < 0 && y > 0 && x > -y)
                printf("B");
            else if (x > 0 && y > 0 && y > x)
                printf("C");
            else if (x > 0 && y > 0 && x > y)
                printf("D");
            else if (x > 0 && y < 0 && -x < y)
                printf("E");
            else if (x > 0 && y < 0 && -x > y)
                printf("F");
            else if (x < 0 && y < 0 && x > y)
                printf("G");
            else if (x < 0 && y < 0 && x < y)
                printf("H");
        }
        printf("\n");
    }
    return 0;
}
