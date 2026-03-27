#include <stdio.h>

int qpow(int a, long long b, int p)
{
    int ans = 1;
    int base = a;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = ans * (long long)base % p;
        }
        base = (long long)base * base % p;
        b >>= 1;
    }
    return ans;
}

int main()
{
	long long b;
	int t,a,p,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %lld %d",&a,&b,&p);
		ans=qpow(a,b,p);
		printf("%d\n",ans);
	}
	return 0;
}
