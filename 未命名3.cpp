#include <stdio.h>
#include<string.h>
#define mod 998244353
#define max 1000001

void write(int n)
{
	if (n/9)
	    write(n/9);
	int m=n%9;
	if (m<5)
	    putchar('0'+m);
	else
		putchar('0'+m+1);    
}
int main(void)
{
	char s[max];
	scanf("%s",s);
	int n=strlen(s);
    for(int i=0;i<n;i++)
    {
	    
		write(n);
		putchar('\n');
	}
	return 0;
}
