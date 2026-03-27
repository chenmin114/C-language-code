#include <stdio.h>
#include <string.h>

int main()
{
   char string[105];

   while (scanf("%s",string) != EOF)
   {
   	    if ('a'<=string[0] && string[0]<='z')
   	        string[0] = string[0]-'a'+'A';
    
        printf("%s\n",string);
   }
   return 0;    
}   
