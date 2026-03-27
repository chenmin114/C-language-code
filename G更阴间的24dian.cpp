#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define eps 1e-10

typedef struct 
{
    double val;
    int id;
} Number;

typedef struct 
{
    char op;
    int id1, id2;
} Step;

bool found;
Step solution[3];

bool is24(double x) 
{
    if (fabs(x) < eps) 
	    return true; 
    double quotient = x / 24.0;
    double rounds = round(quotient);
    return fabs(quotient - rounds) < eps;
}

void dfs(Number nums[], int count, int step) 
{
    if (found) 
	    return;    
    if (count == 1) {
        if (is24(nums[0].val)) 
		{
            found = true;
        }
        return;
    }
    for (int i = 0; i < count; i++) 
	{
        for (int j = i + 1; j < count; j++) 
		{
            Number newnums[4];
            int newcount = 0;
            for (int k = 0; k < count; k++) 
			{
                if (k != i && k != j) 
                    newnums[newcount++] = nums[k];                
            }
            Number num1 = nums[i];
            Number num2 = nums[j];
            newnums[newcount] = (Number){num1.val + num2.val, 5 + step};
            solution[step] = (Step){'+', num1.id, num2.id};
            dfs(newnums, newcount + 1, step + 1);
            if (found) 
			    return;
            newnums[newcount] = (Number){num1.val*num2.val, 5+step};
            solution[step] = (Step){'*', num1.id, num2.id};
            dfs(newnums, newcount + 1, step + 1);
            if (found) 
			    return;
            newnums[newcount] = (Number){num1.val-num2.val, 5 + step};
            solution[step] = (Step){'-', num1.id, num2.id};
            dfs(newnums, newcount + 1, step + 1);
            if (found) 
			    return;            
            newnums[newcount] = (Number){num2.val-num1.val, 5 + step};
            solution[step] = (Step){'-', num2.id, num1.id};
            dfs(newnums, newcount + 1, step + 1);
            if (found)
			    return;
            if (fabs(num2.val) > eps) 
			{
                newnums[newcount] = (Number){num1.val / num2.val, 5 + step};
                solution[step] = (Step){'/', num1.id, num2.id};
                dfs(newnums, newcount + 1, step + 1);
                if (found) 
				    return;
            }    
            if (fabs(num1.val) > eps) 
			{
                newnums[newcount]=(Number){num2.val / num1.val, 5 + step};
                solution[step] = (Step){'/', num2.id, num1.id};
                dfs(newnums, newcount + 1, step + 1);
                if (found) 
				    return;
            }
        }
    }
}

int main() 
{
    int T;
    scanf("%d", &T);    
    while (T--) 
	{
        Number nums[4];
        for (int i = 0; i < 4; i++) 
		{
            scanf("%lf", &nums[i].val);
            nums[i].id = i + 1;
        }        
        found = false;
        dfs(nums,4,0);        
        if (found) 
		{
            printf("YE5\n");
            for (int i = 0; i < 3; i++) 
			{
                printf("%c %d %d\n",solution[i].op,solution[i].id1,solution[i].id2);
            }
        }
		else   
		{
            printf("NO\n");
        }
        if (T > 0) 
		{
            printf("\n");
        }
    }
	
    return 0;
}
