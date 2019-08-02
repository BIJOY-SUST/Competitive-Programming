#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mx             100010
#define inf            0x3f3f3f3f
#define mod            1000000007
#define PI             2*acos(0.0)
#define E              2.71828182845904523536
#define ll             long long int
#define ull            unsigned long long int
#define pii            pair<int,int>
#define pll            pair<ll,ll>
#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
#define fast           ios_base::sync_with_stdio(false),cin.tie(NULL)
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
template <typename T> bool bitcheck(T p,T pos){return (bool)(p&(1<<pos));}
template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
template <typename T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//********************************************Code Start Here*********************************************************//

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    vector<pll >v;
    for(int cs=1;cs<=t;cs++){
        ll d,n;
        v.clear();
        scanf("%lld%lld",&d,&n);
        for(ll i=0;i<n;i++){
            ll k,s;
            scanf("%lld%lld",&k,&s);
            v.push_back({k,s});
        }
        sort(v.begin(),v.end());
        if(n==1){
            double t=(double)(d-v[0].first)/v[0].second*1.0;
            double ans=(double)d/t*1.0;
            printf("Case #%d: %.6f\n",cs,ans);
        }
        else if(n==2){
            if(v[0].second>v[1].second){
                double vt=(double)v[0].second-(double)v[1].second;
                double dd=(double)v[1].first-(double)v[0].first;
                double t=(double)dd/vt*1.0;
                double s=(double)v[1].second*t;
//                    cout<<t<< " "<<d<<" "<<" "<<s<<endl;
                s+=v[1].first;
                if(s<=d){
                    double t2=(double)(d-s)/v[1].second*1.0;
                    double ans=(double)d/(t+t2)*1.0;
                    printf("Case #%d: %.6f\n",cs,ans);
                }
                else{
                    cout<<s<<" "<<t<<endl;
                    double t2=(double)(d-v[0].first)/v[0].second*1.0;
                    double ans=(double)d/t2*1.0;
                    printf("Case #%d: %.6f\n",cs,ans);
                }
            }
            else{
                double t=(double)(d-v[0].first)/v[0].second*1.0;
                double ans=(double)d/t*1.0;
                printf("Case #%d: %.6f\n",cs,ans);
            }
        }
        else printf("Case #%d: %.6f\n",cs,5.9);
        /*else{
            ll i=0;
            ll ans=0;
            while(v.size()!=1){
                ll i=0;
                sort(v.begin(),v.end());
                vector<pair<double,double> >dis;
                for(ll j=i+1;j<v.size();j++){
                    if(v[j].second<v[i].second){
                        double vt=(double)v[i].second-(double)v[j].second;
                        double dd=(double)v[j].first-(double)v[i].first;
                        double t=(double)dd/vt*1.0;
                        double s=(double)v[j].second*t;
        //                    cout<<t<< " "<<d<<" "<<" "<<s<<endl;
                        s+=v[j].first;
                        if(s<d) dis.push_back({s,t});
                    }
                }

                sort(dis.begin(),dis.end());
                ans+=dis[0].second;
                ll cnt=0;
                for(auto x:v){
                    if(dis[0].first>x.first){
                        cnt++;
                    }
                }
                if(cnt) v.erase(v.begin()+cnt-1);
                else v.erase(v.begin());
                dis.clear();
            }
            printf("Case #%d: %.6f\n",cs,ans);
        }
        */
    }
    return 0;
}
/*

*/
