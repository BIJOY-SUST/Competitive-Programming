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
        ll w,even=1,odd;
        scanf("%lld",&w);
        odd=w;
        bool flag=false;
        while(1){
            if((odd&1)==0){
                odd=odd>>1;
                even=even<<1;
                if(odd&1){
                    flag=true;
                    break;
                }
            }
            else break;
        }
        if(flag) printf("Case %d: %lld %lld\n",tc,odd,even);
        else printf("Case %d: Impossible\n",tc);

    }
    return 0;
}
/*
Input
11
36
516
16660
600
1188
2222556
222222
93222
6666666666666666666
7777777777777778888
1999999999999999000

Output
Case 1: 9 4
Case 2: 129 4
Case 3: 4165 4
Case 4: 75 8
Case 5: 297 4
Case 6: 555639 4
Case 7: 111111 2
Case 8: 46611 2
Case 9: 3333333333333333333 2
Case 10: 972222222222222361 8
Case 11: 249999999999999875 8
*/

