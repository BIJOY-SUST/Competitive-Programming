#include<bits/stdc++.h>
using namespace std;
//#define int long long int
#define debug(x) cout<< #x <<"= " << x << endl;
#define p pair<int,int>
#define mem(a,b) memset((a),(b),sizeof(a))

int dx[]={1,-1,0,0,1,1,-1,-1};
int dy[]={0,0,1,-1,1,-1,1,-1};

vector<pair<int,int> >v[5002];
priority_queue<p,vector<p>,greater<p> >q;
int ss[5002];
int dis[5002];
//int dir[5002][5002];
//int cost[5002][5002];
int n,m;
int dij(int start,int End){
    p u,vv;
    for(int i=1;i<=n;i++) dis[i]=100001;
    q.push(make_pair(0,start));
    dis[start]=0;
    while(!q.empty()){
        u=q.top();
        q.pop();
        if(u.first>dis[u.second]) continue;
        for(int i=0;i<v[u.second].size();i++){
            vv=v[u.second][i];
            if(dis[u.second]+vv.second<dis[vv.first]){
                dis[vv.first]=dis[u.second]+vv.second;
                q.push(make_pair(dis[vv.first],vv.first));
            }
        }
    }
    return dis[End];
}
int main(){
    int t;
    cin >> t;
    while(t--){
        vector<pair<int,int> > sr;
        cin >> n >> m;
        mem(ss,0);
        while(m--){
            int a,b;
            cin >> a >> b;
            ss[a]++;
            sr.push_back(make_pair(a,b));
        }
        for(int i=1;i<=n;i++){
//            if(ss[i]==0)
            for(int j=0;j<sr.size();j++)
            {
                int dd=abs(i-sr[j].first);
                v[i].push_back(make_pair(sr[j].second,dd));
//                dir[i][sr[i].second]=dd;
//                v[sr[j]].push_back(i);
            }
        }
        int ans=dij(1,n);
        cout<<ans<<endl;
        for(int i=1;i<=5000;i++) v[i].clear();
        sr.clear();

    }

return 0;
}
