#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n, m;
    scanf("%d %d", &n, &m);
    long long **a = (long long**)malloc((n+1) * sizeof(long long*));
    for (int i = 0; i <= n; i++) 
        a[i] = (long long*)malloc((m+1) * sizeof(long long));
    for (int i = 1; i <= n; i++) 
	{
        for (int j = 1; j <= m; j++) 
		{
            scanf("%lld", &a[i][j]);
        }
    }
    long long **pref = (long long**)malloc((n+1) * sizeof(long long*));
    for (int i = 0; i <= n; i++) 
        pref[i] = (long long*)malloc((m+1) * sizeof(long long));
    for (int i = 0; i <= n; i++) pref[i][0] = 0;
    for (int j = 0; j <= m; j++) pref[0][j] = 0;
    for (int i = 1; i <= n; i++) 
	{
        for (int j = 1; j <= m; j++) 
            pref[i][j] = a[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
    }    
    int q;
    scanf("%d", &q);
    while (q--) 
	{
        int i1, j1, i2, j2;
        scanf("%d %d %d %d", &i1, &j1, &i2, &j2);       
        long long ans = pref[i2][j2] - pref[i1-1][j2] - pref[i2][j1-1] + pref[i1-1][j1-1];
        printf("%lld\n", ans);
    }
    for (int i = 0; i <= n; i++) 
	{
        free(a[i]);
        free(pref[i]);
    }
    free(a);
    free(pref);    
    return 0;
}
