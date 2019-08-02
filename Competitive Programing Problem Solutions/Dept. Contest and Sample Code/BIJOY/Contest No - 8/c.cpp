#include<bits/stdc++.h>
#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
//#define pp             pair<int,int>
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
vector<int>edges[mx];
set<int>s;
int dd=0;
bool vis[mx];
int mark[mx];
void dfs(int u){
    vis[u]=true;
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(mark[v]==-1&&mark[u]==1){
            mark[v]=2;
            dfs(v);
        }
        else if(mark[v]==-1){
            mark[v]=1;
            dfs(v);
        }
        else if(mark[u]==mark[v]){
            dd=1;
            return;
        }

    }
    return;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,e;
    scanf("%d%d",&n,&e);
    for(int i=1;i<=e;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        edges[u].push_back(v);
        edges[v].push_back(u);
        s.insert(u);
        s.insert(v);
    }
    mem(vis,false);
    mem(mark,-1);
    for(__typeof(s.begin())it=s.begin();it!=s.end();it++){
        if(!vis[*it]){
            mark[*it]=1;
            dfs(*it);
            if(dd){
                printf("-1\n");
                return 0;
            }
        }
    }
    vector<int>one,two;
    for(int i=1;i<=n;i++){
        if(mark[i]==1) one.push_back(i);
        else if(mark[i]==2) two.push_back(i);
    }
    printf("%d\n",one.size());
    for(int i=0;i<one.size();i++){
        printf("%d ",one[i]);
    }
    printf("\n");
    printf("%d\n",two.size());
    for(int i=0;i<two.size();i++){
        printf("%d ",two[i]);
    }
    printf("\n");
    return 0;
}
/*

*/


