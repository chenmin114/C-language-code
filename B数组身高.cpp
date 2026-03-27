#include<stdio.h>
#include<math.h>

void h(int a[],int n)
{
    int i,j,hold;
    for(i=1;i<n;i++)
	{
        for(j=0;j<n-i;j++)
		{
            if(a[j]>a[j+1]){
                hold=a[j];
                a[j]=a[j+1];
                a[j+1]=hold;
            }
       }
    }
}
int f(int n,double p)
{
    int i,j=0;
    for(i=0;i<=n;i++){
        if(fabs(n*p-i)<1e-8)
            j=i;
    }
    return j;
}
int main()
{
    int n,i;
    double p,ans;
    scanf("%d%lf",&n,&p);
    int x[n];
    for(i=0;i<n;i++){
        scanf("%d",&x[i]);
    }
    h(x,n);
    if(f(n,p)!=0){
        ans=(x[f(n,p)-1]+x[f(n,p)])/2.0;
        printf("%.1lf",ans);
    }
    else
    {
        int s=n*p;
        ans=x[s];
        printf("%.1lf",ans);
    }
    return 0;
}
