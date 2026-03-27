#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);

        int sign = 1; 
        int zero = 0;
        long long mag = 1; 
		int flag=0; 
		int x[105];
        for (int i = 0; i < n; i++) 
        {
            scanf("%d", &x[i]);
        }
		for (int i = 0; i < n; i++) 
		{    
            if (x[i] == 0) 
            {
                zero = 1;
            }
		}
        if (zero) 
		{
	        if (k == 0) printf("=\n");
	        else if (k > 0) printf("<\n");
	        else printf(">\n");
	        continue;
		}
		for (int i = 0; i < n; i++)
		{ 
            if (x[i] < 0) 
            {
                sign = -sign;
            }
            int abs_x = x[i] < 0 ? -x[i] : x[i];
            if (mag <= 1000000) 
            {
                mag *= abs_x; 
                if (mag > 1000000) 
				{
					flag=1;
				}	
            }
		} 
        if (sign > 0) 
        {
            if (flag) 
            {
                printf(">\n");
            } 
            else 
            {
                long long prod = mag;
                if (prod == k) printf("=\n");
                else if (prod > k) printf(">\n");
                else printf("<\n");
            }
        } 
        else 
        {
            if (flag) 
            {
                printf("<\n");
            } 
            else 
            {
                long long prod = -mag;
                if (prod == k) printf("=\n");
                else if (prod > k) printf(">\n");
                else printf("<\n");
            }
        }
    }
    return 0;
}
