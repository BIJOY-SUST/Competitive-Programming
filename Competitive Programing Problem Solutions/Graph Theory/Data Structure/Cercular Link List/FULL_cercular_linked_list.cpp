#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *next;
};
node *last = NULL;
void addempty(int value){
    if(last!=NULL){
        printf("The Cercular Linked List isnot Empty\n");
        return;
    }
    node *temp_node=(node*)malloc(sizeof(node));
    temp_node->data=value;
    last=temp_node;
    temp_node->next=temp_node;
}
void addbegin(int value){
    if(last==NULL){
        addempty(value);
        return;
    }
    node *temp_node=(node*)malloc(sizeof(node));
    temp_node->data=value;
    temp_node->next=last->next;
    last->next=temp_node;
}
void addend(int value){
    if(last==NULL){
        addempty(value);
        return;
    }
    node *temp_node=(node*)malloc(sizeof(node));
    temp_node->data=value;
    temp_node->next=last->next;
    last->next=temp_node;
    last=temp_node;
}
void addafter(int previous,int value){
    if(last==NULL) return;
    node *p;
    p=last->next;
    do{
        if(p->data==previous){
            node *temp_node=(node*)malloc(sizeof(node));
            temp_node->data=value;
            temp_node->next=p->next;
            p->next=temp_node;
            if(p==last) last=temp_node;
            return;
        }
        p=p->next;
    }while(p!=last->next);
    printf("%d not present in the list\n",previous);
}
void traverse(){
    node *p;
    if(last==NULL){
        printf("List is empty\n");
        return;
    }
    p=last->next;
    do{
        printf("%d ",p->data);
        p=p->next;
    }
    while(p!=last->next);
}
int main(){
    addempty(6);
    addbegin(4);
    addbegin(2);
    addend(8);
    addend(12);
    addafter(8,10);
    traverse();
    return 0;
}
