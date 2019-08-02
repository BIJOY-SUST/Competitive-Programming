#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *left,*right;
    node(){
        left=NULL;
        right=NULL;
    }
};
node *root,*tail;
void insert(int roll){
    if(root==NULL){
        root=new node();
        root->data=roll;
    }
    else{
        node *current_node=root,*parent;
        while(current_node!=NULL){
            if(roll<current_node->data){
                parent=current_node;
                current_node=current_node->left;
            }
            else{
                parent=current_node;
                current_node=current_node->right;
            }
        }
        node *newnode=new node();
        newnode->data=roll;
        if(newnode->data<parent->data){
            parent->left=newnode;
        }
        else{
            parent->right=newnode;
        }
    }
}
void print(node *current_node){
    if(current_node==NULL){
        return;
    }
    cout<<current_node->data<<endl;
    print(current_node->left);
    print(current_node->right);
}
int main(){
    insert(1);
    insert(2);
    insert(9);
    insert(3);
    insert(5);
    insert(8);
    insert(6);
    print(root);
    return 0;
}
