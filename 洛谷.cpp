#include <stdio.h>
#include <math.h>

int main() 
{
    long long n,i;
    int flag=1;   
    scanf("%lld",&n);
    if (n%2==0) 
	{
        int count=0;
        while (n%2==0) 
		{
            count++;
            n/=2;
        }
        if (count==1) 
		{
            printf("2");
        } 
		else 
		{
            printf("2^%d",count);
        }
        flag= 0;
    }
    for (i=3;i*i<=n;i+=2)
	{
        if (n%i==0) 
		{
            int count=0;
            while (n%i==0) 
			{
                count++;
                n/=i;
            }
            if (!flag) 
			{
                printf(" * ");
            }
            if (count==1)
			{
                printf("%lld", i);
            } 
			else 
			{
                printf("%lld^%d", i, count);
            }
            flag=0;
        }
    }
    if (n > 1) 
	{
        if (!flag) 
		{
            printf(" * ");
        }
        printf("%lld",n);
    } 
    return 0;
}
