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
vector<int>v,vv;
map<int,vector<int> >mapping;
map<int,bool>mm;
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        int h;scanf("%d",&h);
        v.push_back(h);
        mapping[h].push_back(i);
    }
    sort(v.begin(),v.end());
    int ans=0,c=0;
    for(int i=0;i<n;i++){
        if(ans+v[i]<=k){
            ++c;
            ans+=v[i];
            vv.push_back(v[i]);
        }
        else break;
    }
    printf("%d\n",c);
    int kk=0;
    vv.erase(unique(vv.begin(),vv.end()),vv.end());
    for(int i=0;i<vv.size()&&kk<c;i++){
        for(int j=0;j<mapping[vv[i]].size()&&kk<c;j++){
            printf("%d ",mapping[vv[i]][j]);
            kk++;
        }
    }
    printf("\n");
    vv.clear();
    v.clear();
    return 0;
}
/*

*/
