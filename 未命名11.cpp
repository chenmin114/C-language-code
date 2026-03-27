#include <stdio.h>

int main() {
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);
    int zheng = a / b;      
    long long rem = a % b;      
    int digits[101] = {0};     
    for (int i = 0; i <= n; ++i) 
	{
        rem *= 10;              
        digits[i] = rem / b;    
        rem = rem % b;          
    }
    if (digits[n] >= 5) 
	{
        int yu = 1;          
        for (int i = n - 1; i >= 0 && yu; --i) 
		{
            digits[i] += yu;
            if (digits[i] >= 10) 
			{
                digits[i] = 0;  
                yu = 1;      
            } 
			else 
			{
                yu = 0;      
            }
        }
        if (yu) 
		{
            zheng++;
        }
    }
    printf("%d.", zheng);
    for (int i = 0; i < n; ++i) 
	{
        printf("%d", digits[i]);
    }
    printf("\n");

    return 0;
}
