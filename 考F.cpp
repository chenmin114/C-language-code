#include <stdio.h>
#include <string.h>
char s[200005];

int check(int len)
{
	char *p=s,*q=s+len-1;
	while (p<q)
	{
		if((*p=='x' && *q=='x')||(*p=='o' && *q=='o')||(*p=='v' && *q=='v')||(*p=='w' && *q=='w')||(*p=='b' && *q=='d')||(*p=='d' && *q=='b')||(*p=='p' && *q=='q')||(*p=='q' && *q=='p'))
		{
			p++;
			q--;
		}
		else return 0;
	}
	if (p==q)
	{
		if (*p=='o' || *p=='v' ||*p=='w' ||*p=='x')
		    return 1;
		else return 0;
	}
	return 1;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",s);
		int len=strlen(s);
		if (check(len))
		    printf("yes\n");
		else printf("no\n");    
	}
	return 0;
}
