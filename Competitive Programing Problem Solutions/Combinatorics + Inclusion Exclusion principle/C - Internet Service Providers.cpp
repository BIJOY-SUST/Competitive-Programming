/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
#include<bits/stdc++.h>
//#define pi             3.141592653589793238462643383
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
#define ll             long long int
//#define llu            unsigned long long int
//#define mx             100001
//#define mod            100000007
//const long long inf =  1e15;
/*----------------------Graph Moves------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
/*---------------------------------------------------*/
/*-----------------------Bitmask---------------------*/
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
/*---------------------------------------------------*/
using namespace std;

int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        ll n,c;
        scanf("%lld %lld",&n,&c);

        if(n==0){
            printf("Case %d: %d\n",tc,0);
        }
        else{
            ll ans1=floor(c/(2*n));
            ll ans2=ans1+1;
            if(ans1*(c-ans1*n)>=ans2*(c-ans2*n)){
                printf("Case %d: %lld\n",tc,ans1);
            }
            else{
                printf("Case %d: %lld\n",tc,ans2);
            }
        }
    }
    return 0;
}
/*
input:
4
45 54
4654 4546
100 120
120 100
My AC Output :
Case 1: 1
Case 2: 0
Case 3: 1
Case 4: 0
*/
