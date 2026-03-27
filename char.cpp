#include <stdio.h>
#include <string.h>
int main()
{
char a[] = "hi";
char b[] = {'h','i'};
char *aPtr = a;
printf("%6s: %x\n", "a", a);
printf("%6s: %x\n", "b", b);
printf("%6s: %x\n", "aPtr", aPtr);
printf("%6s: %x\n", "&aPtr", &aPtr);
printf("\n%6s: %x", "abc", "abc");
printf("\n%6s: %x\n", "abcde", "abcde");
return 0;
}
