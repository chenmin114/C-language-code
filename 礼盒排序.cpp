#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int id;         
    int total;      
    int max_price;  
    int min_price;  
} Box;

int compare(const void *a, const void *b) {
    Box *boxA = (Box *)a;
    Box *boxB = (Box *)b;
    if (boxA->total!=boxB->total)     return boxA->total-boxB->total;
    if (boxA->max_price!=boxB->max_price)     return boxA->max_price-boxB->max_price;
    if (boxA->min_price!=boxB->min_price)     return boxA->min_price - boxB->min_price;
    return boxA->id-boxB->id;
}

int main() 
{
    int n,k;
    scanf("%d %d", &n, &k);
    Box boxes[1005]; 
    for (int i=0;i<n;i++) 
	{
        boxes[i].id=i+1; 
        boxes[i].total=0;
        boxes[i].max_price=-1; 
        boxes[i].min_price=100000; 
        for (int j=0;j<k;j++) 
		{
            int price;
            scanf("%d",&price);
            boxes[i].total+=price;
            if (price>boxes[i].max_price) {
                boxes[i].max_price=price;
            }
            if (price<boxes[i].min_price) {
                boxes[i].min_price=price;
            }
        }
    }
    qsort(boxes,n,sizeof(Box),compare);
    for (int i = 0; i < n; i++) 
	{
        printf("%d",boxes[i].id);
        if (i<n-1) 
		{
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
