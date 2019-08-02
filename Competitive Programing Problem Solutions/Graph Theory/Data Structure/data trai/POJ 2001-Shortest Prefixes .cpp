#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string>vt;
vector<string>::iterator it;

long long i, k, sz, cur, last, x;
string s;

struct node{
    int next[26+1];
    int cnt;
}ar[20109];

void new_trie(int cur){
    for(int j=0; j<26; j++)ar[cur].next[j]=-1;
    ar[cur].cnt=1;
}

void insrt(){
        cur=0, sz=s.size();
        for(i=0; i<sz; i++){
            x=s[i]-'a';
            if(ar[cur].next[x]==-1){
                ar[cur].next[x]=last;
                new_trie(last++);
                cur=ar[cur].next[x];
            }
            else{
                cur=ar[cur].next[x];
                ar[cur].cnt++;
            }
        }
}

void fnd(){
        sz=s.size(), cur=0;
        for(i=0; i<sz; i++){
            x=s[i]-'a';
            cout<<s[i];
            cur=ar[cur].next[x];
            if(ar[cur].cnt==1) i=sz;
        }
}

int main(){
        new_trie(0);
        last=1;
        while(getline(cin, s)){
            if(s.size()==0) break;
            vt.push_back(s);
            insrt();
        }
        for(it=vt.begin(); it<vt.end(); it++){
            s=*it;
            cout<<s<<" ";
            fnd();
            cout<<endl;


        }
        return 0;
}
