#include <stdio.h>
#include <string.h>

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int k;
		char s[1005],ans[1005];
		scanf("%d",&k);
		getchar();
		gets(s);
		int l=strlen(s);
		printf("%s\n",s+l-k);
	}
	return 0;
}
