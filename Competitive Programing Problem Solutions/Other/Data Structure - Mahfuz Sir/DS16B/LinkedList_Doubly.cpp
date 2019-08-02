#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    node *next;
    node *prev;
};
node *start = NULL;
node *finish = NULL;
bool isEmpty()
{
    if(start == NULL)
        return true;
    return false;
}
void listInsert(int data)
{
    node *item = (node *)malloc(sizeof(node));
    item -> data = data;
    item -> next = start;
    item -> prev = NULL;

    if(isEmpty())
        finish = item;
    else
        start->prev = item;

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
void showReversedList()
{
    node *current = finish;
    printf("\n\nList Items: ");
    while(current != NULL)
    {
        printf("%d, ", current -> data);
        current = current -> prev;
    }
    printf("\n");
}
int main()
{
    listInsert(5);
    listInsert(4);
    listInsert(3);
    listInsert(2);
    listInsert(1);
    showList();
    showReversedList();
    return 0;
}





