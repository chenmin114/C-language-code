#include <stdio.h>
#include <string.h>

char a[6],b[6],c[11];  
int num[15],you[15];                          
int flag=0;              

long long match(char *str) {
    long long ans=0;
    for (int i = 0; str[i]; i++) 
	{
        ans=ans*10+num[str[i]-'0'];
    }
    return ans;
}

int check() 
{
	long long a0,b0,c0;
    if (num[a[0]-'0'] == 0|| num[b[0]-'0'] == 0 || num[c[0]-'0'] == 0) 
	    return 0;    
	a0=match(a); 
	b0=match(b); 
	c0=match(c);
    
    return a0 * b0 == c0;
}


void search(int x) 
{
    if (flag) 
	    return;    
    if (x==10) 
	{
        if (check()) 
		{
            flag=1;
            printf("%lld * %lld = %lld\n",match(a),match(b),match(c));
        }
        return;
    }
    
    for (int i=0;i<10;i++) 
	{
        if (!you[i]) 
		{
            you[i]=1;
            num[x]=i;
            search(x+1);
            you[i]=0;
        }
    }
}

int main() 
{
    scanf("%5s * %5s = %10s",a,b,c);
    memset(you, 0, sizeof(you));
    memset(num, 0, sizeof(num));   
    search(0);
    return 0;
}
