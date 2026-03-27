#include<stdio.h>
int main(){
    int t,a,b,c;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&b,&c);

        if(b<c||(b-c)&1==1)
		    printf("Designant.\n");
        else{
            a=0;
            int tmp=(b-c)>>1;
            int flag=1;
            for(int i=0;i<=30;i++){
                if((tmp>>i)&1){
                    if((c>>i)&1)
					    flag=0;
                    else 
					    a|=(1<<i);
                }
                else if((c>>i)&1)
				    a|=(1<<i);
            }
            if(flag)
			    printf("%d\n",a);
            else 
			    printf("Designant.\n");
        }
    }
return 0;
}
