#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[10005];
int f(char *s)
{
	int len=strlen(s);
	int left=0,right=len-1;
	int count=0;
	while (left<right)
	{
		if (s[left]!=s[right])
		    count++;
		left++;
		right--;    
	}
	return count;
}

int main()
{
	while (fgets(s,1000,stdin)!= NULL)
	{		 
        size_t len=strlen(s);
		if (len>0 && s[len-1]=='\n')
		{
			s[len-1]='\0';
		}
		int count=f(s);
	    printf("%d\n",count);
		
	}
	return 0;
}
