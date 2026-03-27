#include <stdio.h> 
int gcd(int n); // ½Ó¿ÚÇåÎú

int gcd(int a,int b)
{
	int r;
	if (b==0)
	    return a;
	return gcd(b,a%b);    
}
int main()
{
	int a,b,r;
	scanf("%d %d",&a,&b);
	r=gcd(a,b);
	printf("%d",r);
	return 0;
}
