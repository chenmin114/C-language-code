#include <stdio.h>
#include <ctype.h>

int found(char p)
{
	p=tolower(p);
	if (p=='a'||p=='e'||p=='i'||p=='o'||p=='u')
	    return 1;
	return 0;    
}

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	while (n--)
	{
		char s;
		int count=0;
		int ji=0,ou=0;
		while ((s=getchar())!= '\n' && s!= EOF) 
		{
			if(found(s))
			{
				count++;
			}
			else 
			{
			    if(count!=0)
			    {
				    if (count%2==1)
				        ji++;
				    else ou++;
				    count=0;    
			    }
			}
		}
		if (count!=0)
		{
			if (count%2==1)
				ji++;
			else ou++;
		}	
	    if (ji>ou)
	    {
		    printf("Turing Complete!\n");
	    }
	    else printf("Ex Machina\n");
	}
	return 0;
}
