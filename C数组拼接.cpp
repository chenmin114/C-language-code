#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char sum[5000005]={0};
char s[100005]={0};


int main() 
{
    int n,len =0;
    scanf("%d", &n);
    for (int i=0;i<n;i++)
    {
		scanf("%s",&s);
		int l= strlen(s);
		for (int j=0;j<l;j++)
		    sum[j+len]=s[j];
		len += l;    
	}
    int p,q;
    scanf("%d %d",&p,&q);
    char temp = sum[p-1];
    sum[p-1] = sum[q-1];
    sum[q-1] = temp;
    
    printf("%s\n", sum);
    return 0;
}
