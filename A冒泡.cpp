#include <stdio.h>



double arr[2010];
void bubbleSort(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                double temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main() 
{
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%lf", &arr[i]);
    }
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++) 
    {
        printf("%.4lf ", arr[i]);
    }
    return 0;
}
