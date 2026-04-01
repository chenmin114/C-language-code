#include <stdio.h>
#include <string.h>
char x[100005],y[100005];
int min(int a,int b)
{
  return (a<b ? a:b);
}

int main()
{
  int n,m;
  scanf("%d %d",&n,&m);
  scanf("%s %s",x,y);
  int same=0,diff=0;
  for (int i=0;i<n;i++)
  {
    if(x[i]==y[i]){
      same++;
    }
    else diff++;
  }
  int ans=min(m,same)+min(n-m,diff);
  printf("%d",ans);
  return 0;
}
