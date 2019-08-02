#include<bits/stdc++.h>
using namespace std;
class node{
public:
    bool endmark;
    node *next[3];
    node(){
        endmark = false;
        for(int i=0;i<2;i++){
            next[i]=NULL;
        }
    }
};
node *root;
bool insert(string s){
    node *current_node=root;
    for(int i=0;i<s.length();i++){
        if(current_node->endmark==true){
            return true;
        }
        int id = s[i]-'0';
        if(current_node->next[id]==NULL){
            current_node->next[id]=new node();
        }
        current_node=current_node->next[id];
    }
    current_node->endmark=true;
    for(int i=0;i<2;i++){
        if(current_node->next[i]!=NULL){
            return true;
        }
    }
    return false;
}

int main(){
    int k=0;
    while(1){
        string s;
        bool flag=false;
        root = new node();
        while(1){
            getline(cin,s);
            if(s.empty()) return 0;
            if(s=="9") break;
            if(flag==false){
                flag=insert(s);
            }
        }
        flag==false?cout<<"Set "<<++k<<" is immediately decodable"<<endl:cout<<"Set "<<++k<<" is not immediately decodable"<<endl;
    }
    return 0;
}

