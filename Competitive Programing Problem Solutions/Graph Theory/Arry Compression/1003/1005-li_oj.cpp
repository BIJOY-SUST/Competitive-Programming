#include<bits/stdc++.h>
using namespace std;
map<string,vector<string> >edges;
vector<string>element;
map<string,bool>visited;
map<string,bool>Stack;
bool DFS(string us){
    if(!visited[us]){
        visited[us]=true;
        Stack[us]=true;
        for(int i=0;i<edges[us].size();i++){
            string vs = edges[us][i];
            if(!visited[vs]&&DFS(vs)){
                return true;
            }
            else if(Stack[vs]){
                return true;
            }
        }
    }
    Stack[us]=false;
    return false;
}
bool IsCyclic(){
    sort(element.begin(),element.end());
    element.erase(unique(element.begin(),element.end()),element.end());
    vector<string>::iterator it;
    for(it=element.begin();it!=element.end();it++){
        if(DFS(*it)){
            return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    string s1,s2;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>s1>>s2;
            element.push_back(s1);
            element.push_back(s2);
            visited[s1]=false;
            Stack[s2]=false;
            edges[s1].push_back(s2);
        }
        IsCyclic()?cout<<"Case "<<i<<": No"<<"\n":cout<<"Case "<<i<<": Yes"<<"\n";
        element.clear();
        visited.clear();
        edges.clear();
        Stack.clear();
    }
    return 0;
}
