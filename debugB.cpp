#include <stdio.h>

double arr[2010];

void insertSort(double arr[], int n);

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }
    insertSort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%.4lf ", arr[i]);
    }
    return 0;
}

void insertSort(double arr[], int n) {
    for (int i = 1; i < n; i++) {
        double key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
