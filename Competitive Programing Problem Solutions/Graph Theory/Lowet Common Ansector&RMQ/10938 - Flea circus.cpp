///পারি নাই , পরে আবার চেষ্টা করতে হবে...Mind it BIJOY
///পারছি YES...AC in 1 go....
#include<bits/stdc++.h>
#define mx             5010
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define pp             pair<int,int>
//#define ll             long long int
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
vector<int >edges[mx];
int level[mx];
int sparse[mx][20];
int parent[mx];
void DFS(int from,int u,int dep){
    parent[u]=from;
    level[u]=dep;
    for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(v!=from){
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
    for(c=1;(1<<c)<=level[p];c++);
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
    for(c=0;(1<<c)<=level[p];c++);
    c--;
    for(int i=c;i>=0;i--){
        if(level[p]-(1<<i)>=q) p=sparse[p][i];
    }
    return p;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,a,b;
    while(scanf("%d",&n)&&n){
        mem(parent,-1);
        mem(level,0);
        mem(sparse,-1);
        for(int i=0;i<mx;i++) edges[i].clear();
        for(int i=1;i<n;i++){
            scanf("%d%d",&a,&b);
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        DFS(-1,1,0);
        Sparse_Table(n);
        scanf("%d",&m);
        while(m--){
            scanf("%d%d",&a,&b);
//            if(level[a]<level[b]) swap(a,b);
            int lca=LCA_query(n,a,b);
            int dis=level[a]+level[b]-2*level[lca];
//            cout<<dis<<endl;
            if(dis%2==0){
                dis=dis>>1;
                if(level[a]-level[lca]>=dis){
//                    cout<<level[a]-k+1<<endl;
                    int ans=no_node(a,level[a]-dis);///Tricky part
                    printf("The fleas meet at %d.\n",ans);
                }
                else{
                    int dd=level[a]-level[lca];
                    dd=dis-dd;
                    dd=dd+level[lca];
//                    cout<<dd<<endl;
                    int ans=no_node(b,dd);///Tricky part
                    printf("The fleas meet at %d.\n",ans);
                }
            }
            else{
                dis=dis>>1;
                vector<int>point;
                if(level[a]-level[lca]>=dis){
//                    cout<<level[a]-k+1<<endl;
                    int ans=no_node(a,level[a]-dis);///Tricky part
                    point.push_back(ans);
                }
                else{
                    int dd=level[a]-level[lca];
                    dd=dis-dd;
                    dd=dd+level[lca];
//                    cout<<dd<<endl;
                    int ans=no_node(b,dd);///Tricky part
                    point.push_back(ans);
                }
                if(level[a]-level[lca]>=dis+1){
//                    cout<<level[a]-k+1<<endl;
                    int ans=no_node(a,level[a]-dis-1);///Tricky part
                    point.push_back(ans);
                }
                else{
                    int dd=level[a]-level[lca];
                    dd=dis+1-dd;
                    dd=dd+level[lca];
//                    cout<<dd<<endl;
                    int ans=no_node(b,dd);///Tricky part
                    point.push_back(ans);
                }
                sort(point.begin(),point.end());
                printf("The fleas jump forever between %d and %d.\n",point[0],point[1]);
                point.clear();
            }
        }
    }
    return 0;
}
/*
Sample Input
8
1 2
1 3
2 4
2 5
3 6
3 7
5 8
5
5 1
7 4
1 8
4 7
7 8
0
Sample Output
The fleas meet at 2.
The fleas meet at 1.
The fleas jump forever between 2 and 5.
The fleas meet at 1.
The fleas jump forever between 1 and 2.
*/
