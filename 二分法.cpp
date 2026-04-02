#include <stdio.h>
#include <stdlib.h>
int s(int k,int n)
{
  int l=1,r=n,i=0,m=0;
  while(m!=k)
  {
    i++;
    int m=(l+r)/2;
    if(m<k){
      l=m+1;
    }
    if(m>k){
      r=m-1;
    }
    if (m==k)
    {
		break;
	}
  }
  return i;
}

int main()
{
  int n,k;
  scanf("%d %d",&n,&k);
  int ans=s(k,n);
  printf("%d",ans);
  return 0;
}
