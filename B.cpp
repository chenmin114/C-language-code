#include <stdio.h>
#include <stdint.h>

int hash_ll(long long key) 
{
    const uint64_t mul = 11400714819323198485ULL;
    uint64_t x = (uint64_t)key;
    x *= mul;
    return (int)(x >> 32);
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;++i)
	{
		long long key,a;
		scanf("%lld",&key);
		a = hash_ll(key);
		printf("%lld\n",a);
	}
	return 0;
}
