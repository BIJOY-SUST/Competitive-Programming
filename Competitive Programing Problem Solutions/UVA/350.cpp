#include<bits/stdc++.h>
using namespace std;
map<int,bool>visited;
int main(){
    int z,i,m,l,ans,c;
    int h=1;
    while(cin>>z>>i>>m>>l){
        if(z==0&&i==0&&m==0&&l==0) break;
        c=0;
        ans=l;
        visited.clear();
        //visited[ans]=true;;
        //int k=ans;
        while(1){
            ans=(z*ans+i)%m;
            //k=ans;

            if(visited[ans]==true) break;
            //cout<<ans<<endl;
            c++;

            visited[ans]=true;
        }
        cout<<"Case "<<h++<<": "<<c<<'\n';
    }
    return 0;
}
