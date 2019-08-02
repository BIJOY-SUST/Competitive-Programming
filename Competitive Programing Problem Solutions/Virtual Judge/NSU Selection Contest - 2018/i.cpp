#include<bits/stdc++.h>
//#define mx             100010
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
//#define pp             pair<int,int>
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//int biton(int p,int pos){return p=p|(1<<pos);}
//int bitoff(int p,int pos){return p=p&~(1<<pos);}
//bool bitcheck(int p,int pos){return (bool)(p&(1<<pos));}
//ll POW(ll b,ll p) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
//ll BigMod(ll b,ll p,ll Mod) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
//ll ModInverse(ll p,ll Mod) {return BigMod(p,Mod-2,Mod);}
using namespace std;
vector<string>v;
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d",&t);
    while(t--){
        v.clear();
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            v.push_back(s);
        }
        sort(v.begin(),v.end());
        bool f=false;
        for(int i=0;i<n-1;i++){
            //for(int j=i+1;j<n;j++){
                //if(i==j) continue;
                string a=v[i],b=v[i+1];
                int cnt=0;
                for(int k=0;k<min(a.length(),b.length());k++){
                    if(a[k]==b[k]){
                        cnt++;
                    }
                }
                if(cnt==min(a.length(),b.length())){
                    f=true;
                    break;
                }
            //}
        }
        if(f){
            cout<<"NO\n";
        }
        else cout<<"YES\n";
    }
    return 0;
}
/**
Input:

Output:

**/
