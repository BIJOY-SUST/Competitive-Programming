#include <stdio.h>
#include <stdlib.h>
struct Node{
  int data;
  struct Node *next;
};
Node *head=NULL;
void push(int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = head;
    head    = new_node;
}
//void insertAfter(struct Node* prev_node, int new_data){
//    if (prev_node == NULL){
//      printf("the given previous node cannot be NULL");
//      return;
//    }
//    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
//    new_node->data  = new_data;
//    new_node->next = prev_node->next;
//    prev_node->next = new_node;
//}
//void append(struct Node** head_ref, int new_data){
//    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
//    struct Node *last = *head_ref;
//    new_node->data  = new_data;
//    new_node->next = NULL;
//    if (*head_ref == NULL){
//       *head_ref = new_node;
//       return;
//    }
//    while (last->next != NULL)
//        last = last->next;
//    last->next = new_node;
//    return;
//}

// This function prints contents of linked list starting from head
void printList(struct Node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}

/* Driver program to test above functions*/
int main()
{
  /* Start with the empty list */
//  struct Node* head = NULL;

  // Insert 6.  So linked list becomes 6->NULL
//  append(&head, 6);

  // Insert 7 at the beginning. So linked list becomes 7->6->NULL
  push( 7);

  // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
  push( 1);

  // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
//  append(&head, 4);
//
//  // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
//  insertAfter(head->next, 8);

  printf("\n Created Linked list is: ");
  printList(head);

  return 0;
}
