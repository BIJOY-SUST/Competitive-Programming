#include<bits/stdc++.h>
using namespace std;
vector<char>elements;
vector<vector<char> >adjcent;///map neya jabe na.........because.........for(int v;v<adjcent[elements[u]].size();v++)...size asbe na
map<char,bool>visited;

bool valid(int u){
    for(int v=0;v<adjcent[elements[u]].size();v++){
        //cout<<adjcent[elements[u]][v]<<endl;
        if(visited[adjcent[elements[u]][v]]){///a b f g
                                             ///a b b f..... if() er modhde (a<b) mane (a) er adjcent jodi visited na kora thake(ortath jodi na neya hoy) tahole a neya jabe...
//            cout<<adjcent[elements[u]][v]<<endl;
            return false;
        }
    }
    return true;
}

void Back_Tracking(string chart){
    if(chart.length()==elements.size()){
        cout<<chart<<endl;
        return;
    }
    for(int i=0;i<elements.size();i++){
        if(!visited[elements[i]]){
            visited[elements[i]]=true;
            if(valid(i)){
                Back_Tracking(chart+elements[i]);
            }
            visited[elements[i]]=false;
        }
    }
}

int main(){
    char x,y;
    string s;
    stringstream ss;
    bool n_line=false;
    while(getline(cin,s)){
        if(n_line){cout<<endl;}
        n_line=true;
        elements.clear();
        adjcent.clear();
        adjcent.resize(200);
        ss.clear();
        ss.str(s);
        while(ss>>x){
            elements.push_back(x);
            visited[x]=false;///visited[x]=false;........ata na dileo bool amni..default false dhore ney........
        }
        sort(elements.begin(),elements.end());
        getline(cin,s);
        ss.clear();
        ss.str(s);
        while(ss>>x>>y){
            adjcent[x].push_back(y);
        }
        Back_Tracking("");
    }
    return 0;
}

