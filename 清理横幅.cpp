//圣诞夜，小蓝收获了一条由大写英文字母组成的祝福横幅字符串 s。其中的字母 L,Q,BL,Q,B 是他特别喜欢的“节日字母”，他准备将它们拿去做成立体装饰，因此，他希望最终横幅中不再出现这三种字母。为了清理横幅，小蓝会重复执行一种整理操作：记当前字符串中 L,Q,B 的总出现次数为 cnt，若 cnt>0，则删除字符串中从左到右的第 cnt 个字符（下标从 1 开始），继续以上过程；若 cnt=0，整理结束。现在，请你计算，为了让最终的字符串 s 中不再包含字母 L,Q,B，最少需要执行多少次整理操作。
#include <stdio.h>
#include <string.h>
char s[100005];

int main(int argc, char *argv[])
{
  scanf("%s",s);
  int len=strlen(s),a=0;
  for (int i=len-1;i>=0;i--)
  {
    if (s[i]=='L' || s[i]=='B' || s[i]=='Q')
    {
      break;
    }
    a++;
  }
  printf("%d",len-a);
  return 0;
}
