#include<bits/stdc++.h>
using namespace std;
map<string,int> visited;
map<string, vector<string> >edges;
int BFS(string s5,string s6){
    queue<string>q;
    q.push(s5);
    visited[s5]=0;
    while(!q.empty()){
        string u=q.front();
        q.pop();
        if(u==s6) return visited[u];
        for(int i=0;i<edges[u].size();i++){
            string v=edges[u][i];
            if(!visited[v]){
                visited[v]=visited[u]+1;
                q.push(v);
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    while(n--){
        string word,tmp;
        while(cin>>word){
            if(word=="*") break;
            edges[word];
            map<string, vector<string> >::const_iterator it;
            for (it = edges.begin(); it != edges.end(); ++it){
                tmp=(*it).first;
                int tamTmp = tmp.size(),dif=0;
                if(tamTmp == word.size()){
                    for (int i = 0; i < tamTmp && dif<2; ++i)
                    {
                        if(tmp[i]!=word[i])
                            dif++;
                    }
                    if(dif==1){
                        edges[tmp].push_back(word);
                        edges[word].push_back(tmp);
                    }
                }
            }
      //cin>>word;
        }
    string ss;
    getchar();
    while(getline(cin,ss)){
        if(ss.length()==0) break;
        int position=ss.find(" ");
        string s3,s4;
        s3=ss.substr(0,position);
        s4=ss.substr(position+1,ss.length());
        int ans=BFS(s3,s4);
        visited.clear();
        cout<<s3<<" "<<s4<<" "<<ans<<'\n';
    }
    if(n>0) cout<<'\n';
  }
  return 0;
}
