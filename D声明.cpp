#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[110];
typedef long long ll;
void run() {
    scanf(" ");
    gets(s);
    int n=strlen(s);
    ll sz=0;
    if(s[0]=='c') sz=1;
    if(s[0]=='s') sz=2;
    if(s[0]=='i') sz=4;
    if(s[0]=='l') sz=8;
    int pos=0;
    while(s[pos]!='[') 
	    pos++;
    pos++;
    int a=0;
    while(s[pos]!=']') {
        a=10*a+s[pos]-'0';
        pos++;
    }
    ll ans=sz*a;
    if(ans>=(1<<30)){
        printf("%lldGB ",ans/(1<<30));
        ans%=(1<<30);
    }
    if(ans>=(1<<20)){
        printf("%lldMB ",ans/(1<<20));
        ans%=(1<<20);
    }
    if(ans>=(1<<10)){
        printf("%lldKB ",ans/(1<<10));
        ans%=(1<<10);
    }
    if(ans>=(1<<0)){
        printf("%lldB ",ans/(1<<0));
        ans%=(1<<0);
    }
    printf("\n");
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--) run();
    return 0;
}
