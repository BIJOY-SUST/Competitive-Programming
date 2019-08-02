#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *next;
    node *previous;
};
node *head=NULL;
void Insert_Fast(int value){
//    node *current_node=root;
    node *newnode=(node*)malloc(sizeof(node));
//    node *newnode=new node();
    newnode->data=value;
    newnode->next=head;
    newnode->previous=NULL;
    if(head!=NULL) head->previous=newnode;
    head=newnode;
}
void Insert_after(node *previous_node,int value){
    if(previous_node==NULL){
        printf("The given previous node cannot be NULL\n");
        return;
    }
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=previous_node->next;
    previous_node->next=newnode;
    newnode->previous=previous_node;
    if(newnode->next!=NULL) newnode->next->previous=newnode;
}
void Insert_Last(int value){
    node *newnode=(node*)malloc(sizeof(node));
    node *last_node=head;
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL){
        newnode->previous=NULL;
        head=newnode;
        return;
    }
    while(last_node->next!=NULL){
        last_node=last_node->next;
    }
    last_node->next=newnode;
    newnode->previous=last_node;
}
void delete_node(node *del){
    if(head==NULL||del==NULL) return;
    if(head==del) head=del->next;
    if(del->next!=NULL) del->next->previous=del->previous;
    if(del->previous!=NULL) del->previous->next=del->next;
    free(del);
    return;
}
void printList(){
    node *check_node;
    node *current_node=head;
    printf("Traversal in forward direction: ");
    while(current_node!=NULL){
        printf(" %d ",current_node->data);
        check_node=current_node;
        current_node=current_node->next;
    }
    printf("\n");
    printf("Traversal in reverse direction: ");
    while(check_node!=NULL){
        printf(" %d ",check_node->data);
        check_node=check_node->previous;
    }
    printf("\n");
}
int main(){
    Insert_Last(6);
    Insert_Fast(7);
    Insert_Fast(1);
    Insert_Last(4);
    Insert_after(head->next,8);
    printf("Created DLL is: ");
    printList();
    delete_node(head->next->next);
    printf("After delete: ");
    printList();
    return 0;
}

