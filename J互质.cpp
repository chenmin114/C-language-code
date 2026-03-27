#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int mu[1000005 + 1];
int x[1000005 + 1];
int y[1000005 + 1];
int z;

void init_mobius() 
{
    memset(x, 1, sizeof(x));
    mu[1] = 1;
    z = 0;
    
    for (int i = 2; i <= 1000005; i++) 
	{
        if (x[i]) {
            y[z++] = i;
            mu[i] = -1;
        }
        
        for (int j = 0; j < z && i * y[j] <= 1000005; j++) 
		{
            x[i * y[j]] = 0;
            
            if (i % y[j] == 0) 
			{
                mu[i * y[j]] = 0;
                break;
            } 
			else 
			{
                mu[i * y[j]] = -mu[i];
            }
        }
    }
}

int main() {
    init_mobius();
    int n;
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    int* cnt = (int*)calloc(1000005 + 1, sizeof(int));
    int* c = (int*)calloc(1000005 + 1, sizeof(int));
    for (int i = 0; i < n; i++) 
	{
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    for (int d = 1; d <= 1000005; d++)
	 {
        for (int k = d; k <= 1000005; k += d) 
		{
            c[d] += cnt[k];
        }
    }
    long long ans = 0;
    for (int d = 1; d <= 1000005; d++) 
	{
        ans += (long long)mu[d] * ((long long)c[d] * (c[d] - 1) / 2);
    }
    printf("%lld\n", ans);
    free(a);
    free(cnt);
    free(c);
    return 0;
}
