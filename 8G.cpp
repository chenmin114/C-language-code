#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#define MOD 998442353

long long pows(long long a,long long b,long long mod)
{
	long long res=1;
	while (b)
	{
	    if(b&1)
		    res=res*a%mod;
		a =a*a%mod;
		b>>=1;
    }
    return res;
}    

int cmp(const void *p, const void *q) 
{
 if(*(long long *)p > *(long long *)q) 
     return 1;
 else if(*(long long *)p < * (long long *)q) 
     return -1;
 else return 0;
}

long long f(long long *a,int n)
{
	qsort(a,n,sizeof(long long),cmp);
	long long res=1;
	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			res =res*((a[j]-a[i])%MOD)%MOD;
		}
	}
	return res;
} 
int main()
{
	int n;
	scanf("%d",&n);
	int size=n+1;
	long long *x=(long long *)malloc(size*sizeof(long long));
	long long *y=(long long *)malloc(size*sizeof(long long));
	for (int i=0;i<size;i++)
	{
		scanf("%lld",&x[i]);
	}
	for (int i=0;i<size;i++)
	{
		scanf("%lld",&y[i]);
	}
	qsort(x,size,sizeof(long long),cmp);
	int flag=0;
	for (int i=0;i<size-1;i++)
	{
		if (x[i]==x[i+1])
		{
		   flag=1;
		   break; 
		}
	}
	if (!flag)
	{
		qsort(y,size,sizeof(long long),cmp);
		for (int i=0;i<size-1;i++)
		{
			if (y[i]==y[i+1])
			{
			   flag=1;
			   break; 
			}
		}
	}
	if (flag)
	{
		printf("0");
		free(x);
		free(y);
		return 0;
	}
	long long V1 =f(x, size);
	    long long V3 =f(y, size);
	    long long pairs = (long long)size * (size - 1) / 2;
	    if (pairs % 2 == 1) {
	        V3 = (MOD - V3) % MOD;
	    }
	
	    long long *fact = (long long*)malloc((n + 1) * sizeof(long long));
	    long long *inv_fact = (long long*)malloc((n + 1) * sizeof(long long));
	    fact[0] = 1;
	    for (int i = 1; i <= n; i++) {
	        fact[i] = fact[i - 1] * i % MOD;
	    }
	    inv_fact[n] = pows(fact[n],MOD - 2,MOD);
	    for (int i = n - 1; i >= 0; i--) {
	        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
	    }	
	    long long V2 = 1;
	    for (int k = 0; k <= n; k++) 
		{
	        long long C = fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
	        V2 = V2 * C % MOD;
	    }	
	    long long ans = V1 * V2 % MOD;
	    ans = ans * V3 % MOD;
	    printf("%lld\n", ans);
	    free(x);
	    free(y);
	    free(fact);
	    free(inv_fact);
	    return 0;	    
}
