#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int f(const char* A, const char* B, int len) 
{
    if (memcmp(A, B, len) == 0)
        return 1;
    if (len % 2 == 1) 
	{
        return 0;
    } 
	else 
	{
        int half = len / 2;
        if (f(A, B, half) && f(A + half, B + half, half))
            return 1;
        if (f(A, B + half, half) && f(A + half, B, half))
            return 1;
        return 0;
    }
}

int main() 
{
    int T;
    scanf("%d", &T);
    while (T--) 
	{
        char A[2005]={0}, B[2005]={0};
        scanf("%s %s", A, B);
        int lenA = strlen(A);
        int lenB = strlen(B);
        if (lenA != lenB) 
            printf("gaq\n"); 
		else 
		{
            if (f(A, B, lenA))
                printf("Mocha Parfait!\n");
            else
                printf("qaq\n");
        }
    }
    return 0;
}
