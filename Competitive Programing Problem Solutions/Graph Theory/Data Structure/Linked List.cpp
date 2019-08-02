#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *next;
    friend class List;
};
node *root=NULL;
class List{
public:
    int Size=0;
    void append_node(int roll);
    void add_node(int position,int roll);
    void delete_node(int roll);
    void print();
    int size();
};
void List::append_node(int roll){
    Size++;
    node *current_node = root;
    if(root==NULL){
        root=new node();
        root->data=roll;
        root->next=NULL;
    }
    else{
        while(current_node->next!=NULL){
            current_node=current_node->next;
        }
        node *newnode=new node();
        newnode->data=roll;
        newnode->next=NULL;
        current_node->next=newnode;
    }
}
void List::add_node(int position,int roll){
    Size++;
    node *current_node = root;
    node *previous_node = NULL;
    node *next_node = NULL;
    ///Creating Block.......
    node *newnode=new node();
    newnode->data=roll;
    int p=0;
    while(p<position){
        current_node=current_node->next;
        previous_node=current_node;
        next_node=current_node->next;
        p++;
    }
    if(position==0){
        newnode->next = root;
        root = newnode;
    }
    else{
        previous_node->next=newnode;
        newnode->next=next_node;
    }
}

void List::delete_node(int roll){
    Size--;
    node *current_node = root;
    node *previous_node = NULL;
    node *next_node = NULL;
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
void List::print(){
    node *current_node = root;
    while(current_node!=NULL){
        cout<<current_node->data<<endl;
        current_node=current_node->next;
    }
}
int List::size(){
    return Size;
}
int main(){
    List L;
    L.append_node(1);
    L.append_node(2);
    L.append_node(6);
    L.print();
    cout<<"After deleting element from the linklist:"<<endl;
    L.delete_node(2);
    L.print();
    cout<<"After adding a element in linklist:"<<endl;
    L.add_node(1,4);
    L.print();
    cout<<"The size of the list:"<<endl;
    cout<<L.size()<<endl;

    return 0;
}

