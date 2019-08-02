#include<stdio.h>
#include<iostream>
using namespace std;
class List
{
private:
    class node
    {
    public:
        int data;
        node *next;
        node()
        {
            next=NULL;
        }
    };
    node *Head,*tail;
    int Size;
public:
    List();
    void append(int val);
    void add(int pos,int val);
    void Delete(int pos);
    void show();
    int size();
};
List::List()
{
    Head=tail=NULL;
    Size=0;
}
void List::append(int val)
{
    Size++;
    node *temp=new node();
    temp->data=val;
    if(Head==NULL)
    {
        Head=tail=temp;
        return;
    }
    tail->next=temp;
    tail=temp;
}
void List::add(int pos,int val)
{
    node *temp=new node();
    temp->data=val;
    if(pos==0)
    {
        Size++;
        temp->next=Head;
        Head=temp;
        return;
    }
    node *left,*right;
    right=Head;
    int p=0;
    while(right!=NULL and p<pos)
    {
        left=right;
        right=right->next;
        p++;
    }
    if(right!=NULL)
    {
        Size++;
        left->next=temp;
        left=temp;
        left->next=right;
    }
}
void List::Delete(int pos)
{
    node *temp,*left,*right;
    if(pos==0)
    {
        Size--;
        temp=Head;
        Head=Head->next;
        delete(temp);
        return;
    }
    int p=0;
    temp=Head;
    while(temp!=NULL and p<pos)
    {
        left=temp;
        temp=temp->next;
        p++;
    }
    if(temp==NULL)return;
    Size--;
    if(temp->next==NULL)
    {
        left->next=NULL;
        tail=left;
        delete(temp);
        return;
    }
    right=temp->next;
    left->next=right;
    delete(temp);
}
void List::show()
{
    node *temp=Head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int List::size()
{
    return Size;
}
int main()
{
    List L;
    L.append(1);
    L.append(2);
    L.append(100);
    L.add(0,-1);
    L.show();
    L.Delete(1);
    cout<<L.size()<<endl;
    L.show();
    return 0;
}
