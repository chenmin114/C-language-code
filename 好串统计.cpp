#include<stdio.h>
#include<string.h>
char s[100005];
int main()
{
  scanf("%s",s);
  int n=strlen(s);
  int len1=0,len2=1;
  long long sum=0;
  for (int i=1;i<n;i++)
  {
    int a=(int)s[i-1],b=(int)s[i];
    if( a==b || a+1==b){
      len2++;
    }
    else {
      sum+=(long long)((len2+1)*len2)/2+len1*len2;
      len1=len2;
      len2=1;
    }
  }
  sum+=(long long)((len2+1)*len2)/2+len1*len2;
  printf("%lld",sum);
  return 0;
}
