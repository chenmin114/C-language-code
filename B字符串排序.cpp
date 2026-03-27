#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cmp(const void *a ,const void *b)
{
    return strcmp(*(const char **)a,*(const char **)b);    		
}

int main()
{
	int n;
	scanf("%d",&n);
	char **str=(char **)malloc(n*sizeof(char *));
	for (int i=0;i<n;i++)
	{
		str[i]=(char *)malloc(1005*sizeof(char));
		scanf("%s",str[i]);
	}
	qsort(str,n,sizeof(str[0]),cmp);
	for (int i=0;i<n;i++)
	{
		printf("%s\n",str[i]);
		free(str[i]); 
	}
	free(str);
	return 0;
}
