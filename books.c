#include <stdio.h>

int main()
{
    int n,t;
    
    scanf("%d %d",&n,&t);
    int time[n];
    for(int i = 0 ; i < n ;i++)
        scanf("%d",time+i);
        
    int sum = 0;
    int l = 0 , r = 0;
    int maxBooks = 0;
    
    for(;r < n ;r++)
    {
        sum +=time[r];
        
        while(sum > t)
        {
            sum-=time[l++];
        }
        int count = r-l+1;
        if(count > maxBooks)maxBooks = count;
    }
    
    printf("%d",maxBooks);
}