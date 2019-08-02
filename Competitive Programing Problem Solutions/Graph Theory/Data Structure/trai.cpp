#include<bits/stdc++.h>
using namespace std;
class node{
public:
    bool endmark;
    node *next[26+1];
    node(){
        endmark = false;
        for(int i=0;i<26;i++){
            next[i] = NULL;
        }
    }
};
node *root;
void insert(char* str,int len){
    node *current_node = root;
    for(int i=0;i<len;i++){
        int id = str[i]-'a';
        if(current_node->next[id]==NULL){
            current_node->next[id]=new node();
        }
        current_node = current_node->next[id];
    }
    current_node->endmark = true;
}
bool search(char* str,int len){
    node *current_node = root;
    for(int i=0;i<len;i++){
        int id = str[i]-'a';
        if(current_node->next[id]==NULL){
            return false;
        }
        current_node=current_node->next[id];
    }
    return current_node->endmark;
}
void del(node *current_node){
    for(int i=0;i<26;i++){
        if(current_node->next[i]){
            del(current_node->next[i]);
        }
    }
    delete(current_node);
}
int main(){
    cout<<"Enter Number of Words:"<<endl;
    root = new node();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char str[50];
        scanf("%s",str);
        insert(str,strlen(str));
    }
    cout<<"Number of Query:"<<endl;
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        char str[50];
        scanf("%s",str);
        if(search(str,strlen(str))){
            cout<<"found"<<endl;
        }
        else{
            cout<<"Not Found"<<endl;
        }
    }
    del(root);
    return 0;
}
