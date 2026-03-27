#include <stdio.h>
int a[105];
int main(){
int t;
scanf("%d",&t);
while(t--){
int n,k;
scanf("%d%d",&n,&k);
for(int i=1;i<=n;i++)
scanf("%d",&a[i]);
// 寻找0
int found0=0;
for(int i=1;i<=n;i++)
if(a[i]==0) found0=1;
if(found0){ // if(statement) 等价于 if((statement)!=0)
if(0<k) printf("<\n");
else if(0>k) printf(">\n");
else printf("=\n");
continue;
}
// 计算答案正负
int negative_count=0;
for(int i=1;i<=n;i++)
if(0>a[i]) negative_count++;
// 无论是正数还是负数，我都先看看会不会溢出
int product=1;
int overflow=0;
for(int i=1;i<=n;i++){
product*=a[i];
if(product<-1000000||product>+1000000){
overflow=1;
break;
}
}
// 先看看溢出了没有
if(overflow){
// 溢出了。这意味着乘积的绝对值应该会超过k的绝对值。
if(negative_count%2==0){
// +
printf(">\n");
} else {
// -
printf("<\n");
}
} else {
// 太棒了没溢出，直接比较即可
if(product<k) printf("<\n");
else if(product>k) printf(">\n");
else printf("=\n");
}
}
return 0;
}
