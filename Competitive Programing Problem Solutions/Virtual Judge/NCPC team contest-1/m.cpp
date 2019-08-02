#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<< #x" " << x << endl;
#define ll long long

struct str
{
    ll d,w1,w2;
};

vector<str> g[100005];

ll n;
ll par[100005];
bool vis[100005];
ll rev[100005];
ll fow[100005];
ll sprst[100005][22];
ll fwt[100005][22];
ll ret[100005][22];
ll L[100005];

ll query(ll p,ll q)
{
    ll log,temp;
    ll ans=0;

    log =1;
    while(1)
    {
        ll next = log+1;
        if((1<<next)>L[p] && (1<<next)>L[q])break;
        log++;
    }
//    cout<<log<<endl;
    if(L[p]>L[q])
    {
        for(ll i=log; i>=0; i--)
        {
            if(L[p]-(1<<i)>=L[q])
            {
                ans+=ret[p][i];
                p=sprst[p][i];
            }
        }
        if(p==q)
            return ans;
    }
    else
    {
//        cout<<ans<<endl;
        for(ll i=log; i>=0; i--)
        {
            if(L[q]-(1<<i)>=L[p])
            {
                ans+=fwt[q][i];
                q=sprst[q][i];
//                cout<<"hhhh "<<fwt[q][i]<<endl;
            }
        }
//        cout<<p<<" "<<q<<" "<<ans<<endl;
        if(p==q)
            return ans;
    }

    for(ll i=log; i>=0; i--)
    {
        if(sprst[p][i]!=-1 && sprst[p][i]!=sprst[q][i])
        {
            ans+=(ret[p][i]+fwt[q][i]);
            p=sprst[p][i],q=sprst[q][i];
        }
    }
    ans+=(rev[p]+fow[q]);
    return ans;

}

void init()
{
    memset(sprst,-1,sizeof sprst);
    memset(fwt,0,sizeof fwt);
    memset(ret,0,sizeof ret);
    for(ll i=0; i<=n; i++)
    {
        sprst[i][0]=par[i],fwt[i][0]=fow[i],ret[i][0]=rev[i];
//        debug(i);
//        debug(ret[i][0]);
    }
    //debug(sprst[1][0]);
    for(ll j=1; (1<<j)<=n; j++)
    {
        for(ll i=1; i<=n; i++)
        {
            if(sprst[i][j-1]!=-1)
            {
                sprst[i][j]= sprst[sprst[i][j-1]][j-1];
                fwt[i][j] = fwt[sprst[i][j-1]][j-1]+fwt[i][j-1];
                ret[i][j] = ret[sprst[i][j-1]][j-1]+ret[i][j-1];

            }
        }
    }
}

void dfs(ll x,ll l)
{
    vis[x]=true;
    ll sz= g[x].size();
    struct str y;
    for(ll i=0; i<sz; i++)
    {
        y= g[x][i];
        if(vis[y.d])
            continue;
        par[y.d]=x;
        fow[y.d] = y.w2;
        rev[y.d] = y.w1;
        L[y.d] = l+1;
        dfs(y.d,l+1);
    }
}



int main()
{
    //ios_base::sync_with_stdio(false);
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        memset(vis,false,sizeof vis);
        memset(par,-1,sizeof par);
        for(int i=0; i<100005; i++)
            g[i].clear();
        scanf("%lld",&n);
        ll tot=0;
        ll u,v,c1,c2;
        for(ll i=0; i<n-1; i++)
        {
            scanf("%lld%lld%lld%lld",&u,&v,&c1,&c2);
            tot+=(c1+c2);
            g[u].push_back({v,c1,c2});
            g[v].push_back({u,c2,c1});
        }
        L[1]=0;
        dfs(1,0);
        init();
        ll m,x,y;
        scanf("%lld",&m);
        //debug(tot);
        while(m--)
        {
            scanf("%lld%lld",&x,&y);
            printf("%lld\n",tot-query(x,y));
        }

    }
    return 0;
}


/*
2
10
10 5 8 19
5 4 2 1
4 7 21 7
9 4 4 4
2 6 4 1
6 5 15 10
3 6 7 5
1 3 2 11
8 2 3 6
2
3 5
10 6
5
1 2 5 10
3 5 25 3
4 2 15 12
3 2 6 7
2
1 5
4 3
*/
