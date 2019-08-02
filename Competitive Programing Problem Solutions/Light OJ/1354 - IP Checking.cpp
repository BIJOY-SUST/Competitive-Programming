#include<bits/stdc++.h>

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
#define one(x)         __builtin_popcount(x)
#define mem(arr,val)   memset(arr,val,sizeof(arr))
#define unique(x)      x.erase(unique(x.begin(),x.end()),x.end())
#define fast           ios_base::sync_with_stdio(false),cin.tie(NULL)
#define forstl(x)      for(__typeof(x.begin()) it=(x.begin());it!=(x.end());++it)
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
template <typename T> bool bitcheck(T p,T pos){return (bool)(p&(1<<pos));}
template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
template <typename T> ll toint(T s) {ll p;stringstream ss(s); ss>>p; return p;}
template <typename T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    ll t;
    scanf("%lld",&t);
    for(ll cs=1;cs<=t;cs++){
        string s1,s2;
        cin>>s1;
        cin>>s2;
        vector<ll>no;
        string tem="";
        for(int i=0;i<s1.length();i++){
            if(s1[i]!='.') tem+=s1[i];
            else{
                ll d=toint(tem);
                //bitset<8>bin_x(d);
                no.push_back(d);
                tem="";
            }
        }
        ll d=toint(tem);
        no.push_back(d);

//        forstl(no) cout<<*it<<endl;
        bool f=false;
        int h=0;
        for(int i=0;i<s2.length();i+=8){
            if(i!=0) i+=1;
//            cout<<i<<endl;
            bitset<8>bin(no[h]);
//            cout<<bin<<endl;
            h++;
            string dd=tostring(bin);
//            cout<<dd[2]<<endl;
            int k=i;
            for(int j=0;j<8;j++){
//                cout<<dd[j]<<" "<<s2[k]<<endl;
                if(dd[j]!=s2[k]){
                    f=true;
                }
                k++;
            }

        }
        printf("Case %lld: ",cs);
        if(f){
            cout<<"No\n";
        }
        else{
            cout<<"Yes\n";
        }
    }
    return 0;
}
