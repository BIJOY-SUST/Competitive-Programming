#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string>st;
vector<string>::iterator it;
long long current_node,last_node;
class node{
public:
    int next[4];
    int Count;
}arr[2500001];
void new_trie(int c_node){
    for(int i=0;i<4;i++){
        arr[c_node].next[i]=-1;
    }
    arr[c_node].Count=1;
}
void insert(string ss){
    current_node=0;
    for(int i=0;i<ss.length();i++){
        int id=ss[i]-'a';
        if(arr[current_node].next[id]==-1){
            arr[current_node].next[id]=last_node;
            new_trie(last_node++);
            current_node=arr[current_node].next[id];
        }
        else{
            current_node=arr[current_node].next[id];
            arr[current_node].Count++;
        }
    }
}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        last_node=1;
        new_trie(0);
        while(n--){
            getline(cin,s);
            if(s.length()==0) break;
            st.push_back(s);
            insert(s);
        }
    }
    return 0;
}
