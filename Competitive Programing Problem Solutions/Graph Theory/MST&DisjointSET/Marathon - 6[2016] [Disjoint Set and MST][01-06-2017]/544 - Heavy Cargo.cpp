#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define pp             pair<int,int>
//#define ll             long long int
//#define bug(x)         printf("X: %d\n",x)
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
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
class node{
public:
    string u,v;
    int w;
    bool operator<(const node &p)const{
        return w>p.w;
    }
};
vector<node>edges;
set<string>s;
map<string,string>repres;
string find_par(string s3){
    if(repres[s3]!=s3) repres[s3]=find_par(repres[s3]);
    return repres[s3];
}
int MST(int n,string s1,string s2){
    sort(edges.begin(),edges.end());
    for(__typeof(s.begin())it=s.begin();it!=s.end();it++){
        repres[*it]=*it;
    }
    int c=0,ans=100000;
    for(int i=0;i<edges.size();i++){
        string pu=find_par(edges[i].u);
        string pv=find_par(edges[i].v);
        if(pu!=pv){
            repres[pu]=pv;
            c++;
            if(ans>edges[i].w) ans=edges[i].w;
            if(c==n-1) break;
        }
        if(find_par(s1)==find_par(s2)) break;
    }
    return ans;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,e,cs=0;
    while(scanf("%d%d",&n,&e)==2&&n!=0&&e!=0){
        edges.clear();
        repres.clear();
        string s1,s2;
        int d;
        for(int i=1;i<=e;i++){
            cin>>s1>>s2>>d;
            node ob;
            ob.u=s1;
            ob.v=s2;
            ob.w=d;
            edges.push_back(ob);
            s.insert(s1);
            s.insert(s2);
        }
        cin>>s1>>s2;
        int ans=MST(n,s1,s2);
        printf("Scenario #%d\n",++cs);
        printf("%d tons\n\n",ans);
    }
    return 0;
}
/*
Sample Input
4 3
Karlsruhe Stuttgart 100
Stuttgart Ulm 80
Ulm Muenchen 120
Karlsruhe Muenchen
5 5
Karlsruhe Stuttgart 100
Stuttgart Ulm 80
Ulm Muenchen 120
Karlsruhe Hamburg 220
Hamburg Muenchen 170
Muenchen Karlsruhe
0 0

Sample Output
Scenario #1
80 tons
Scenario #2
170 tons
*/
///Hints: I am doing a maximum spanning tree and then finding the min weight between the source and destination...
