#include <stdio.h>

int main() 
{
    int n, k;
    scanf("%d %d", &n, &k);
    int a[100];
    int p[100];
    for (int i = 0; i < n; i++) 
	{
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < k; i++) 
	{
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < k; i++) 
	{
        a[p[i] - 1] = 0;
    }
    for (int i = 0; i < n; i++) 
	{
        printf("%d ", a[i]);
    }
    return 0;
}	 
