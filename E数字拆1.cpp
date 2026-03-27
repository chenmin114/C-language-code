#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* f(int x) 
{
    if (x == 1) 
	{
        char* res = (char*)malloc(3 * sizeof(char));
        sprintf(res, "1");
        return res;
    }
    char* left = NULL;
    char* right = NULL;
    char* mid = NULL;
    char* res = NULL;
    if (x % 2 == 1) 
	{  
        int half = (x - 1) / 2;
        left = f(half);
        mid = f(1);
        right = f(half);
        int left1 = strlen(left);
        int mid1 = strlen(mid);
        int right1 = strlen(right);
        res = (char*)malloc((left1 + mid1 + right1 + 4) * sizeof(char));
        sprintf(res, "(%s+%s+%s)", left, mid, right);

        free(left);
        free(mid);
        free(right);
    } 
	else 
	{  
        int half = x / 2;
        left = f(half);
        right = f(half);
        int left1 = strlen(left);
        int right1 = strlen(right);
        res = (char*)malloc((left1 +right1 + 3) * sizeof(char));
        sprintf(res, "(%s+%s)", left, right);
        free(left);
        free(right);
    }
    return res;
}

int main() 
{
    int t;
    scanf("%d", &t);
    while (t--) 
	{
        int n;
        scanf("%d", &n);
        char* ans = f(n);
        printf("%s\n", ans);
        free(ans);
    }

    return 0;
}
