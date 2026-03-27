#include <stdio.h>
#include <ctype.h>

int main() 
{	
    int x;
    while(scanf("%d",&x) != EOF)    
        if ('0' <= x && x <= '9' || 'a' <= x && x <= 'z' || 'A' <= x && x <= 'Z') 
	    {
            printf("Lingliang likes %c!\n", x);
        } 
	    else 
	    {
           printf("Ewww\n");
        }
    
    return 0;
}	
