#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(lli i  = (lli)(a); i < (lli)(b);i++)
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(v) (v).size()
#define all(v) (v).begin(), (v).end()
#define trace(x) cout << #x << ": " << x << endl;

typedef long long int lli;
typedef pair<lli, lli> ii;
typedef pair<ii, lli> iii;
typedef vector<lli> vi;
typedef vector<ii> vii;
typedef double C;
const int N=2*1e5+9;

vector<lli> v;


bool check(lli mid,lli medio,lli n,lli k){

    lli queda=k-(mid-v[medio]);
    lli ant=mid;
    lli ind=medio+1;

    while(ind<=n){
        if(v[ind]<ant){
            lli need=(ant)-v[ind];
            if(need>queda) return false;
            ant=v[ind]+need;
            queda-=need;
        }
        ind++;
    }
    return true;
}


int main(){
    // fastio;
    v.pb(0);
    lli n,k; cin>>n>>k;
    rep(i,1,n+1){
        lli num; cin>>num;
        v.pb(num);
    }
    sort(all(v));
    lli medio=(n+1)/2;
    lli low=v[medio],high=v[medio]+k;


    while((low+1)!=high){
        lli mid=(low+high)/2;
        if(check(mid,medio,n,k)) low=mid;
        else high=mid;
    }
    trace(high);
    trace(low);
    if(check(high,medio,n,k)) cout<<high;
    else cout<<low;

    return 0;
}
