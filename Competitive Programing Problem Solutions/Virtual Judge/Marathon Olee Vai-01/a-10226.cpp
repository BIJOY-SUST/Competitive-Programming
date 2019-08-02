#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d\n\n",&n);
    while(n--){
        int all=0;
        string name;
        map<string,int>tree;
        while(getline(cin,name)){
            if(name.length()==0) break;
            else if(tree[name]==0) tree[name]=1;
            else tree[name]++;
            all++;
        }
        //cout<<all<<endl;
        for(__typeof(tree.begin()) it=tree.begin();it!=tree.end();it++){
            printf("%s %.4f\n",(*it).first.data(),(double)(*it).second/(double)all*100.0);
        }
        if(n>0) cout<<"\n";
        tree.clear();
    }
    return 0;
}
