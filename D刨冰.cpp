#include <stdio.h>
#include <stdbool.h>

bool isprime(int n) 
{
    if (n <= 3) 
	    return true;
    if (n % 2 == 0 || n % 3 == 0) 
	    return false;
    for (int i = 5; i * i <= n; i += 6) 
	{
        if (n % i == 0 || n % (i + 2) == 0) 
		    return false;
    }
    return true;
}

int f(int n) 
{
    if (n % 2 == 0) 
	    return 2;
    for (int i = 3; i * i <= n; i += 2) 
	{
        if (n % i == 0) 
		    return i;
    }
    return n;
}


bool h(int n) 
{
    while (n % 2 == 0) 
	{
        n /= 2;
    }
    return n == 1;
}

int main() 
{
    int x;
    scanf("%d", &x);


    bool found = false;
    int ans = -1;
    int count = 0;
    int max = 114514;
    while (count < max) 
	{
        if (h(x)) 
		{
            found = true;
            ans = x;
            break;
            
        }
        if (isprime(x)) 
		{
            x = (x | (2 * x)) + 1;
        } 
		else 
		{
            int factor = f(x);
            x /= factor;
        }
        count++;
    }

    if (ans != -1) 
	{
        printf("%d %d\n", ans, count);
    } 
	else 
	{
        printf("En taro\n");
    }

    return 0;
}
