#include <stdio.h>
#include <string.h>


int main()
{
	char s[100005];
	char result[100005];
	int k = 0;
	scanf("%s",s);
	int length = strlen(s);
	for (int i=0;i < length;i++)
	{
	    if ((s[i] >= 'A') && (s[i] <= 'Z')) 
	    s[i] = s[i] +32;
	}
	for (int j=0;j < length;j++)
	{
	    if (s[j-1] == 'a' || s[j-1] == 'e' || s[j-1] == 'i' || s[j-1] == 'o' || s[j-1] == 'u' && s[j] == 'r')
	        continue;
		else
		    result[k++] = s[j];	 
	}
	printf("%s",result);
	return 0;
}		
