#include <stdio.h>

long long read() 
{
    long long x = 0, f = 1;
    long long c = getchar();
    while (c > '9' || c < '0') 
	{
        if (c == '-')
            f = -f;
        c = getchar();
    }
    while (c >= '0' && c <= '9') 
	{
        x = (x << 3) + (x << 1) + (c ^ '0');
        c = getchar();
    }
    return x * f;
}

int main() 
{
    long long T = read();
    for (int i=0;i<T;i++) 
	{
        long long l = read();
        long long r = read();
        
        if (l == r) 
		{
            printf("%lld\n", l);
        }
		else 
		{
            long long diff = l ^ r;
            long long k = 0;
            while (diff) 
			{
                diff >>= 1;
                k++;
            }
            long long mask = (1LL << (k - 1)) - 1;
            printf("%lld\n", r | mask);
        }
    }
    return 0;
}
