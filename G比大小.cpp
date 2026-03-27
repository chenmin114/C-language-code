#include<stdio.h>
#include<math.h>
long long a[105]={0};

int main()
{
    int t,n,k,sign,flag;
    long long sum;
    
    scanf("%d",&t);
    for(int i=0;i<t;i++)
	{
        sum=1;
        sign=0;

        flag=0;

        scanf("%d %d",&n,&k);

        for(int j=0;j<n;j++)
		{
            scanf("%lld",&a[j]);
            if(a[j]<0)
                sign++;
        }
        for(int j=0;j<n &&flag==0;j++)
        {
 
            if(a[j]==0)
            {
                flag=1;
                if(k==0)
                    printf("=\n");
			    if(k<0)
                    printf(">\n");
                if(k>0)
                    printf("<\n");
            }
        }    
        if(sign%2==0 && flag==0)
	    {
            if(k<=0)
            {
			    printf(">\n");			
			    flag=1;
		    }
            else
		    {
                for(int j=0;j<n && flag==0;j++)
                {
                    sum*=llabs(a[j]);
                    if (sum>k)
                    {
					    printf(">\n");					
					    flag=1;
                    }
                }
                if(sum==k)
                    printf("=\n");
                if(sum<k)
                    printf("<\n");
		    }
		    
	    }
		
        if(sign%2!=0&& flag==0)
        {
            if(k>=0)
            {
			    printf("<\n");
			    flag=1;
		    }
        
            else
            {
                for(int j=0;j<n && flag==0;j++)
                {
                    sum*=llabs(a[j]);
                    if(sum>-k)
			        {
                        printf("<\n");
                        flag=1;
			        }
                }	
                if(sum==-k)
                    printf("=\n");
                if(sum<-k)
                    printf(">\n");
            }
        }
	}    
    return 0;
}    
