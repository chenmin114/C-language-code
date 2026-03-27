#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); 
    int lengths[1000];  
    int sum = 0;
    int max, min;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &lengths[i]); 
        sum += lengths[i];  
        max = min = lengths[0]; 
        if (lengths[i] > max) max = lengths[i];
        if (lengths[i] < min) min = lengths[i];
        
    }
    double average = (sum - max - min) * 1.0 / (n - 2);
    int t = (int)(average * 100);
    double result = t / 100.0;    
    printf("%.2f\n", result);  
    return 0;
}
