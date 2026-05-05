#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++) {       // 遍历行
        for (int j=0; j<N; j++) {   // 遍历列
            if (i==j || i+j==N-1) 
			{
                printf("+");
            } 
			else 
			{
                printf("-");
            }
        }
        printf("\n");
    }
    return 0;
}
