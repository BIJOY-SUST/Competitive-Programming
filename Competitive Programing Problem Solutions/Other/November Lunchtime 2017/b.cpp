#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
#define ll             long long int
#define llu            unsigned long long int
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
ll arr[mx];
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++){
            // k;scanf("%d",&k);
            scanf("%lld",&arr[i]);
        }
        for(int h=1;h<=q;h++){
            ll c,l,r;
            scanf("%lld %lld %lld",&c,&l,&r);
            ll mm=-99999999;
            if(c==1){
                for(int i=l;i<=r;i++){
                    ll dd=(arr[i]-arr[l])*(arr[r]-arr[i]);
                    if(mm<dd) mm=dd;
                }
                printf("%lld\n",mm);
            }
            else{
                arr[l]=r;
            }
        }
    }
    return 0;
}
/*

*/
