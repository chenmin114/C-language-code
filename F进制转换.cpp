#include <stdio.h>
#include <string.h>
char ans[105]={0};

int main()
{
	int a, k;
	scanf("%d %d",&a,&k);
	if (a==0)
	{
	    printf("0\n");
	    return 0;
	}
	int i=0;
    while (a>0)
	{
		int p=a%k;
		if (p<10)
		    ans[i++]=p+'0';
		else
		    ans[i++]='a'+p-10;
		a=a/k;    
		    
		        
	}
	for (int j=i-1;j>=0;j--)
	{
		printf("%c",ans[j]);
	}	
	return 0;
}
