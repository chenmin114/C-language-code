#include <stdio.h>
int d[1000005];

int main() 
{
    int n, m, T;
    scanf("%d %d %d", &n, &m, &T);    
    for (int i = 0; i < n; i++) 
	{
        int s, t;
        scanf("%d %d", &s, &t);
        d[s]++;
        if (t < T) 
		    d[t]--;
    }    
    int people = 0, max = 0, best = 0;
    int start = -1, len = 0;    
    for (int t = 0; t <= T; t++) 
	{
        people += d[t];
        if (people <= m) {
            if (start == -1) 
			    start = t;
            len++;
        } else {
            if (start != -1) {
                if (len > max) {
                    max = len;
                    best = start;
                }
                start = -1;
                len = 0;
            }
        }
    }
    
    if (start != -1 && len > max) 
	{
        best = start;
    }
    
    printf("%d\n", best);
    return 0;
}
