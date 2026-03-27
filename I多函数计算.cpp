#include <stdio.h>
#include <stdlib.h>
#define mod 998244353
#define MAXN 200005

long long A[200005], B[200005];
int op[200005];
long long a_or_b[200005];
int c[200005], d[200005];


void f(int k) 
{
    if (A[k] != -1) 
	    return; 
    
    switch (op[k]) 
	{
        case 1:
            A[k] = 1;
            B[k] = a_or_b[k] % mod;
            break;
        case 2:
            A[k] = a_or_b[k] % mod;
            B[k] = 0;
            break;
        case 3:
            f(d[k]);
            f(c[k]);
            A[k] = (A[c[k]] * A[d[k]]) % mod;
            B[k] = (A[c[k]] * B[d[k]] + B[c[k]]) % mod;
            break;
        case 4:
            f(c[k]);
            f(d[k]);
            A[k] = (A[c[k]] + A[d[k]]) % mod;
            B[k] = (B[c[k]] + B[d[k]]) % mod;
            break;
    }
}

int main() 
{
    int n, q;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) 
	{
        A[i] = -1;
        B[i] = -1;
    }
    
    for (int i = 1; i <= n; ++i) 
	{
        scanf("%d", &op[i]);
        if (op[i] == 1 || op[i] == 2) 
		{
            scanf("%lld", &a_or_b[i]);
        } 
		else 
		{ 
            scanf("%d%d", &c[i], &d[i]);
        }
    }
    for (int i = 1; i <= n; ++i) 
	{
        if (A[i] == -1) 
		{
            f(i);
        }
    }
    scanf("%d", &q);
    while (q--) 
	{
        int k;
        long long x;
        scanf("%d%lld", &k, &x);
        x %= mod;
        long long res = (A[k] * x + B[k]) % mod;
        if (res < 0) res += mod;
        printf("%lld\n", res);
    }
    
    return 0;
}
