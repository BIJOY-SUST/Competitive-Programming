#include<bits/stdc++.h>
using namespace std;
map<string,int>representative;
/**map<int,int>max_cre;
map<string,int>creatures;
int find_parent(int x){
    if(representative[x]!=x) representative[x]=find_parent(representative[x]);
    return representative[x];
}**/
int main(){
    int t,n;
    string ss1,ss2;
    cin>>t;
    while(t--){
        cin>>n;
        int h=0;
        for(int i=1;i<=n;i++){
            cin>>ss1>>ss2;
            if(representative[ss1]==0){
                representative[ss1]++;
                h=representative[ss1]+h;
            }
            if(representative[ss2]==0){
                representative[ss2]++;
                h=representative[ss2]+h;
            }
            cout<<h<<endl;
        }
    }
    return 0;
}

