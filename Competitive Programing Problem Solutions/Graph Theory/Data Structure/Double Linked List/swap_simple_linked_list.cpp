#include<bits/stdc++.h>
using namespace std;
//int c=0;
class node{
public:
    int data;
    node *next;
};
node *head = NULL;
void swapnodes(int x,int y){
    if(x==y) return;
    node *prevx=NULL,*currentx=head;
    while(currentx&&currentx->data!=x){
        prevx=currentx;
        currentx=currentx->next;
    }
    node *prevy=NULL,*currenty=head;
    while(currenty&&currenty->data!=y){
        prevy=currenty;
        currenty=currenty->next;
    }
    if(currentx==NULL||currenty==NULL){
        return;
    }
    if(prevx!=NULL) prevx->next=currenty;
    else head=currenty;
    if(prevy!=NULL) prevy->next=currentx;
    else head=currentx;
    node *temp_node=currenty->next;
    currenty->next=currentx->next;
    currentx->next=temp_node;
}
void Insert(int value){
//    c++;
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=head;
    head=newnode;
}
void printList(){
    node *current_node=head;
    while(current_node!=NULL){
        printf("%d ",current_node->data);
        current_node=current_node->next;
    }
}
int main(){
    Insert(9);
    Insert(1);
    Insert(3);
    Insert(2);
    Insert(6);
    Insert(8);
//    cout<<c<<endl;
    printf("Linked List before calling swapnodes() ");
    printList();
    swapnodes(6,1);
    printf("Linked List after calling swapnodes() ");
    printList();
    return 0;
}
