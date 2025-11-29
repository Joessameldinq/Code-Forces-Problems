#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 1000
int search(const char *key);

typedef struct Node
{
    char *key;
    int occurances;
    struct Node* next;

}Node;

Node *table[TABLE_SIZE];

unsigned long hash( const char *str)
{
    unsigned long h = 5381;
    int c;

    while ((c = *str++))
    {
        h = ((h<<5) +h) + c;
    }

    return h % TABLE_SIZE;
}
void insert(const char *key)
{
    unsigned long index = hash(key);
    Node *cur = table[index];

    // Step 1: Check if the key already exists
    while (cur != NULL)
    {
        if (strcmp(cur->key, key) == 0)
        {
            cur->occurances++;
            return;                     // Done, no new node needed
        }
        cur = cur->next;
    }

    // Step 2: Key not found → create a new node
    Node *newNode = malloc(sizeof(Node));
    newNode->key = malloc(strlen(key) + 1);
    strcpy(newNode->key, key);

    newNode->occurances = 1;
    newNode->next = table[index];
    table[index] = newNode;
}

int search(const char *key)
{
    unsigned long index = hash(key);

    Node *cur = table[index]; // head
    while ((cur != NULL))
    {
        if(strcmp(cur->key,key) == 0)
            return cur->occurances;
        cur = cur->next;
    }

    return 0;
    
}
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    char *temp[t];

    for(int i = 0 ; i < t ;i++)
    {
        temp[i] = (char*)malloc(33);
        scanf("%s",temp[i]);
    }
    for(int i =0 ; i < t;i++)
    {
        if(search(temp[i]) == 0)
            printf("OK\n");
        else
        {
            printf("%s%d\n",temp[i],search(temp[i]));
        }
        insert(temp[i]);
        

    }

    

    
}
