#include<bits/stdc++.h>
using namespace std;
vector<char>elements;
vector<pair<int,int> >edges;
map<char,bool>visited;

//bool valid(int u){
//    for(int v=0;v<adjcent[elements[u]].size();v++){
//        //cout<<adjcent[elements[u]][v]<<endl;
//        if(visited[adjcent[elements[u]][v]]){
//
////            cout<<adjcent[elements[u]][v]<<endl;
//            return false;
//        }
//    }
//    return true;
//}

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
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n,p;
        scanf("%d %d",&n,&p);
        for(int j=1;j<=p;j++){
            int index,value;
            scanf("%d %d",&index,&value);
            edges.push_back(make_pair(index,value));
        }
        for(int h=1;h<=n;h++){

        }
    }
    return 0;
}

