#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define p              pair<int,int>
#define ll             long long int
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
using namespace std;

int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    ll n,x;
    scanf("%lld %lld",&n,&x);
    ll lef=x,child=0;
    char ch;
    ll d;
    for(ll i=0;i<n;i++){
//        scanf("%c %lld",&ch,&d);
        cin>>ch>>d;
        if(ch=='+'){
            lef=lef+d;
        }
        else{
            if(lef>=d){
                lef=lef-d;
            }
            else{
                child++;
            }
        }
    }
    printf("%lld %lld\n",lef,child);
    return 0;
}
/*

*/
