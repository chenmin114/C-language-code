#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int s = 0,a;
    for (int i = 0; i < n; ++i) 
	{
        scanf("%d", &a);
        s ^= a;
    }
    printf("%d\n", s);
    return 0;
}
