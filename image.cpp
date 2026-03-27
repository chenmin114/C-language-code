#include <stdio.h>
#include <ctype.h>

int main() {
    char c,x;

    while (scanf("%c", &c) != EOF)
	{
        if ('a' <= c && c <= 'z') 
		{
			x = 'Z' - (c - 'a');
            printf("%c",x);
        } 
        else if ('A' <= c && c <= 'Z') 
		{
			x = 'z' - (c - 'A');
            printf("%c",x);
        } 

        else {
            printf("%c",c);
        }
    }
    return 0;
}
