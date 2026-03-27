#include <stdio.h>

long long n(int m) {
    if (m < 3) 
	    return 0;
    long long p[35] = {0};
    p[2] = 1;
    for (int i = 3; i <= m; i++) 
	{
        for (int j = 0; j < i - 2; j++) 
		{
            p[i] += p[j + 2] * p[i - j - 1];
        }
    }
    return p[m];
}

int main() 
{
    int m;
    scanf("%d", &m);
    printf("%lld\n", n(m));
    return 0;
}
