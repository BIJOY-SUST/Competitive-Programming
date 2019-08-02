#include<bits/stdc++.h>
using namespace std;
char c, d;
string line;
stringstream ss;
vector<char> elements;
vector<vector<char> > adj;
map<char, bool> vis;
bool valid(int e) {
   // cout<<"check"<<endl;
    for(int i = 0; i < adj[elements[e]].size(); i++)
        if(vis[adj[elements[e]][i]])
            return false;
    return true;
}
void Back_Tracking(string comb) {
    if(comb.length() == elements.size()){
        cout << comb << endl;
        return;
    }
    //cout<<"ghura"<<endl;
    for(int i = 0; i < elements.size(); i++) {
        if(!vis[elements[i]]) {
            //cout<<"which true "<<i<<endl;
            vis[elements[i]] = true;
            if(valid(i)){
               // cout<<comb<<endl;
                //cout<<elements[i]<<endl;
                Back_Tracking(comb + elements[i]);
               // cout<<elements[i]<<"==yes"<<endl;
            }
            vis[elements[i]] = false;
            //cout<<comb<<" "<<elements[i]<<"==no"<<endl;
        }
    }
}
int main(){
    bool n_line = false;
    while(getline(cin,line)){
        if(n_line) cout<<endl;
        n_line = true;
        elements.clear();
        adj.clear();
        adj.resize(256);
        ss.clear();
        ss.str(line);
        while(ss >> c){
            elements.push_back(c);
            ///vis[c]=false;........ata na dileo bool bydefault false dhore ney........
        }
        sort(elements.begin(), elements.end());
        getline(cin, line);
        ss.clear();
        ss.str(line);
        while(ss >> c >> d){
            adj[c].push_back(d);
        }
        Back_Tracking("");
    }
    return 0;
}

