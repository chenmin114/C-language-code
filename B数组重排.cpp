#include <stdio.h>

int main() 
{
    int t;
    scanf("%d", &t);
    while (t--) 
	{
        int n;
        scanf("%d", &n);
        int c0 = 0, c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++) 
		{
            int num;
            scanf("%d", &num);
            int r = num % 3;
            if (r == 0) 
			    c0++;
            else if (r == 1) 
			    c1++;
            else 
			    c2++;
        }
        int max = c0;
        if (c1 > max) 
		    max = c1;
        if (c2 > max) 
		    max = c2;
        if (2 * max <= n + 1) 
		{
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
