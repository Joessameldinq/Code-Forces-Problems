#include <stdio.h>
#include <string.h>
typedef struct
{
    char request[33];
    int count;
}Record;

int main()
{
    int n;
    char temp[32];
    int index = 0;
    scanf("%d",&n);

    Record records[n];
    for(int i = 0 ; i < n ;i++)
    {
        scanf("%s",temp);
        strcpy(records[i].request,temp);
        records[i].count =0;
        for(int j = 0 ; j < i ;j++)
            if(strcmp(temp,records[j].request) == 0)
                records[i].count++; 
    }
    for(int i = 0 ;i < n;i++)
    {
        if(records[i].count == 0)
            printf("OK\n");
        else
            printf("%s%d\n",records[i].request,records[i].count);
    }

}
