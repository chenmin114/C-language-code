#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int main() 
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
    	int a1,b1,c1,d1,a2,b2,c2,d2;
    	long long s1,s2;
    	scanf("%d %d %d %d %d %d %d %d",&a1,&b1,&c1,&d1,&a2,&b2,&c2,&d2);
    	int x1 = max(a1,a2);
    	int x2 = min(c1,c2);
    	int x = x2 - x1;
    	if (x <= 0)
    	    x=0;
        int y1 = max(b1,b2);
		int y2 = min(d1,d2);
		int y = y2 - y1;
		if (y <= 0)
			y=0;
		s1 = x*y;
		long long s3=(long long)(c1-a1)*(d1-b1);
		long long s4=(long long)(c2-a2)*(d2-b2);
		s2 = s3 + s4 - s1;
		printf("%lld %lld\n",s1,s2);	
    }
    return 0;
}    
