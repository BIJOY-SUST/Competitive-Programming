#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
#define ll             long long int
//#define llu            unsigned long long int
#define mx             500010
//#define mod            100000007
//const long long inf =  1e15;
//----------------------Graph Moves--------------------
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//-----------------------------------------------------
//-----------------------Bitmask-----------------------
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
//-----------------------------------------------------
using namespace std;
ll x[mx],d[mx];
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=0;i<n;i++) scanf("%lld",&x[i]);
        for(int i=0;i<q;i++) scanf("%lld",&d[i]);
        ll product=1;
        for(int i=0;i<n;i++)
            if(product<=1000000010) product*=x[i];
//        double ans=1/(float)x[0];
//        for(int i=1;i<n;i++){
//            ans=(double)((double)ans/(double)x[i]);
//        }
        for(int i=0;i<q;i++){
            ll ans2=floor(d[i]/product);
            if(i==q-1) printf("%lld",ans2);
            else printf("%lld ",ans2);
        }
        printf("\n");
    }
    return 0;
}
/*

*/
