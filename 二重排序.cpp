#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long h; 
    long long w; 
} Student;

Student students[100005];
Student temp[100005];
long long swap_count=0; 

int cmp(Student a, Student b) {
    if (a.h!=b.h) {
        return a.h>b.h;
    }
    return a.w>b.w;
}

// 归并排序计算逆序对
void merge_sort(int left,int right) {
    if (left >= right) return;
    int mid=left+(right-left)/2;
    merge_sort(left,mid);
    merge_sort(mid+1,right);
    int i=left;
    int j=mid+1;
    int k=left;
    while (i<=mid && j<=right) {
        // 如果左边的元素应该排在右边元素的前面（或者相等），则不构成逆序
        if (cmp(students[i],students[j])) {
            temp[k++]=students[i++];
        } else {
            // 如果右边的元素应该排在左边元素的前面
            // 说明 students[i...mid] 这些元素都相对于 students[j] 是逆序的
            temp[k++]=students[j++];
            swap_count+=(mid-i+1);
        }
    }
    while (i<=mid) {
        temp[k++]=students[i++];
    }
    while (j<=right) {
        temp[k++]=students[j++];
    }
    for (i=left;i<=right;i++) {
        students[i]=temp[i];
    }
}

int main() 
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) 
	{
        scanf("%d %d",&students[i].h,&students[i].w);
    }
    merge_sort(0,n-1);
    printf("%lld\n",swap_count);
    return 0;
}
