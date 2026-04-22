#include <stdio.h>
#include <stdlib.h>
#define MAX_N 10005

typedef struct {
    int id;        
    int c,m,e;    
    int sum;      
    int cm;     
    int cmmax;     
    int rank;       
} Student;

Student students[10005];
int compare(const void *a, const void *b) {
    Student *s1=(Student *)a;
    Student *s2=(Student *)b;
    if (s1->sum!=s2->sum) 
	{
        return s2->sum-s1->sum;
    }
    if (s1->cm!=s2->cm) 
	{
        return s2->cm-s1->cm;
    }
    if (s1->cmmax!=s2->cmmax) {
        return s2->cmmax-s1->cmmax;
    }
    return 0;
}

int main() 
{
    int N;
    scanf("%d",&N);
    for (int i=0;i<N;i++) 
	{
        students[i].id=i;
        scanf("%d %d %d",&students[i].c,&students[i].m,&students[i].e);
        students[i].sum=students[i].c+students[i].m+students[i].e;
        students[i].cm=students[i].c+students[i].m;
        students[i].cmmax=(students[i].c>students[i].m) ? students[i].c: students[i].m;
    }
    qsort(students,N,sizeof(Student),compare);
    for (int i=0;i<N;i++) 
	{
        if (i==0){
            students[i].rank=1;
        } 
		else{
            Student *cur=&students[i];
            Student *pre=&students[i-1];
            // 判断是否与上一名并列 (三项指标完全相同)
            if (cur->sum== pre->sum && cur->cm==pre->cm && cur->cmmax==pre->cmmax) 
				{
                cur->rank=pre->rank;
            } else {
                cur->rank=i+1;
            }
        }
    }
    int ranks[10005];
    for (int i=0;i<N;i++){
        ranks[students[i].id]=students[i].rank;
    }
    for (int i=0;i<N;i++){
        printf("%d\n",ranks[i]);
    }
    return 0;
}
