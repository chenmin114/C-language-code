#include <stdio.h>
#define MOD 998244353

int main() {
    int n;
    scanf("%d", &n);
    if (n == 2) 
	{ 
        printf("6\n");
        return 0;
    }
    long long a12 = 1, a13 = 1,a21 = 1, a23 = 1,a31 = 1, a32 = 1;
    for (int i = 3; i <= n; ++i) 
	{
        long long na12 = (a21 + a31) % MOD;
        long long na13 = (a21 + a31) % MOD;
        long long na21 = a12 % MOD;
        long long na23 = a32 % MOD; 
        long long na31 = (a13 + a23) % MOD;
        long long na32 = (a13 + a23) % MOD;
        a12 = na12; 
		a13 = na13;
        a21 = na21; 
		a23 = na23;
        a31 = na31; 
		a32 = na32;
    }
    
    long long ans = (a12 + a13 + a21 + a23 + a31 + a32) % MOD;
    printf("%lld\n", ans);
    return 0;
}
