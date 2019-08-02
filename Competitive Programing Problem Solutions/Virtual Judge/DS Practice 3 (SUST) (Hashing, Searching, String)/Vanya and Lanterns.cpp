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
//#define mx             1000001
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
//int biton(int N,int pos){return N=N(1<<pos);}
//int bitoff(int N,int pos){return N=N&~(1<<pos);}
//bool check(int N,int pos){return (bool)(N&(1<<pos));}
/*---------------------------------------------------*/
using namespace std;
vector<int>v;
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        int h;
        scanf("%d",&h);
        v.push_back(h);
    }
    sort(v.begin(),v.end());
//    for(int i=0;i<n;i++){
//        cout<<v[i]<<endl;
//    }
    int d=0;
    for(int i=0;i<n-1;i++){
        int dd=v[i+1]-v[i];
        if(dd>d) d=dd;
    }
//cout<<d<<endl;
    d=max(d,2*(v[0]-0));
    d=max(d,2*(k-v[n-1]));
    printf("%f\n",(float)d/2);

    return 0;
}
