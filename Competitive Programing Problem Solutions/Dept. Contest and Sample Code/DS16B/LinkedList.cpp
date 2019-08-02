#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    node *next;
};
node *start = NULL;
void listInsert(int data)
{
    node *item = (node *)malloc(sizeof(node));
    item -> data = data;
    item -> next = start;

    start = item;
}
void showList()
{
    node *current = start;
    printf("\n\nList Items: ");
    while(current != NULL)
    {
        printf("%d, ", current -> data);
        current = current -> next;
    }
    printf("\n");
}
void deleteFromList(int data)
{
    node *current = start;
    node *previous = NULL;
    while(current != NULL)
    {
        if(current -> data == data)
        {
            if(previous == NULL)
                start = current -> next;
            else
                previous -> next = current -> next;
        }
        previous = current;
        current = current -> next;
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
    deleteFromList(2);
    deleteFromList(1);
    printf("List after deleting 3, 2\n");
    showList();
    return 0;
}
