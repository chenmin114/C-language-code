#include <stdio.h>

int main() 
{
	char a = -3; // 11111101 : -3
	printf("%hhd\n", a >> 1); // 1 1111110 : -2
	printf("%hhd\n", a >> 2); // 11 111111 : -1
	
}
