#include <stdio.h>
#include <stdlib.h>
#define mod 100003

int main() 
{
    int N, K;
    scanf("%d %d", &N, &K);    
    int *d = (int*)malloc((N + 1) * sizeof(int));
    int *s = (int*)malloc((N + 1) * sizeof(int));
    d[0] = 1;
    s[0] = 1;   
    for (int i = 1; i <= N; i++) 
	{
        if (i <= K) {
            d[i] = s[i - 1] % mod;
        } else {
            d[i] = (s[i - 1] - s[i - K - 1] + mod) % mod;
        }
        s[i] = (s[i - 1] + d[i]) % mod;
    }    
    printf("%d\n", d[N]);   
    free(d);
    free(s);
    return 0;
}
