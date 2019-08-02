#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    map<string,int>tree;
    string name;
    scanf("%d\n\n",&n);
    while(n--){
        //tree.clear();
        int ans=0;
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
        //map<string,int>::iterator it;
        for(__typeof(tree.begin()) it=tree.begin();it!=tree.end();it++){
            printf("%s %.4f\n",(*it).first.data(),(double)(*it).second/(double)ans*100.0);
        }
        if(n>0) cout<<endl;
        tree.clear();
    }
    return 0;
}
