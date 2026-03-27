#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s1[15],s2[15];
int main()
{
	while (scanf("%s %s",s1,s2)!=EOF)
	{
		int len1=strlen(s1),len2=strlen(s2);
		if (len1==len2)
		{
			int i=strcmp(s1,s2);
			if (i>0)
			{
				printf("%s\n",s2);
			}
			else 
			    printf("%s\n",s1);
		}
		else 
		{
        	int i=strcmp(s1,s2);
			if (i>0)
		    {
			printf("%s\n",s1);
			}
			else 
			printf ("%s\n",s2);		  
		}
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));		
	}
	return 0;
}
