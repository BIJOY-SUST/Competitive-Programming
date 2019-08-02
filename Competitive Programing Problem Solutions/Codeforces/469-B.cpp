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
bool mm[1005];
vector<pair<int,int> >vv,uu;
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(mm,false,sizeof(mm));
    int p,q,l,r;
    scanf("%d%d%d%d",&p,&q,&l,&r);
    while(p--){
        int a,b;
        scanf("%d%d",&a,&b);
        //for(int i=a;i<=b;i++) mm[i]=true;
        uu.push_back({a,b});
    }
    while(q--){
        int c,d; scanf("%d%d",&c,&d);
        vv.push_back({c,d});
    }
    int ans=0;
    for(int i=l;i<=r;i++){
        for(int j=0;j<vv.size();j++){
//            if(mm[vv[j].first+i]==true||mm[vv[j].second+i]==true){
//                ans++;
//            //if(i==3) cout<<"g"<<endl;
//                break;
//            }
//            //if(i==3) cout<<"kan"<<endl;
            for(int k=0;k<uu.size();k++){
                //if(i==3) cout<<"g"<<endl;
                if(vv[j].first+i<=uu[k].first&&uu[k].first<=vv[j].second+i){
                    ans++;
                    //cout<<j<<" "<<k<<endl;
                    //if(i==3) cout<<"g"<<endl;
                    goto x;
                }
                if(vv[j].first+i<=uu[k].second&&uu[k].second<=vv[j].second+i){
                    ans++;
                    goto x;
                }
                if(vv[j].first+i>=uu[k].first&&vv[j].second+i<=uu[k].second){
                    ans++;
                    goto x;
                }
            }
        }
        x:
            int d=1;
    }
    printf("%d\n",ans);
    return 0;
}
/*

*/
