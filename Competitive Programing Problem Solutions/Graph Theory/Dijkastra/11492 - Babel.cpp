#include<bits/stdc++.h>
#define mx             2010
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
#define pp             pair<int,string>
//#define bug(x)         printf("X: %d\n",x)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//ll POW(ll b,ll p) {ll r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//ll BigMod(ll b,ll p,ll m) {ll r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//ll ModInverse(ll n,ll m) {return BigMod(n,m-2,m);}
using namespace std;
vector<pp >edges[2*mx];
//int cost[20001][20001];
map<string,int>mapping;
map<int,string>no;
class data{
public:
    int node;
    string w;
//    int d=w.length();
    bool operator<(const data &p)const{
        return w.length()>p.w.length();
    }
};

int Dijkstra(int start,int End){
    int dis[mx];
    for(int i=0;i<mx;i++) dis[i]=1e9;
    priority_queue<data>q;///priority_queue<int,vector<int>,greater<int> >q;
    data u,v;
    u.node=start,u.w="";
    q.push(u);
    dis[start]=0;
    no[start]=u.w;
    while(!q.empty()){
        u=q.top();
        q.pop();
        int uw = dis[u.node];
        for(int i=0;i<edges[u.node].size();i++){
            //cout<<i<<endl;
            v.node = edges[u.node][i].first;
            v.w = u.w+edges[u.node][i].second;
//            string a=no[u.node];
//            string b=no[v.node];
            string a=no[u.node],b=edges[u.node][i].second;
//            cout<<a<<" "<<b<<endl;
            if(dis[v.node]>v.w.length()&&a[0]!=b[0]){
//                cout<<v.node<<" "<<v.w<<endl;
                no[v.node]=b;
                dis[v.node] = v.w.length();
                q.push(v);
            }
            else if(dis[v.node]>v.w.length()&&a[0]==b[0]){
//                cout<<u.node<<" "<<v.node<<" "<<v.w<<endl;
                dis[v.node]=1e9;
                dis[u.node]=1e9;
                no[v.node]="";
            }
        }
    }
    return dis[End];
}

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(scanf("%d",&n)==1){
        if(n==0) break;
        for(int i=0;i<mx;i++) edges[i].clear();
        mapping.clear();
        no.clear();
        int Assign=1;
        string start,End;
        cin>>start>>End;
        string s1,s2,w;
        for(int i=1;i<=n;i++){
            cin>>s1>>s2>>w;
            if(mapping.find(s1)==mapping.end()){
                mapping[s1]=Assign++;
                //cout<<mapping[s1]<<endl;
            }
            if(mapping.find(s2)==mapping.end()){
                mapping[s2]=Assign++;
                //cout<<mapping[s2]<<endl;
            }
            edges[mapping[s1]].push_back({mapping[s2],w});
            edges[mapping[s2]].push_back({mapping[s1],w});
//            no[mapping[s1]]=s1;
//            no[mapping[s2]]=s2;
//            cout<<mapping[s1]<<" "<<mapping[s2]<<" "<<w<<endl;
//            cost[mapping[s1]][mapping[s2]]=w.length();
//            cost[mapping[s2]][mapping[s1]]=w.length();
        }
        if(mapping.find(start)==mapping.end()){
            mapping[start]=Assign++;
            //cout<<mapping[s1]<<endl;
        }
        if(mapping.find(End)==mapping.end()){
            mapping[End]=Assign++;
            //cout<<mapping[s2]<<endl;
        }
//        cout<<mapping[start]<<" "<<mapping[End]<<endl;
        int d = Dijkstra(mapping[start],mapping[End]);
        if(d!=1e9){
            cout<<d<<"\n";
        }
        else{
            cout<<"impossivel\n";
        }
    }
    return 0;
}
/*
5
english arabic
english french ahmad
french arabic amer
english spanish wahed
spanish german esmo
german french tweel
*/
