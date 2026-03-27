#include <stdio.h>

long long gcd(long long a, long long b) 
{
    while (b != 0) 
	{
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int main()
{
    int T;
    scanf("%d", &T);  
    while (T--) 
	{
        long long n, a1, d;
        scanf("%lld %lld %lld", &n, &a1, &d);  
        long long x = gcd(a1, d);  
        printf("%lld\n",x);
    }
    return 0;
}
