#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;

};
node *root=NULL;

void append_node(int roll){
    if(root==NULL){
        root=new node();
        root->data=roll;
        root->next=NULL;
    }
    else{
        node *current_node=root;
        while(current_node->next!=NULL){
            current_node=current_node->next;
        }
        node *newnode=new node();
        newnode->data=roll;
        newnode->next=NULL;
        current_node->next=newnode;
    }
}

void add_node(int position,int roll){
    node *current_node=root;
    node *previous_node=NULL;
    node *next_node=NULL;
    ///Creating Block...for new node..
    node *newnode=new node();
    newnode->data=roll;
    if(position==0){
        newnode->next = root;
        root = newnode;
        return;
    }
    int p=0;
    while(p<position){
        current_node=current_node->next;
        previous_node=current_node;
        next_node=current_node->next;
        p++;
    }
    previous_node->next=newnode;
    newnode->next=next_node;
}

void delete_node(int roll){
    node *current_node=root;
    node *previous_node=NULL;
    while(current_node->data!=roll){
        previous_node=current_node;
        current_node=current_node->next;
    }
    if(current_node==root){
        node *tmp = root;
        root = root->next;
        delete(tmp);
    }
    else{
        previous_node->next=current_node->next;
        delete(current_node);
    }
}
void print(){
    node *current_node=root;
    while(current_node!=NULL){
        cout<<current_node->data<<endl;
        current_node=current_node->next;
    }
}
int main(){
    append_node(1);
    append_node(2);
    append_node(6);
    print();
    //cout<<"After deleting element from the linklist:"<<endl;
    //delete_node(2);
    //print();
    cout<<"After adding a element in linklist:"<<endl;
    add_node(2,4);
    print();

    return 0;
}
