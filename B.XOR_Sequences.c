#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);

    while (t--)
    {
        int a , b;
        scanf("%d %d",&a,&b);
        for(int i = 0 ; i < 30;i++)
        {
            if((a& (1<<i)) != (b & (1<<i)))
            {
                printf("%d\n",1<<i);
                break;
            }
        }
    }
    
    
    

    
    
}
