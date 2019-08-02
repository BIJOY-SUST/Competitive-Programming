/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
#include<bits/stdc++.h>
//#define pi             3.141592653589793238462643383
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define ll             long long int
//#define llu            unsigned long long int
#define mx             100000001
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
int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
bool check(int n,int pos){return (bool)(n&(1<<pos));}
/*---------------------------------------------------*/
using namespace std;
int mark[mx>>5];
vector<int>prime;
void sieve(){
    memset(mark,0,sizeof(mark));
    for(int i=3;i<=(int)sqrt(mx);i+=2){
        if(!check(mark[i>>5],i&31)) for(int j=i*i;j<=mx;j+=i<<1)
            mark[j>>5]=biton(mark[j>>5],j&31);
    }
    prime.push_back(2);
    for(int i=3;i<=mx;i+=2) if(!check(mark[i>>5],i&31)) prime.push_back(i);
}
int main(){
    sieve();
    for(int i=1;i<=prime.size();i+=100){
        printf("%d\n",prime[i-1]);
    }
    return 0;
}
