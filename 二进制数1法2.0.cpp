#include <stdio.h>

typedef long long ll;
ll count(int n) 
{
    ll sum = 0;
    for (int k = 0; k < 31; ++k) 
	{  
        int length = 1 << (k + 1);  
        int cycle = n / length;
        ll full_ones = (ll)cycle * (1 << k);         
        int remain = n % length;
        ll rem_ones = (remain > (1 << k)) ? (remain - (1 << k)) : 0;  
        sum += full_ones + rem_ones;
    }
    return sum;
}
int main() 
{
    int T;
    scanf("%d", &T);
    while (T--) 
	{
        int n;
        scanf("%d", &n);
        printf("%lld\n", count(n));
    }
    return 0;
}
