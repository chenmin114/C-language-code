#include <stdio.h>
#include <stdint.h>

int even(uint64_t data, int count) 
{
    int t = 0;
    for (int i=0;i<count;i++) 
	{
        if (data & (1ULL<<i)) 
            t++;
    }
    return t % 2;
}

int main() 
{
    int n;
    scanf("%d",&n);
    int a[57];
    int x = 0;
    for (int i = 0; i < 64; i++) 
	{
        if (i!=0 && i!=1 && i!=2 && i!=4 && i!=8 && i!=16 && i!=32) 
		{
            a[x++]=i;
        }
    }    
    for (int i=0;i< n;i++) 
	{
        uint64_t n;
        scanf("%llu", &n);        
        uint64_t d=0;
        for (int j=0;j<57;j++) 
		{
            if (n & (1ULL<<j)) 
                d |= (1ULL<<a[j]);
        }
        uint64_t mask1 = 0;
        for (int j= 1; j< 64;j++) 
		{
            if (j!= 1 && (j & 1)) 
			{  
                mask1^=(d>>j) & 1;
            }
        }
        if (mask1)d |= (1ULL<<1);
        uint64_t mask2 = 0;
        for (int j=1;j<64;j++) 
		{
            if (j!= 2 && (j& 2)) 
			{ 
                mask2^=(d>>j) & 1;
            }
        }
        if (mask2)d |= (1ULL<<2);
        uint64_t mask4 = 0;
        for (int j= 1;j< 64;j++) 
		{
        	
            if (j!=4 && (j&4)) 
			{  
                mask4^=(d >>j) & 1;
            }
        }
        if (mask4)d |= (1ULL<<4);
        uint64_t mask8 = 0;
        for (int j= 1;j< 64;j++) 
		{
            if (j!= 8 && (j& 8)) 
			{ 
                mask8^=(d >>j) & 1;
            }
        }
        if (mask8)d |= (1ULL << 8);
        uint64_t mask16 = 0;
        for (int j= 1;j< 64;j++) 
		{
            if (j!= 16 && (j& 16)) 
			{  
                mask16^=(d >>j) & 1;
            }
        }
        if (mask16)d |= (1ULL << 16);
        uint64_t mask32 = 0;
        for (int j= 1;j< 64;j++) 
		{
            if (j!= 32 && (j & 32)) 
			{  
                mask32^=(d >>j) & 1;
            }
        }
        if (mask32)d |= (1ULL << 32);
        uint64_t mask0 = 0;
        for (int j= 1;j< 64;j++) 
		{
            mask0 ^=(d >>j) & 1;
        }
        if (mask0)d |= 1ULL;
        
        printf("%llu\n",d);
    }
    
    return 0;
}
