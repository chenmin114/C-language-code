#include <stdio.h>
long long array[1005]={0};

void swap(long long *a,long long *b)
{
	long long temp =*a;
	*a=*b;
	*b=temp;
}

int compare(long long a, long long b) {
    return a - b;
}

void stoogeSort(long long array[], int arraySize) {
    if (compare(array[0], array[arraySize - 1]) > 0) {
        swap(&array[0], &array[arraySize - 1]);              // TODO
    }
    if (arraySize >= 3) {
        int third = arraySize / 3;
        stoogeSort(array, arraySize - third);
        stoogeSort(array + third, arraySize - third);
        stoogeSort(array, arraySize - third);
    }
}


int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%lld",&array[i]);
	}
	stoogeSort(array,n);
	for (int i=0;i<n;i++)
	{
		if (i==0)
		    printf("%lld",array[i]);
		else
		    printf(" %lld",array[i]);    
		
	}
	return 0;
	
}
