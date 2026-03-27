#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool zhi(long long x) 
{
    if (x <= 1) 
	{
        return false;
    }
    if (x == 2) 
	{
        return true;
    }
    if (x % 2 == 0) 
	{
        return false;
    }
    long long r = (long long)sqrt(x);
    for (long long i = 3; i <= r; i += 2) 
	{
        if (x % i == 0) 
		{
            return false;
        }
    }
    return true;
}

int main() 
{
    int T;
    scanf("%d", &T);
    while (T--) 
	{
        long long n;
        scanf("%lld", &n);
        for (long long i = n;; i++) 
		{
            if (zhi(i)) 
			{
                printf("%lld\n", i);
                break;
            }
        }
    }
    return 0;
}
