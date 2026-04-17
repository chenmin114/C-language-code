#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;     
    int c;  
    int s;  
} Student;

int cmp(const void *a, const void *b) {
    Student *s1=(Student *)a;
    Student *s2=(Student *)b;
    if (s1->s!=s2->s) {
        return s2->s-s1->s; 
    }
    if (s1->c!=s2->c) 
	{
        return s2->c-s1->c; 
    }
    return s1->id-s2->id; 
}
Student students[305];

int main() 
{
    int n;
    Student students[305];
    scanf("%d", &n); 
    for (int i=0;i<n;i++) 
	{
        int ch,m,e;
        scanf("%d %d %d",&ch,&m,&e);
        students[i].id =i+1;         
        students[i].c=ch;        
        students[i].s=ch+m+e;  
    }
    qsort(students,n,sizeof(Student),cmp);
    for (int i = 0; i < 5; i++) {
        printf("%d %d\n", students[i].id,students[i].s);
    }
    return 0;
}
