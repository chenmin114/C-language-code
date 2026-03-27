#include <stdio.h>

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    int s = 1;
    for (int i = 0; i < n; i++) 
	{
        int score;
        scanf("%d", &score);
        if (score > x) 
		{
            s++;
        }
    }
    printf("%d\n", s);
    return 0;
}
