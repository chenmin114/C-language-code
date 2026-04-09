#include <stdio.h>
long long x1,x2,x3,x4,t2,t3,t4,q;
long long min(long long a,long long b)
{
    return (a>b ? b:a);
}

int main()
{
  scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&x1,&x2,&x3,&x4,&t2,&t3,&t4,&q);
  long long ans=x1*q;
  if(q>=t2){
    ans=min(ans,x2+x1*(q-t2));
  }
  else ans=min(ans,x2);
  if(q>=t3){
    ans=min(ans,x3+x1*(q-t3));
  }
  else ans=min(ans,x3);
  if(q>=t4){
    ans=min(ans,x4+x1*(q-t4));
  }
  else ans=min(ans,x4);
  if(q>=t2+t3){
    ans=min(ans,x2+x3+x1*(q-t2-t3));
  }
  else ans=min(ans,x2+x3);
  if(q>=t4+t2){
    ans=min(ans,x4+x2+x1*(q-t4-t2));
  }
  else ans=min(ans,x2+x4);
  if(q>=t4+t3){
    ans=min(ans,x4+x3+x1*(q-t4-t3));
  }
  else ans=min(ans,x3+x4);
  if(q>=t4+t3+t2){
    ans=min(ans,x4+x3+x2+x1*(q-t4-t3-t2));
  }
  else ans=min(ans,x2+x3+x4);
  printf("%lld",ans);
  return 0;
}
