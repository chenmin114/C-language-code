#include <stdio.h>
#include <stdlib.h> 
int a[105]={0};
int main() 
{
    int T;
    scanf("%d", &T);

    while (T--) 
	{
        int n;
        int k;
        scanf("%d %d", &n, &k);
        long long sum = 1;  
        int sign = 1;           
        int zero = 0;             
        for (int i = 0; i < n; i++) 
		{
            scanf("%d", &a[i]); 
		
            if (a[i] == 0) 
			{
                zero = 1;
                continue; 
            }
		}
		if (zero) 
		{
		    if (k == 0) 
			{
		        printf("=\n");
		    } 
			else if (k < 0) 
			{
		        printf(">\n"); 
		    } 
			else 
			{ 
		        printf("<\n");
		    }
		} 
		else
		{
			for (int i = 0; i < n; i++)
			{
				sum *= abs(a[i]);
				if (a[i] < 0) 
				{
				    sign *= -1;
				}
				if (sum > abs(k)) 
				{
				    if (sign == 1)
					{
				        printf(">\n");
				    } 
					else 
					{
				        printf("<\n");
				    }
				}    
			}			   
            if (sum==abs(k) && ((sign == 1 && k> 0) || (sign ==-1 && k<0)))
            {
				printf("=\n");
			}
            if (sum < abs(k))
			{
				if (k > 0)
				    printf("<\n");
				else
				    printf(">\n");    
			}    
            
        }
	}

    return 0;
}
