#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000
void precompute(int *dp) 
{
    dp[1] = 0; 
    for (int i = 2; i <= MAX; i++) 
	{
        dp[i] = 0; 
        for (int j = 1; j * j <= i; j++) 
		{
            if (i % j == 0) 
			{
                if (j < i && !dp[i - j]) 
				{
                    dp[i] = 1; 
                    break;
                }
                int other = i / j;
                if (other < i && other != j && !dp[i - other]) 
				{
                    dp[i] = 1;
                    break;
                }
            }
        }
    }
}

int main() 
{
    int T;
    scanf("%d", &T);
    int *dp = (int*)malloc((MAX + 1) * sizeof(int));
    precompute(dp);
    for (int i = 0; i < T; i++) 
	{
        int n;
        scanf("%d", &n);
        if (dp[n]) 
		{
            printf("AN-94\n");
        } 
		else 
		{
            printf("AK-12\n");
        }
    }
    free(dp);
    return 0;
}
