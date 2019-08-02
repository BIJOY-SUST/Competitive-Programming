#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<< #x" " << x << endl;
#define ll long long
ll m = 1000000007;
ll n;
ll a[100005];
//ll rec(ll pos,ll con,ll jin)
//{
//    //debug(pos);
//    if(pos>n)
//        return 0;
//    ll newcon = (((a[pos]-1)*jin)%m+(con*a[pos])%m)%m;
//    // debug(newcon);
//    ll newjin = (jin*a[pos])%m;
//    //debug(newjin);
//    return max(newcon,rec(pos+1,newcon,newjin)%m);
//}
//ll con =a[1]-1;
//ll jin = a[1];
//for(int i=2; i<=n; i++)
//{
//    con = (((a[i]-1)*jin)%m+(con*a[i])%m)%m;
//    jin = (jin*a[i])%m;
//}
int main()
{
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t ;
    while(t--)
    {
        cin >> n;
        for(ll i=1; i<=n; i++)
        {
            cin >> a[i];
        }

        ll con =a[1]-1;
        ll jin = a[1];
        for(int i=2; i<=n; i++)
        {
            con = (((a[i]-1)*jin)%m+(con*a[i])%m)%m;
            jin = (jin*a[i])%m;
        }
        cout<< con<<endl;
//        if(n==1)
//            cout<< a[1]-1<<endl;
//        else
//            cout<< rec(2,a[1]-1,a[1])%m<<endl;
    }
    return 0;
}
