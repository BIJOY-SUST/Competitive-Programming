#include<bits/stdc++.h>
#define mx 2005
using namespace std;
vector<pair<int,int> >Pair;
int Distance[mx],cost[mx][mx];
int n,m;
bool B_F(){
    for(int i=0;i<n;i++) Distance[i]=10000001;
    Distance[0]=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            int u=Pair[j].first,v=Pair[j].second;
            if(Distance[u]+cost[u][v]<Distance[v]){
                Distance[v]=Distance[u]+cost[u][v];
            }
        }
    }
    for(int i=0;i<m;i++){
        int u=Pair[i].first,v=Pair[i].second;
        if(Distance[u]+cost[u][v]<Distance[v]){
            return true;
        }
    }
    return false;
}
int main(){
//    freopen("001.txt","r",stdin);
//    freopen("002.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int s1,s2,w;
        memset(cost,0,sizeof(cost));
        scanf("%d %d",&n,&m);
//        cin>>s1>>s2;
        for(int j=0;j<m;j++){
//            cin>>s1>>s2>>w;
            scanf("%d %d %d",&s1,&s2,&w);
            Pair.push_back(make_pair(s1,s2));
            cost[s1][s2]=w;
        }
//        for(int j=0;j<m;j++){
//            int u=Pair[j].first,v=Pair[j].second;
//            cout<<u<<" "<<v<<" "<<cost[u][v]<<endl;
//        }
        bool flag=B_F();
        if(flag) cout<<"possible\n";
        else cout<<"not possible\n";
        Pair.clear();
    }
    return 0;
}
/*
Input:
2
5 6
1 2 1 2 3 1 3 4 1 4 5 1 5 4 -1  1 5 64
Output:
not possible
*/
