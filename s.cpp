#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n,s;
    scanf("%d", &n);
    n = n - 1;
    while (n--)
    {    
        scanf("%d",&s);
        printf("M");
        while (s >= 1)
        {
            printf("_"); 
			s = s - 1;
        }	                
    }
    printf("M");
    return 0;
}
