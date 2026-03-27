#include <stdio.h>
#include <ctype.h>
#define N 26
int main()
{
    char ch;
    int upper=0, total=0, lower[N]= {0};
    while(scanf("%c", &ch) != EOF) //(ch=getchar()) != EOF
    {
        if(islower(ch))
            lower[ch-'a']++; // if ch is 'a', lower[0]++
        else if (isupper(ch))
            upper++;
        total++;
    }
    for (int i=0; i<N; i++)
    {
        if(lower[i] != 0)
            printf("%c: %d\n", i+'a', lower[i]);
    }
    printf("Upper: %d\nTotal: %d\n",upper,total);
    return 0;
} 
