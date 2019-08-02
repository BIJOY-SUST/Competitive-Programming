#include<bits/stdc++.h>
using namespace std;
int parent[26],Rank[26];
int Find(int x){
    if(x!=parent[x]) parent[x]=Find(parent[x]);
    return parent[x];
}
int Union(int &x, int &y){
    int PX=Find(x),PY=Find(y);
    if(Rank[PX]>Rank[PY]) parent[PY]=PX;
    else{
        parent[PX]=PY;
        if(Rank[PX]==Rank[PY])
            Rank[PY]++;
    }
}
int main(){
    int T,n,x,y,ans;
    string s;
    scanf("%d\n\n",&T);
    for(int tc=1;tc<=T;tc++){
        getline(cin,s);
        n=s[0]-'A'+1;
        ans=n;
        for(int i=0;i<n;i++){
            parent[i]=i;
            Rank[i]=0;
        }
        while(1){
            if(!getline(cin,s) || s.empty()) break;
            x=s[0]-'A'; y=s[1]-'A';
            if(Find(x)!=Find(y)){
                Union(x,y);
                ans--;
            }
        }
        if(tc!=1) printf("\n");
        printf("%d\n",ans);
    }
    return 0;
}

