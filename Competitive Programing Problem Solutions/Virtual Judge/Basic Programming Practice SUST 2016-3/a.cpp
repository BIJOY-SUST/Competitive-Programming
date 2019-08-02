#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
//#define pp             pair<int,int>
//#define bug(x)         printf("X: %d\n",x)
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
vector<int>v1,v2;
map<int,int>mapping1;
map<int,int>mapping2;
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int h;scanf("%d",&h);
        v1.push_back(h);
        v2.push_back(h);
        mapping1[h]++;
        //mapping2[i]=h;
    }
    sort(v1.rbegin(),v1.rend());
    v1.erase(unique(v1.begin(),v1.end()),v1.end());
    int k=1;
    for(int i=0;i<v1.size();i++){
        mapping2[v1[i]]=k;
        k+=mapping1[v1[i]];
    }
    for(int i=0;i<n;i++){
        printf("%d ",mapping2[v2[i]]);
    }
    return 0;
}
/*

*/
