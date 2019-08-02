#include<bits/stdc++.h>
#define mx             510
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
//#define pp             pair<int,int>
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//int biton(int p,int pos){return p=p|(1<<pos);}
//int bitoff(int p,int pos){return p=p&~(1<<pos);}
//bool bitcheck(int p,int pos){return (bool)(p&(1<<pos));}
//ll POW(ll b,ll p) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
//ll BigMod(ll b,ll p,ll Mod) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
//ll ModInverse(ll p,ll Mod) {return BigMod(p,Mod-2,Mod);}
using namespace std;
int boys[mx][mx],girls[mx][mx];
int cur_boy[mx],boy_to_girl[mx],girl_to_boy[mx];
bool i_love_you[mx];
int find_rank(int n,int v,int u){
    for(int i=1;i<=n;i++){
        if(girls[v][i]==u) return i;
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d",&t);
    while(t--){
        mem(boys,0);
        mem(girls,0);
        mem(boy_to_girl,0);
        mem(girl_to_boy,0);
        int n; scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int x; scanf("%d",&x);
            for(int j=1;j<=n;j++){
                scanf("%d",&girls[x][j]);
            }
        }
        for(int i=1;i<=n;i++){
            int x; scanf("%d",&x);
            for(int j=1;j<=n;j++){
                scanf("%d",&boys[x][j]);
            }
        }
        queue<int>q;
        for(int i=1;i<=n;i++) q.push(i);
        fill(cur_boy,cur_boy+n+1,1);
        mem(i_love_you,true);
        while(!q.empty()){
            int i,u=q.front();
            q.pop();
//            cout<<cur_boy[u]<<endl;
            for(i=cur_boy[u];i<=n;i++){
                int v=boys[u][i];
                if(i_love_you[v]){
                    boy_to_girl[u]=v;
                    girl_to_boy[v]=u;
                    i_love_you[v]=false;
//                    cout<<v<<endl;
                    break;
                }
                else{
                    int rank_cur=find_rank(n,v,u);
                    int rank_prev=find_rank(n,v,girl_to_boy[v]);
                    if(rank_cur<rank_prev){
                        q.push(girl_to_boy[v]);
                        boy_to_girl[u]=v;
                        girl_to_boy[v]=u;
                        break;
                    }
                }
            }
            cur_boy[u]=i+1;
        }
        for(int i=1;i<=n;i++){
            printf("%d %d\n",i,boy_to_girl[i]);
        }
    }
    return 0;
}
/**
Input:
2
7
1 3 4 2 1 6 7 5
2 6 4 2 3 5 1 7
3 6 3 5 7 2 4 1
4 1 6 3 2 4 7 5
5 1 6 5 3 4 7 2
6 1 7 3 4 5 6 2
7 5 6 2 4 3 7 1
1 4 5 3 7 2 6 1
2 5 6 4 7 3 2 1
3 1 6 5 4 3 7 2
4 3 5 6 7 2 4 1
5 1 7 6 4 3 5 2
6 6 3 7 5 2 4 1
7 1 7 4 2 6 5 3
Output:
1 4
2 5
3 1
4 3
5 7
6 6
7 2
**/
