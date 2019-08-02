#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define p              pair<int,int>
//#define ll             long long int
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
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
    void append_node();
    void delete_node(int value);
    void search_node(int value);
    void sort_node();
    void print();
    void size();
};
void List::append_node(){
    int cmd,position,value;
    node *current_node = root;
    printf("Press 1 or 2 or 3 for Element Inserted at Last or Beginning or a Particular position\n");
    scanf("%d",&cmd);
    if(cmd==1){
        Size++;
        printf("Enter an element: ");
        scanf("%d",&value);
        if(root==NULL){
            root=new node();
            root->data=value;
            root->next=NULL;
        }
        else{
            while(current_node->next!=NULL){
                current_node=current_node->next;
            }
            node *newnode=new node();
            newnode->data=value;
            newnode->next=NULL;
            current_node->next=newnode;
        }
    }
    else if(cmd==2){
        Size++;
        printf("Enter an element: ");
        scanf("%d",&value);
        if(root==NULL){
            root=new node();
            root->data=value;
            root->next=NULL;
        }
        else{
            node *newnode=new node();
            newnode->data=value;
            newnode->next=root;
            root=newnode;
        }
    }
    else if(cmd==3){
        printf("Enter the Position and an element: ");
        scanf("%d %d",&position,&value);
        node *current_node = root;
        node *previous_node;// = NULL;
        node *next_node = NULL;
        ///Creating Block.......
        node *newnode=new node();
        newnode->data=value;
        int p=0;
        while(p<position){
            if(p==Size){
                printf("Overflow\n");
                return;
            }
            previous_node=current_node;
            next_node=current_node->next;
            current_node=current_node->next;
            p++;
        }
        Size++;
        if(position==0){
            newnode->next = root;
            root = newnode;
        }
        else{
            previous_node->next=newnode;
            newnode->next=next_node;
        }
    }
    else{
        printf("Unknown Command\n");
        return;
    }
    printf("Inserted\n");
}
void List::delete_node(int value){
    node *current_node = root;
    node *previous_node = NULL;
    if(current_node==NULL){
        printf("Linked List is Empty\n");
        return;
    }
    while(current_node->data!=value){
        previous_node=current_node;
        current_node=current_node->next;
        if(current_node==NULL) break;
    }
    if(current_node==NULL){
        printf("Invalid Element\n");
    }
    else{
        Size--;
        if(current_node==root){
            node *temp_node = root;
            root = root->next;
            delete(temp_node);
        }
        else{
            previous_node->next=current_node->next;
            delete(current_node);
        }
        printf("Element Deleted\n");
    }
}
void List::search_node(int value){
    int position=0;
    node *current_node = root;
    if(current_node==NULL){
        printf("Linked List is Empty\n");
        return;
    }
    while(current_node->data!=value){
        position++;
        current_node=current_node->next;
        if(current_node==NULL) break;
    }
    if(current_node==NULL){
        printf("Invalid Element\n");
    }
    else{
        printf("Located at position %d\n",position);
    }
}
void List::sort_node(){
    int temp_value,srt;
    node *i;
    node *current_node = root;
    if(current_node==NULL){
        printf("Linked List is Empty\n");
        return;
    }
    printf("Press 1 or 2 for Ascending or Descending Order: ");
    scanf("%d",&srt);
    if(srt==1){
        while(current_node!=NULL){
            for(i=current_node->next;i!=NULL;i=i->next){
                if(current_node->data > i->data){
                    temp_value=current_node->data;
                    current_node->data=i->data;
                    i->data=temp_value;
                }
            }
            current_node=current_node->next;
        }
    }
    else if(srt==2){
        while(current_node!=NULL){
            for(i=current_node->next;i!=NULL;i=i->next){
                if(current_node->data < i->data){
                    temp_value=current_node->data;
                    current_node->data=i->data;
                    i->data=temp_value;
                }
            }
            current_node=current_node->next;
        }
    }
    else{
        printf("Unknown Command\n");
        return;
    }
    printf("Sorted\n");
}
void List::print(){
    node *current_node = root;
    if(current_node==NULL){
        printf("Linked List is Empty\n");
    }
    else{
        printf("%d",current_node->data);
        current_node=current_node->next;
        while(current_node!=NULL){
            printf("->%d",current_node->data);
            current_node=current_node->next;
        }
        printf("\n");
    }
}
void List::size(){
    if(Size==0) printf("Linked List is Empty\n");
    else printf("The Size of Linked List %d\n",Size);
}
int main(){
    List L;
    int Case,value;
    printf("#**********Linked List**********#\n");
    printf("Press 1 for Append an element\n");
    printf("Press 2 for Delete an element\n");
    printf("Press 3 for Search an element\n");
    printf("Press 4 for Sort the Linked List\n");
    printf("Press 5 for Print the Linked List\n");
    printf("Press 6 for Size of the Linked List\n");
    printf("Press 0 for Exist from Linked List\n");
    while(scanf("%d",&Case)&&Case!=0){
        switch(Case){
        case 1:
            L.append_node();
            break;
        case 2:
            printf("Enter the value to be deleted: ");
            scanf("%d",&value);
            L.delete_node(value);
            break;
        case 3:
            printf("Enter the value to be searched: ");
            scanf("%d",&value);
            L.search_node(value);
            break;
        case 4:
            L.sort_node();
            break;
        case 5:
            L.print();
            break;
        case 6:
            L.size();
            break;
        default:
            printf("Unknown Command\n");
        }
    }
    return 0;
}


