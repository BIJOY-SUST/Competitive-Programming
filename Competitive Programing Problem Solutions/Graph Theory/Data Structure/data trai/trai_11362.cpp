#include<bits/stdc++.h>
using namespace std;
class node{
public:
    bool endmark;
    node *next[11];
    node(){
        endmark = false;
        for(int i=0;i<10;i++){
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
    for(int i=0;i<10;i++){
        if(current_node->next[i]!=NULL){
            return true;
        }
    }
    return false;
}

int main(){
    int T,N;
    cin>>T;
    while(T--){
        string s;
        bool flag=false;
        root = new node();
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>s;
            if(flag==false){
                flag=insert(s);
            }
        }
        flag==false?cout<<"YES"<<endl:cout<<"NO"<<endl;
    }
    return 0;
}
