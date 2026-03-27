#include<stdio.h>
#include<math.h>
int a[10003];
void sort(int[],int);
int main(){
	int n,m;
	double p,ans;
	scanf("%d%lf",&n,&p);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	} 
	sort(a,n);
	m=(int)(n*p+1e-9);
	if(fabs(m-n*p)<1e-12)
	ans=(a[m-1]+a[m])/2.0;
	else
	ans=a[m];
	printf("%.1lf",ans);
	return 0;
}
void sort(int a[],int n)
{
	int hold,num;
	for(int i=1;i<n;i++){
		num=0;
		for(int j=0;j<n-i;j++){
			if(a[j]>a[j+1]){
				hold=a[j];
				a[j]=a[j+1];
				a[j+1]=hold;
				num++;
			}
		}
		if(num==0){
			break;
		}
	}
}
