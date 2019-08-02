#include<bits/stdc++.h>
using namespace std;
int main(){
    char ss[100001];
    while(scanf("%s",ss)!=EOF){
        list<char>v;
        list<char>::iterator it;
        it = v.begin();
        for(int i=0;i<strlen(ss);i++){
            if(ss[i]=='['){
                it = v.begin();
            }
            else if(ss[i]==']'){
                it = v.end();
            }
            else{
                v.insert(it,ss[i]);
            }
        }
        for(it=v.begin();it!=v.end();it++){
            cout<<*it;
        }
        cout<<endl;
    }
    return 0;
}
