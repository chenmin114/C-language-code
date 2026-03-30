#include <stdio.h>
#include <string.h>
char s[10000];

int main()
{
	long long n;
	scanf("%lld",&n);
	int len=0;
	while (n!=0)
	{
		s[len]='A'+(n-1)%26;
		len++;
		n--;
		n=n/26;
	}
	for (int i=len-1;i>=0;i--)
	{
		printf("%c",s[i]);
	}
	return 0;
}
