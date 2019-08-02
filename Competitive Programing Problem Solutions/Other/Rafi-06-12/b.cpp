#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define p              pair<int,int>
#define ll             long long int
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
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
using namespace std;

int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    ll n;
    scanf("%lld",&n);

    ll ans=n%4;
    //ans++;
    if(n==0){
        printf("1\n");
    }
//    else if(ans==0){
//        printf("8")
//    }
    else if(ans==1){
        printf("8\n");
    }
    else if(ans==2){
        printf("4\n");
    }
    else if(ans==3){
        printf("2\n");
    }
    else if(ans==0){
        printf("6\n");
    }
    return 0;
}
/*

*/
