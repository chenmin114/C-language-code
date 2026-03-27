#include <stdio.h>

int main() 
{
	long long n,sum,a;
    while (scanf("%lld", &n) != EOF) 
    {   
	    sum=0;
	    a=1;
        while (n > 0) 
		{
            long long t = n % 9;  
            if (t >= 5) 
			{
                t++;  
            }
            sum += t * a; 
            a *= 10;  
            n /= 9;     
        }
        
        printf("%lld\n", sum);  
    }
    return 0;
}
