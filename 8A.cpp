#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char name[21];
    char id[19];
} Student;

int cmp(const void *a, const void *b) {
    Student *s1 = (Student *)a;
    Student *s2 = (Student *)b; 
    int gender1 = s1->id[16] - '0';
    int gender2 = s2->id[16] - '0';  
    if (gender1 % 2 != gender2 % 2) 
	{
        if (gender1 % 2 == 0) 
		    return -1;
        else 
		    return 1;
    }   
    int place = strncmp(s1->id, s2->id, 6);
    if (place != 0) 
	    return place;    
    int birth =strncmp(s1->id+6,s2->id+6,8);
    if (birth!=0)
        return birth;
    int number = strncmp(s1->id+14,s2->id+14,3);
	if (number!=0)
	    return number;
}

int main()
{
	int n;
	scanf("%d",&n);
	Student *s=(Student *)malloc(n*sizeof(Student));
	for (int i=0;i<n;i++)
	{
		
		scanf("%s %s",&s[i].name,&s[i].id);
	}
	qsort(s,n,sizeof(s[0]),cmp);
	long long sid=25700001;
	for (int i=0;i<n;i++)
	{
		printf("%lld %s\n",sid,s[i].name);
		sid++;
	}
	return 0;
	
}		    
