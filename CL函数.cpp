#include <stdio.h>


long long lucas(int a) 
{
    if (a == 0) 
	    return 2;
    if (a == 1) 
	    return 1;
    long long l0 = 2, l1 = 1, ln;
    for (int i = 2; i <= a; i++) 
	{
        ln = l1 + l0;
        l0 = l1;
        l1 = ln;
    }
    return ln;
}

int main() 
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
	{
        int x;
        scanf("%d", &x);
        printf("%lld\n", lucas(x));
    }
    return 0;
}
