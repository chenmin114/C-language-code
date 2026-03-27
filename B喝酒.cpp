#include <stdio.h>

int main() 
{
    int n;
    scanf("%d",&n); 
    while (n >= 3)
    {
        printf("%d bottles of beer on the wall,\n",n);
        printf("%d bottles of beer.\n",n);
        printf("Take one down and pass it around,\n");
        printf("now there's %d more bottles of beer on the wall!\n",n-1);
        n = n - 1;
    }
    if (n == 2)
    {
        printf("2 bottles of beer on the wall,\n");
        printf("2 bottles of beer.\n");
        printf("Take one down and pass it around,\n");
        printf("now there's 1 more bottle of beer on the wall!\n");
        n = n -1;
    }
    if (n == 1)
    {
        printf("1 bottle of beer on the wall,\n");
        printf("1 bottle of beer.\n");
        printf("Take one down and pass it around,\n");
        printf("there's no more bottles of beer on the wall!\n");
    }
    return 0;
    
}    
