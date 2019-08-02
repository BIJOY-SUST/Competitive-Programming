#include<bits/stdc++.h>
using namespace std;
vector<char>elements;
vector<vector<char> >adjacent;
bool visited[1001];
bool flag=true;
bool check(char u){
    for(int v=0;v<adjacent[u].size();v++){
        if(visited[adjacent[u][v]]) return false;
    }
    return true;
}
void Back_Tracking(string ch){
    if(ch.length()==elements.size()){
        cout<<ch[0];
        for(int i=1;i<ch.length();i++){
            cout<<" "<<ch[i];
        }
        cout<<'\n';
        flag=false;
        return;
    }
    for(int i=0;i<elements.size();i++){
        char c=elements[i];
        if(!visited[c]){
            if(check(c)){
                visited[c]=true;
                Back_Tracking(ch+c);
                visited[c]=false;
            }
        }
    }
}
int main(){
//    freopen("01.txt","r",stdin);
//    freopen("02.txt","w",stdout);
    int t;
//    cin.ignore();
    scanf("%d",&t);
//    printf("\n");
    getchar();
    while(t--){
        char x,y,z;
        memset(visited,false,sizeof(visited));
        string s;
        stringstream ss;
        getchar();
        getline(cin,s);
        ss.clear();
        ss.str(s);
        while(ss>>x){
            elements.push_back(x);
//            cout<<x;
        }
        sort(elements.begin(),elements.end());
        s.clear();
        adjacent.resize(200);
        getline(cin,s);
        ss.clear();
        ss.str(s);
        while(ss>>x>>y>>z){
            adjacent[x].push_back(z);
//            printf("%c %c %c\n",x,y,z);
        }
        Back_Tracking("");
        if(flag) printf("NO\n");
        flag=true;
        s.clear();
        elements.clear();
        for(int i=0;i<adjacent.size();i++){
            adjacent[i].clear();
        }
        adjacent.clear();
        if(t>0) printf("\n");
    }
    return 0;
}
