#include <stdio.h>
#include <string.h>
int a[5005]={0};
int b[5005]={0};
int main() 
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
	{
        scanf("%d", &a[i]);
    }
    int max_len = 0;
    for (int i = 0; i < n; ++i) 
	{
        b[i] = 1; 
        for (int j = 0; j < i; ++j) 
		{
            if (a[j] <= a[i]) 
			{ 
                if (b[j] + 1 > b[i]) 
				{
                    b[i] = b[j] + 1;
                }
            }
        }
        if (b[i] > max_len) 
		{
            max_len = b[i];
        }
    }
    printf("%d\n", n - max_len);

    return 0;
}
