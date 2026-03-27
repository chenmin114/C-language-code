#include <stdio.h>


int no5(int n) 
{
    if (n == 0) 
	{
        return 1;
    }
    while (n > 0) 
	{
        if (n % 10 == 5) 
		{
            return 0;
        }
        n /= 10;
    }
    return 1;
}

int main() 
{
    int n;
    scanf("%d", &n);
    int count = 0;
    for (int a = 0; a <= n; a++) 
	{
        if (!no5(a)) 
		{
            continue;
        }
        for (int b = a; b <= n - a; b++) 
		{
            if (!no5(b)) 
			{
                continue;
            }
            int c = n - a - b;
            if (c >= b && no5(c)) 
			{
                count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}
