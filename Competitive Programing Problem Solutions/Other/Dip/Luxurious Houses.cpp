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
//#define ll             long long int
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n;
    int v[10001];
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int d=0;
    int vv[100001];
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            vv[i]=0;
            d=max(d,v[i]);
            continue;
        }
        else if(d==v[i]){
            vv[i]=1;
        }
        else if(v[i]>d){
            vv[i]=0;
            d=v[i];
        }
        else{
            vv[i]=d-v[i]+1;
        }
    }
    for(int i=0;i<n;i++){
        cout<<vv[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
