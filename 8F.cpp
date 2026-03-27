#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++)
	{
	    long long L,R;
		scanf("%lld %lld",&L,&R);
		unsigned long long s=(unsigned long long)L^(unsigned long long)R;
		if (s==0)
		    printf("0\n");
		else 
		{
			s|= s>>1;
			s|= s>>2;
			s|= s>>4;
			s|= s>>8;
			s|= s>>16;
			s|= s>>32;

			printf("%llu\n",s);
		} 
	} 
	return 0;
} 
