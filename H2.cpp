#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        if (n % 2 == 0)
            printf("Bob\n");
        if (n % 2 == 1)  
		    printf("Alice\n");        
    }
    return 0;
}
