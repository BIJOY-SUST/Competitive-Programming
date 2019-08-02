#include<bits/stdc++.h>
using namespace std;
map<string,int>visited;
map<string,vector<string> >edges;

int BFS(string s5,string s6){
    queue<string>q;
    q.push(s5);
    visited[s5]=0;
    while(!q.empty()){
        string u=q.front();
        q.pop();
        //if(u==s6) return visited[u];
        for(int i=0;i<edges[u].size();i++){
            string v=edges[u][i];
            if(!visited[v]){
                visited[v]=visited[u]+1;
                q.push(v);
            }
        }
    }
    return visited[s6];
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    freopen("j1.txt","r",stdin);
//    freopen("j2.txt","w",stdout);
    int n;
    cin>>n;
    while(n--){
        string ss1,ss2;
        while(cin>>ss1){
            if(ss1=="*") break;
            edges[ss1];
            for(__typeof(edges.begin()) it=edges.begin();it!=edges.end();it++){
                ss2=it->first;
                int differ=0;
                if(ss2.length()==ss1.length()){
                    for(int i=0;i<ss2.length()&&differ<=1;i++){
                        if(ss2[i]!=ss1[i]) differ++;
                    }
                    if(differ==1){
                        edges[ss2].push_back(ss1);
                        edges[ss1].push_back(ss2);
                    }
                }
            }
        }
        string ss;
        getchar();
        while(getline(cin,ss)){
            if(ss.length()==0) break;
            int position=ss.find(" ");
            string s3,s4;
            s3=ss.substr(0,position);
            s4=ss.substr(position+1,ss.length());
            visited.clear();
            int ans=BFS(s3,s4);
            cout<<s3<<" "<<s4<<" "<<ans<<'\n';
        }
        if(n>0) cout<<'\n';
    }
    return 0;
}
