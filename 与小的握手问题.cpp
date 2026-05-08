#include <stdio.h>
#include <stdlib.h>

int arr[300005];
int temp[300005];
long long total=0; // 使用 long long 防止溢出

// 归并排序并统计顺序对 (前面的数 < 后面的数)
void merge_sort(int left, int right) {
    if (left>=right) return;
    int mid=left+(right-left)/2;
    merge_sort(left,mid);
    merge_sort(mid+1,right);
    // 合并过程
    int i=left;      // 左半部分指针
    int j=mid+1;   // 右半部分指针
    int k=left;      // 临时数组指针
    while (i<=mid && j<=right) 
	{
        // 如果左边的数 <= 右边的数
        // 说明 arr[i] 比右边从 j 到 right 的所有数都小
        // 这些构成了顺序对
        if (arr[i]<=arr[j]) {
            temp[k++]=arr[i++];
            // 核心统计逻辑：
            // arr[i] (当前的左元素) 小于 right 数组中剩余的所有元素 (从 j 到 right)
            total+=(right-j+1);
        } 
		else {
            // 如果左边的数 > 右边的数，不构成顺序对，直接放入
            temp[k++]=arr[j++];
        }
    }
    // 处理剩余元素
    while (i<=mid) 
	{
        temp[k++] = arr[i++];
        // 右边已经空了，没有比它大的在后面了，不需要加
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    // 将排序好的部分复制回原数组
    for (i=left;i<=right;i++) {
        arr[i]=temp[i];
    }
}

int main() 
{
    int N;
    scanf("%d", &N);
    for (int i=0;i<N;i++) 
	{
        scanf("%d",&arr[i]);
    }
    merge_sort(0,N-1);
    printf("%lld\n", total);
    return 0;
}
