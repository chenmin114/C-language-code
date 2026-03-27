#include <stdio.h>
#include <ctype.h>

int main() {
    char c,x;

    while (scanf("%c", &c) != EOF)
	{
        if (islower(c)) 
		{
			x = 'Z' - (c - 'a');
            printf("%c",x);
        } 
        else if (isupper(c)) 
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
