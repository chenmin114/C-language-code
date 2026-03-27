#include <stdio.h>
#include <string.h>
#include <ctype.h>

char s1[2010],s2[2010],key[60];

int main()
{
	gets(s1);
	int size = strlen(s1);
	for (int i=0;i<size;i++)
	{
		s2[i]=tolower(s1[i]);//存储小写字符串 
	}
	int n;
	scanf("%d",&n);
	while (n--)
	{
		scanf("%s",key);
		int len = strlen(key);
		char *p = s2; // 使用字符指针 p 指向 s2 未处理该关键词的起始处
		while ((p =strstr(p,key))!= NULL)
		{
			for (int i=0;i<len;i++)
			    s1[p-s2+i] = '*';// p - s2 是 s2 中该关键词起始位置的偏移量，将原字符串这一字符改为星号
		
		   p++;// 防止一直处理同一次出现，从下一个字符开始匹配    
	    }
	}
	printf("%s",s1);
	return 0; 
}
