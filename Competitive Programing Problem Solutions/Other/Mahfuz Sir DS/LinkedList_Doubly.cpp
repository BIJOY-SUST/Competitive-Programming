#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    node *next;
    node *prev;
};
node *start = NULL;
node *finish = NULL;
bool isempty()
{
    if(start == NULL)
        return true;
    return false;
}
void listInsert(int data)
{
    node *link = (node *)malloc(sizeof(node));
    link->data = data;
    link->next = start;
    link->prev = NULL;
    if(isempty())
        finish = link;
    else
        start->prev = link;
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
void showReversedList()
{
    node *current = finish;
    printf("\n\nList Items: ");
    while(current != NULL)
    {
        printf("%d ", current->data);
        current = current->prev;
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
