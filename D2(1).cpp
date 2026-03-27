#include <stdio.h>

int main() 
{
    int n, m;
    scanf("%d %d", &n, &m);   
    if (m == 0) 
        printf("0\n");
    else 
        printf("%d\n", n % m);
    return 0;
}
