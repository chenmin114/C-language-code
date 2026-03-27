#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[505];
int a[505];

int compare(int i, int j) 
{
    while (s[i] && s[j] && s[i] == s[j]) 
	{
        i++;
        j++;
    }
    return s[i] - s[j];
}

int f(const void *a, const void *b) 
{
    int idx1 = *(int*)a - 1;  
    int idx2 = *(int*)b - 1;
    return compare(idx1, idx2);
}

int main() 
{
    scanf("%s", s);
    int n = strlen(s);   
    for (int i = 0; i < n; i++) 
	{
        a[i] = i + 1;
    }   
    qsort(a, n, sizeof(int), f);    
    for (int i = 0; i < n; i++) 
	{
        printf("%d ", a[i]);
    }
    printf("\n");
    
    return 0;
}
