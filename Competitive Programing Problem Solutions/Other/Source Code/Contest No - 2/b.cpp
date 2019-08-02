#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
#define ll             long long int
//#define llu            unsigned long long int
#define mx             100010
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
    int n;
    scanf("%d",&n);
    int c=0,t=0,tt=0;
    for(int i=0;i<n;i++){
        ll x;
        scanf("%lld",&x);
        if(x%4==0){
            c++;
        }
        else if(x%4!=0&&x%2==0) t++;
        else if(x%4!=0&&x%2!=0) tt++;
    }
    if(t%2) tt++;
    if(c>=tt) printf("Yes\n");
    else if(abs(c-tt)==1) printf("Yes\n");
    else printf("No\n");
    return 0;
}























//    for(int i=0;i<n;i++){
//        if(arr[i]%4==0){
//            flag=true;
//        }
//        else flag=false;
//    }
