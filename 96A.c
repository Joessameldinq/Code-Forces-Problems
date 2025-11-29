#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main()
{
    char players[100];
    scanf(" %s",players);

    int n = strlen(players);
    int current,prev = players[0],counter = 1;
    bool dangerous = false;
    for(int i = 1 ;i < n ; i++)
    {
        current = players[i];
        if(current != prev)
            counter = 1;
        else
            counter++;
        prev = players[i];
        if(counter >=7)
            {
                dangerous = true;

            }

    }
    if(!dangerous)
        printf("NO\n");
    else
        printf("YES\n");
}