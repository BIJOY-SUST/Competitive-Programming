#include<bits/stdc++.h>
#define mx             1010
//#define mod            1000000007
//#define pi             2*acos(0.0)
#define pp             pair<int,int>
//#define ll             long long int
#define me             printf("BIJOY\n");
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//template< class T > inline T SQR(T a) {return ((a)*(a));}
//template< class T > inline T gcd(T a,T b) {a=abs(a);b=abs(b); if(!b) return a; return gcd(b,a%b);}
//template< class T > inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/_gcd(a,b))*b;}
//template<typename T> T POW(T b,T p) {T r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//template<typename T> T BigMod(T b,T p,T m) {T r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//template<typename T> T ModInverse(T n,T m) {return BigMod(n,m-2,m);}
using namespace std;
bool mark[mx];
bool vis[mx];
vector<int>prime;
//vector<int>factor;
int ans;
void sieve(){
    mem(mark,true);
    for(int i=4;i<=mx;i+=2) mark[i]=false;
    for(int i=3;i<=(int)sqrt(mx);i+=2){
        if(mark[i]) for(int j=i*i;j<=mx;j+=2*i){
            mark[j]=false;
        }
    }
    prime.push_back(2);
    for(int i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);
}
//void prime_factor(int n){
//    int sq=sqrt(n);
//    for(int i=0;i<prime.size()&&prime[i]<=sq;i++){
//        if(mark[n]) break;
//        if(n%prime[i]==0){
//            while(n%prime[i]==0){
//                n/=prime[i];
//                factor.push_back(prime[i]);
//            }
//            sq=sqrt(n);
//        }
//    }
//    if(n!=1) factor.push_back(n);
//}
bool bfs(int s,int t){
    queue<pp >q;
    q.push({s,0});
    vis[s]=true;
    while(!q.empty()){
        pp u=q.front();
        q.pop();
        if(u.first==t){
            ans=u.second;
            return true;
        }
        for(int i=0;prime[i]<u.first;i++){
            int d=prime[i];
            if(u.first+d<=t&&u.first%d==0&&!vis[u.first+d]){
                vis[u.first+d]=true;
                q.push({u.first+d,u.second+1});
            }
        }
    }
    return false;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    sieve();
    int t; scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int s,t; scanf("%d %d",&s,&t);
        mem(vis,false);
//        if(!mark[s]) prime_factor(s);
        ans=0;
//        for(int i=0;i<prime.size();i++)
//            cout<<prime[i]<<endl;
//        factor.erase(unique(factor.begin(),factor.end()),factor.end());
        bool flag=bfs(s,t);
        if(flag) printf("Case %d: %d\n",cs,ans);
        else printf("Case %d: -1\n",cs);
//        for(int i=0;i<factor.size();i++){
//            printf("%d\n",factor[i]);
//        }
//        factor.clear();
    }
    return 0;
}
/*
Sample Input
2
6 12
6 13
Output for Sample Input
Case 1: 2
Case 2: -1
*/
