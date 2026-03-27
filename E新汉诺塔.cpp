#include <stdio.h>

void hanoi(int n, char from, char to, char via);
void move(int i, char from, char to);
int main()
{
    int num,from,via,to;
    scanf("%d %d %d %d", &num,&from,&to,&via);
    hanoi(num, from, via, to);
    return 0;
}
void hanoi(int n, char from, char via, char to)
{
    if (n == 1)
    {
    move(n, from, to);
    return;
    }
    hanoi(n - 1, from, to, via); 
    move(n, from, to); 
    hanoi(n - 1, via, from, to); 
}
void move(int i, char from, char to)
{
    printf("Electromagnet move disk %d from %d to %d\n", i, from, to);
}
