#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

int hashtable[10];

void insert()
{
    int key;
    int value;
    int hkey;
    int index;
    printf("enter the value to be inserted\n");
    scanf("%d", &key);
    hkey = key % TABLE_SIZE;

    if (hashtable[hkey] == NULL)
    {
        hashtable[hkey] = key;
        // printf("%d",hkey);
        printf("Value inserted\n");
    }

    else if (hashtable[hkey] != NULL)
    {
        for(int i=0;i< TABLE_SIZE; i++){
            index = (hkey + i) % TABLE_SIZE;
            if(hashtable[index]==NULL){
                hashtable[index] = key;
                printf("Value inserted\n");
                return;
            }
        }
        printf("Table is full\n");
       
    }
}
void search()
{
    int search_value;
    printf("Enter the value you want to search\n");
    scanf("%d", &search_value);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashtable[i] == search_value)
        {
            printf("Your value is at index %d \n", i);
        }
        else
        {
            printf("Value not found\n");
        }
    }
}

void display()
{

    int i;

    printf("\nelements in the hash table are \n");

    for (i = 0; i < TABLE_SIZE; i++){
        printf("value =  %d\n", hashtable[i]);
    }

        
}

int main(){
    int opt,i;
    for (int i = 0; i < 10; i++)
    {
        hashtable[i] == NULL;
    }
    while(1){
         printf("\nPress 1. Insert\t 2. Display \t3. Search \t4.Exit \n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:exit(0);
        }
    }
}