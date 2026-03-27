#include <stdio.h>
unsigned long long A[33]={0};

int f(int k, unsigned long long a) 
{
    if (k == 0) 
	    return 0;
    for (int j = 0; j < k; j++) 
	{
        if (a < A[j]) 
		{
            return f(j,a) + k;
        } 
		else 
		{
            a -= A[j];
        }
    }
    return -1;
}

int main() 
{
    A[0] = 1;
    for (int i = 1; i <= 32; i++) 
	{
        A[i] = 1ULL << (i - 1);
    }
    unsigned long long n;
    scanf("%llu", &n);
    if (n == 0) 
	{
        printf("0\n");
        return 0;
    }
    int k = 0;
    while ((1ULL << k) <= n) 
	    k++;
    unsigned long long offset = n - (1ULL << (k - 1));
    int ans = f(k, offset);
    printf("%d\n", ans);
    return 0;
}
