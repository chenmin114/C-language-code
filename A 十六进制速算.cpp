#include <stdio.h>
#include <string.h>
#include <ctype.h>
char line[105];

void f(char h,char* s) 
{
    int num;
    if (h>='0' && h<='9') 
	{
        num=h-'0';
    } 
	else 
	{
        num=h-'a'+ 10;
    }
    for (int i=3;i>=0;i--) 
	{
        s[3 - i]=(num & (1 << i)) ? '1' : '0';
    }
    s[4] = '\0';
}

int main() {
    int n;
    scanf("%d", &n);
    getchar(); 
    for (int i=0;i<n; i++) 
	{
        fgets(line,sizeof(line),stdin);
        char s[40]={0};
        int x=0;
        for (int j=0;line[j]!='\0';j++) 
		{
            if (isxdigit(line[j])) 
			{
                s[x++] = line[j];
            }
        }
        s[16] = '\0';       
        char bin4[5];
		for (int k = 0; k < 16; k++) {
		    f(s[k], bin4);
            printf("%s", bin4);
		    if ((k + 1) % 4 == 0 && k != 15) {
		        printf(" ");
		    }
        }
		        printf("\n");
    }
    
    return 0;
}
