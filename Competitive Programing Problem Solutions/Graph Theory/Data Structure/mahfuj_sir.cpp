#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
node *start=NULL;
void listInsert(int data){
    node *link=(node *)malloc(sizeof(node));
    link->data=data;
    link->next=start;
    start =link;
}
void showlist(){
    node *current=start;
    printf("\nList Items: ");
    while(current!=NULL){
        printf("%d",current->data);
        current =current->next;
    }
}
void deletelist(int data)
{
    node *previous=NULL;
    node *current=start;
    while(current!=NULL)
    {
        if(current->data==data)
        {
            if(previous==NULL) start=current->next;
            else previous->next=current->next;
        }
        previous=current;
        current=current->next;
    }
}
int main(){
    listInsert(5);
    listInsert(4);
    listInsert(3);
    listInsert(2);
    listInsert(1);
    showlist();
    deletelist(3);
    printf("\nAfter delete:");
    showlist();
    return 0;
}

