#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *next;
};
node *head=NULL;
void Insert_node(int value){
    node *newnode=(node*)malloc(sizeof(node));
    node *temp_node=head;
    newnode->data=value;
    newnode->next=head;
    if(head!=NULL){
        while(temp_node->next!=head){
            temp_node=temp_node->next;
        }
        temp_node->next=newnode;
    }
    else newnode->next=newnode;
    head=newnode;
}
void printList(){
    node *temp_node=head;
    if(head!=NULL){
        do{
            printf("%d ",temp_node->data);
            temp_node=temp_node->next;
        }
        while(temp_node!=head);
    }
    printf("\n");
}
int main(){
    Insert_node(12);
    Insert_node(56);
    Insert_node(2);
    Insert_node(11);
    printf("Contents of Cercular Linked List: ");
    printList();
    return 0;
}
