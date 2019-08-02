#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
#define ll             long long int
//#define llu            unsigned long long int
//#define mx             10000010
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
int arr[101];
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    ll ans=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        ans+=arr[i];
    }
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int p,x;
        scanf("%d %d",&p,&x);
        ll ans2=ans;
        ans2=ans2-arr[p]+x;
        printf("%lld\n",ans2);
    }
    return 0;
}

