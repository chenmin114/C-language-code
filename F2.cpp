#include<stdio.h>

int main()
{
	int a;

	while ((a = getchar()) != EOF)
	{
		if (a == '\n')
		    continue;
		if ('0' <= a && a <= '9' || 'a' <= a && a <= 'z' || 'A' <= a && a <= 'Z')
   	    {
		    printf("Lingliang likes %c!\n",a);
   	    }
   	    else 
		{ 
		    printf("Ewww\n");
		}
	}		 
	return 0;	    
}
