#include <stdio.h>
#include <math.h>

double dis(double x1, double y1, double z1, double x2, double y2, double z2) 
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
}

int main() 
{
    int n;
    scanf("%d", &n);
    while (n--) 
	{
        double xA, yA, zA, xB, yB, zB, xC, yC, zC;
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf", &xA, &yA, &zA, &xB, &yB, &zB, &xC, &yC, &zC);
        double BAx = xA - xB;
        double BAy = yA - yB;
        double BAz = zA - zB;
        double BCx = xC - xB;
        double BCy = yC - yB;
        double BCz = zC - zB;
        double dot = BAx * BCx + BAy * BCy + BAz * BCz;
        double lenBA = sqrt(BAx * BAx + BAy * BAy + BAz * BAz);
        double lenBC = sqrt(BCx * BCx + BCy * BCy + BCz * BCz);
        double cosb = dot / (lenBA * lenBC);
        double ans = acos(cosb);
        printf("%.5f\n", ans);
    }
    return 0;
}
