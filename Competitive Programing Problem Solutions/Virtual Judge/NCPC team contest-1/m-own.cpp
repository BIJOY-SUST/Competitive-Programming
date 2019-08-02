
#include<bits/stdc++.h>

using namespace std;

#define F               first
#define S               second
#define pb              push_back

#define ll              long long int

#define nl              '\n'
#define pf              printf
#define sf              scanf
#define mem(arr,val)    memset(arr,val,sizeof(arr))

const ll  mx        = 1e5+10;

struct data{
    ll no,w1,w2;
};
vector<data>edge[mx];
ll lavel[mx],ff[mx],fff[mx][25];
ll bb[mx],bbb[mx][25],spars[mx][25],par[mx];
bool vis[mx];

void dfs(ll u,ll l){
    vis[u]=1;
    for(ll i=0;i<edge[u].size();i++){
        data v = edge[u][i];
        if(vis[v.no]==0){
            ff[v.no]=v.w2;
            bb[v.no]=v.w1;
            par[v.no]=u;
            lavel[v.no]=l+1;
            dfs(v.no,l+1);
        }
    }
//    return;
}
void table(ll n){
    mem(spars,-1);mem(bbb,0);mem(fff,0);

    for(ll i=0;i<=n;i++){
        spars[i][0]=par[i],fff[i][0]=ff[i],bbb[i][0]=bb[i];
    }

    for(ll j=1;(1<<j)<=n;j++){
        for(ll i=1;i<=n;i++){
            if(spars[i][j-1]!=-1){
    spars[i][j]=spars[spars[i][j-1]][j-1];
    fff[i][j]=fff[spars[i][j-1]][j-1]+fff[i][j-1];
    bbb[i][j]=bbb[spars[i][j-1]][j-1]+bbb[i][j-1];
            }
        }
    }
}
ll query(ll p,ll q){
//    if(lavel[p]<lavel[q]) swap(p,q);
    ll c,ans=0;
    c =1;
    while(1)
    {
        ll next = c+1;
        if((1<<next)>lavel[p] && (1<<next)>lavel[q])break;
        c++;
    }
//    for(c=1;(1<<c)<=lavel[p] && (1<<c)<=lavel[q];c++);
//    c--;
//    debug(c);
    if(lavel[p]>lavel[q]){
        for(ll i=c;i>=0;i--){
            if(lavel[p]-(1<<i)>=lavel[q]){
                ans+=bbb[p][i];
                p=spars[p][i];
            }
        }
        if(p==q) return ans;
    }
    else{
        for(ll i=c;i>=0;i--){
            if(lavel[q]-(1<<i)>=lavel[p]){
                ans+=fff[q][i];
                q=spars[q][i];
//                debug(fff[q][i]);
            }
        }
//        debug(p,q,ans);
        if(p==q) return ans;
    }
    for(ll i=c;i>=0;i--){
        if(spars[p][i]!=-1&&spars[p][i]!=spars[q][i]){
            ans+=(bbb[p][i]+fff[q][i]);
            p=spars[p][i]; q=spars[q][i];
        }
    }
    ans+=(bb[p]+ff[q]);
    return ans;
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    ll t,n,u,v,c1,c2;
    sf("%lld",&t);
    while(t--){
        mem(par,-1);
        mem(vis,0);
        for(int i=0;i<mx;i++) edge[i].clear();


        sf("%lld",&n);
        ll total=0;
        for(ll i=1;i<n;i++){
            sf("%lld%lld%lld%lld",&u,&v,&c1,&c2);
            edge[u].pb({v,c1,c2});
            edge[v].pb({u,c2,c1});
            total+=(c1+c2);
        }
        lavel[1]=0;
        dfs(1,0);
        table(n);

        ll m,x,y;
        sf("%lld",&m);
        while(m--){
            sf("%lld%lld",&x,&y);
            ll d=query(x,y);
            ll ans=total-d;
            pf("%lld\n",ans);
//            debug(total,d,ans);
        }
    }
    return 0;
}
/*

*/
