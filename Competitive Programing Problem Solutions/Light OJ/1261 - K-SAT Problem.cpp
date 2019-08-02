#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define pp             pair<int,int>
//#define ll             long long int
//#define bug(x)         printf("X: %d\n",x)
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
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
vector<int>pos[50],neg[50];
vector<int>v;
int ans[50];
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        mem(ans,0);
        for(int i=0;i<50;i++){
            pos[i].clear();
            neg[i].clear();
        }
        v.clear();
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++){
            char ch;
            int h;
            for(int j=0;j<k;j++){
//                scanf("%c %d",&ch,&h);
                cin>>ch>>h;
//                cout<<ch<<" "<<h<<endl;
                if(ch=='+') pos[i].push_back(h);
                else neg[i].push_back(h);
            }
        }
//        cout<<pos[1].size()<< " "<<neg[1].size()<<endl;
        int p; scanf("%d",&p);
        while(p--){
            int h; scanf("%d",&h);
            v.push_back(h);
        }
        for(int i=1;i<=n;i++){
            bool ff=false;
            for(int j=0;j<pos[i].size();j++){
                bool f=binary_search(v.begin(),v.end(),pos[i][j]);
                if(f){
                    ans[i]++;
                    ff=true;
//                    cout<<f<<endl;
                    break;
                }
            }
            if(ff==false)
            for(int j=0;j<neg[i].size();j++){
                bool f=binary_search(v.begin(),v.end(),neg[i][j]);
//                cout<<f<<endl;
                if(!f){
                    ans[i]++;
                    break;
                }
            }
        }
        bool flag=false;
        for(int i=1;i<=n;i++){
//            cout<<i<<" "<<ans[i]<<endl;
            if(ans[i]==0){
                flag=true;
                break;
            }
        }
//        cout<<flag<<endl;
        if(flag){
            printf("Case %d: No\n",cs);
        }
        else{
            printf("Case %d: Yes\n",cs);
        }
    }
    return 0;
}
/*

*/
