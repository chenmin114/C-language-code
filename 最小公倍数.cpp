#include <stdio.h>

int main()
{
	int a, b, GCD, LCM;
	scanf("%d%d", &a, &b);
	LCM = a * b; // 这行不能少
	while((GCD = a%b) != 0)
	{
	    a = b;
	    b = GCD;
	}
	GCD = b;
	LCM = LCM/GCD;
	//不能写成(a*b)/GCD，因a和b已被修改（在计算GCD的过程中）
	printf("%d", LCM);
	return 0;
}
