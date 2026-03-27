#include <stdio.h>

int main() 
{
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) 
	{
        int atk1, pen1,atk2, pen2;
        double cr1,cd1,penratio1,cr2,cd2,penratio2,damage1,damage2;
        scanf("%d %lf %lf %lf %d", &atk1, &cr1, &cd1, &penratio1, &pen1);      
        scanf("%d %lf %lf %lf %d", &atk2, &cr2, &cd2, &penratio2, &pen2);   
        damage1 = atk1 * (1 + cr1 * cd1) / (1 + (952.8 * (1 - penratio1) - pen1) / 794);
        damage2 = atk2 * (1 + cr2 * cd2) / (1 + (952.8 * (1 - penratio2) - pen2) / 794);
        if (damage2 > damage1) 
            printf("YES\n");
		else 
            printf("NO\n");
    }

    return 0;
}
