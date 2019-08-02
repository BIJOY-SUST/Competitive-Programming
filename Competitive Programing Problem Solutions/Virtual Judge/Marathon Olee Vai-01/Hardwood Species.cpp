#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d\n\n",&n);
    while(n--){
        int ans=0;
        string name;
        map<string,int>tree;
        while(getline(cin,name)){
            if(name.length()==0){
                break;
            }
            if(tree[name]==0){
                tree[name]=1;
            }
            else{
                tree[name]+=1;
            }
            ans++;
        }
        for(__typeof(tree.begin()) it=tree.begin();it!=tree.end();it++){
            printf("%s %.4f\n",(*it).first.data(),(double)(*it).second/(double)ans*100.0);
        }
        if(n>0) cout<<endl;
        tree.clear();
    }
    return 0;
}

