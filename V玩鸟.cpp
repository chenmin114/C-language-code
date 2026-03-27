#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_T 2000

int is_digit(char c) 
{
    return c >= '1' && c <= '9';
}


double get_obstacle_value(char c, int is_up) 
{
    if (c == '*') return is_up ? 100.0 : -100.0;
    if (is_digit(c)) return (c - '0') * 10.0 * (is_up ? 1.0 : -1.0);
    return is_up ? 100.0 : -100.0; 
}

int main() 
{
    int T;
    double g, v0;
    scanf("%d %lf %lf", &T, &g, &v0);
    char up[MAX_T + 5], down[MAX_T + 5], op[MAX_T + 5];
    scanf("%s", up);
    scanf("%s", down);
    scanf("%s", op);
    double y = 0.0, v = 0.0; 
    int k_count = 0; 
    for (int i = 0; i < T; i++) 
	{
        if (op[i] == 'K') 
		{
            v = v0; 
            k_count++;
        }
        double up_edge = get_obstacle_value(up[i], 1);
        double down_edge = get_obstacle_value(down[i], 0);
        int collision = 0;
        double t_peak = 0.0;
        int has_peak = 0;
        if (v > 0 && g > 0) 
		{
            t_peak = v / g; 
            if (t_peak > 0 && t_peak < 1.0)
			{
                has_peak = 1;
            }
        }
        if (has_peak) 
		{
            double y_start = y;
            double v_start = v;
            double y_peak = y_start + v_start * t_peak - 0.5 * g * t_peak * t_peak;
            double v_peak = v_start - g * t_peak;
            if (y_start > up_edge || y_start < down_edge || 
                y_start > 100 || y_start < -100 ||
                y_peak > up_edge || y_peak < down_edge ||
                y_peak > 100 || y_peak < -100) 
			{
                collision = 1;
            }
            if (!collision) 
			{
                double t_second = 1.0 - t_peak;
                double y_end = y_peak + v_peak * t_second - 0.5 * g * t_second * t_second;
                double v_end = v_peak - g * t_second;
                if (y_end > up_edge || y_end < down_edge ||
                    y_end > 100 || y_end < -100)
				{
                    collision = 1;
                }
            }
        } 
		else 
		{
            double y_end = y + v * 1.0 - 0.5 * g * 1.0;
            double v_end = v - g;
            if (y > up_edge || y < down_edge || y > 100 || y < -100 ||
                y_end > up_edge || y_end < down_edge || y_end > 100 || y_end < -100) 
			{
                collision = 1;
            }
        }
        if (collision) 
		{
            printf("Failed! (%d)\n", i + 1);
            return 0;
        }
        y = y + v * 1.0 - 0.5 * g * 1.0;
        v = v - g;
    }
    printf("Alive! (%d)\n", k_count);
    return 0;
}
