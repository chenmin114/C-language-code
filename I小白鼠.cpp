#include <stdio.h>

int main() 
{
    long long n, m,t = 0,b,c = 1;
    scanf("%lld %lld", &n, &m);
    if (n == 1) 
	{
        printf("0\n");
        return 0;
    }
    else
    {
        b = m + 1;    
        while (c < n) 
		{
            c *= b;
            t++;
        }
    }
    printf("%lld\n", t);
    return 0;
}
