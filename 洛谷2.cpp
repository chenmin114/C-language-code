#include <stdio.h>
#include <stdlib.h>
int t[505], s[505], a[505],p[505]={0}; 

int cmp(const void *a, const void *b) 
{
    int i1=*(int *)a;
    int i2=*(int *)b;
    if (s[i1] != s[i2]) 
	{
        return s[i2]-s[i1]; 
    } 
	else 
	{
        return t[i1]-t[i2]; 
    }
}

int main() 
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) 
	{
        scanf("%d",&t[i]);
    }
    for (int i=0;i<n;i++) 
	{
        scanf("%d",&s[i]);
        a[i]=i; 
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int sum=0;
    for (int i=0;i<n;i++) 
	{
        for (int j=t[a[i]];j>=1;j--) 
		{
            if (p[j]==0) 
			{ 
                p[j]=1;
                sum+=s[a[i]];
                break;
            }
        }
    }
    printf("%d\n",sum);
    return 0;
}
