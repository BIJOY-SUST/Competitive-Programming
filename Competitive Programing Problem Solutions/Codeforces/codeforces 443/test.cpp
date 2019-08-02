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
vector<ll>v;
map<ll,ll>mmm;
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    ll n,k;
    scanf("%lld %lld",&n,&k);
    for(int i=0;i<n;i++){
        ll h;scanf("%lld",&h);
        v.push_back(h);
    }
    ll c1=0,c2=0,ans,i=0;
    bool flag=false;
    while(1){
        if(flag) break;
        while(v[i]>v[i+1]){
            //c1++;
            //c2=0;
            mmm[v[i]]++;
            v.push_back(v[i+1]);
            v.erase(v.begin()+1);
            if(mmm[v[i]]==k||mmm[v[i]]>n){
                ans=v[i];
                flag=true;
                break;
            }
        }
        if(flag) break;
        while(v[i]<v[i+1]){
//            c2++;
//            c1=0;
            mmm[v[i+1]]++;
            v.push_back(v[i]);
            v.erase(v.begin());
            if(mmm[v[i+1]]==k||mmm[v[i+1]]>n){
                ans=v[i+1];
                flag=true;
                break;
            }
        }
        if(flag) break;
    }
    printf("%lld\n",ans);
    return 0;
}
