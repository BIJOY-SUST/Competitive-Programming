#include<bits/stdc++.h>
#define mx             10010
//#define mod            1000000007
//#define pi             2*acos(0.0)
#define pp             pair<int,int>
#define ll             long long int
//#define bug(x)         printf("X: %d\n",x)
//#define one(n)         __builtin_popcount(n)
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
vector<pp >edges[mx];
int level[mx];
int sparse[mx][20];
int parent[mx];
int dis[mx];
void DFS(int from,int u,int dep){
    parent[u]=from;
    level[u]=dep;
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i].first;
        int w=edges[u][i].second;
        if(v!=from){
            dis[v]=dis[u]+w;
            DFS(u,v,dep+1);
        }

    }
}
void Sparse_Table(int n){
    for(int i=1;i<=n;i++){
        sparse[i][0]=parent[i];
    }
    sparse[1][0]=-1;
    for(int j=1;(1<<j)<n;j++){
        for(int i=1;i<=n;i++){
            if(sparse[i][j-1]!=-1){
                sparse[i][j]=sparse[sparse[i][j-1]][j-1];
            }
        }
    }
}
int LCA_query(int n,int p,int q){
    if(level[p]<level[q]) swap(p,q);
    int c;
    for(c=0;(1<<c)<=level[p];c++);///c is equal to zero or one doesn't matter...
    c--;
    for(int i=c;i>=0;i--){
        if(level[p]-(1<<i)>=level[q]){
            p=sparse[p][i];
        }
    }
    if(p==q) return p;
    for(int i=c;i>=0;i--){
        if(sparse[p][i]!=-1&&sparse[p][i]!=sparse[q][i]){
            p=sparse[p][i],q=sparse[q][i];
        }
    }
    return parent[p];
}
int no_node(int p,int q){
    int c;
    for(c=0;(1<<c)<=level[p];c++);///c is equal to zero or one doesn't matter...
    c--;
    for(int i=c;i>=0;i--){
        if(level[p]-(1<<i)>=q){
            p=sparse[p][i];
        }
    }
    return p;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t,n,m,a,b,w;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        mem(parent,-1);
        mem(level,0);
        mem(sparse,-1);
        mem(dis,0);
        for(int i=0;i<mx;i++) edges[i].clear();
        for(int i=1;i<n;i++){
            scanf("%d%d%d",&a,&b,&w);
            edges[a].push_back({b,w});
            edges[b].push_back({a,w});
        }
        DFS(-1,1,0);
        Sparse_Table(n);
        while(1){
            char ch[10];
            scanf("%s",ch);
            if(ch[1]=='I'){
                scanf("%d%d",&a,&b);
                int d=LCA_query(n,a,b);
                int ans=dis[a]+dis[b]-2*dis[d];
                printf("%d\n",ans);
            }
            else if(ch[1]=='T'){
                scanf("%d%d",&a,&b);
                int k; scanf("%d",&k);
                int d=LCA_query(n,a,b);
                if(level[a]-level[d]+1>=k){
//                    cout<<level[a]-k+1<<endl;
                    int ans=no_node(a,level[a]-k+1);///Tricky part
                    printf("%d\n",ans);
                }
                else{
                    int dd=level[a]-level[d];
                    dd=k-dd;
                    dd=dd+level[d]-1;
//                    cout<<dd<<endl;
                    int ans=no_node(b,dd);///Tricky part
                    printf("%d\n",ans);
                }
            }
            else break;
        }
        printf("\n");
    }
    return 0;
}
/*
Input:
1

6
1 2 1
2 4 1
2 5 2
1 3 1
3 6 2
DIST 4 6
KTH 4 6 4
DONE

Output:
5
3
*/
