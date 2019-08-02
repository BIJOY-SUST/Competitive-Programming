#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cout<< #x <<"= " << x << endl;
#define mem(a,b) memset((a),(b),sizeof(a))

int dx[]={1,-1,0,0,1,1,-1,-1};
int dy[]={0,0,1,-1,1,-1,1,-1};

bool mark[100005];
vector<int> v;
ll N= 100005;
/*sieve(){
    mem(mark,true);
    for(int i=4;i<=N;i+=2) mark[i]=false;
    for(int i=3;i<=(int)sqrt(N);i+=2){
        if(mark[i]) for(int j=i*i;j<=N;j+=2*i){
            mark[j]=false;
        }
    }
    v.push_back(2);
    for(int i=3;i<=N;i+=2) if(mark[i]) v.push_back(i);
}*/

vector<ll> g;
vector<ll> b;

void gdivs(ll a)
{
    ll s=sqrt(a);
    for(int i=1;i<=s;i++)
    {
        if(a%i==0)
        {
            if(a/i==i)
            {
                g.push_back(i);
            }
            else
            {
                g.push_back(i);
                g.push_back(a/i);
            }
        }
    }
}
void bdivs(ll a)
{
    ll s=sqrt(a);
    for(int i=1;i<=s;i++)
    {
        if(a%i==0)
        {
            if(a/i==i)
            {
                b.push_back(i);
            }
            else
            {
                b.push_back(i);
                b.push_back(a/i);
            }
        }
    }
}
int main(){
    ll t;
    cin >> t;
    for(int tt=1;tt<=t;tt++){
        b.clear();
        g.clear();
        ll n,bb;
        cin >> n >> bb;
        ll gg=n-bb;
        gdivs(gg);
        bdivs(bb);
        sort(b.begin(),b.end());
        sort(g.begin(),g.end());
        ll sum=0;
        for(int i=0;i<g.size();i++){
          ll k=lower_bound(b.begin(),b.end(),g[i])-b.begin();
          sum+=k;
        }
        cout<< "Case "<< tt << ": "<< sum << endl;
    }
    return 0;
}
