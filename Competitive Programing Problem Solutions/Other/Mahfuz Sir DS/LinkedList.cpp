#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    node *next;
};
node *start = NULL;
void listInsert(int data)
{
    node *link = (node *)malloc(sizeof(node));
    link->data = data;
    link->next = start;

    start = link;
}
void showList()
{
    node *current = start;
    printf("\n\nList Items: ");
    while(current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void deleteFromList(int data)
{
    node *previous = NULL;
    node *current = start;
    while(current != NULL)
    {
        if(current->data == data)
        {
            if(previous == NULL)
                start = current->next;
            else
                previous->next = current->next;
        }
        previous = current;
        current = current->next;
    }
}
int main()
{
    listInsert(5);
    listInsert(4);
    listInsert(3);
    listInsert(2);
    listInsert(1);
    showList();
    deleteFromList(3);
    printf("After deleting 3:");
    showList();
    return 0;
}
