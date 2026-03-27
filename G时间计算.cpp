#include <stdio.h>

int main() 
{
	int n;
	scanf("%d",&n);
	int h,m,s,need,r1,r2,remain;
	scanf("%d:%d:%d",&h,&m,&s);
	need = h * 3600 + m * 60 + s;
	for (int i = 0;i < n;i++)
	{
		int h1,m1,s1;
		scanf("%d:%d:%d",&h1,&m1,&s1);
		r1 = h1 * 3600 + m1 * 60 + s1;
		int h2,m2,s2;
		scanf("%d:%d:%d",&h2,&m2,&s2);
		r2 = h2 * 3600 + m2 * 60 + s2;
		remain = r2 - r1;
		int h3,m3,s3;
		h3 = remain / 3600;
		m3 = remain / 60 % 60;
		s3 = remain % 60;
		if (remain >= need)
		    printf("%02d:%02d:%02d Yes!\n", h3, m3, s3);
		else	
		    printf("%02d:%02d:%02d No~555~\n", h3, m3, s3);
	}
	return 0;
}	
