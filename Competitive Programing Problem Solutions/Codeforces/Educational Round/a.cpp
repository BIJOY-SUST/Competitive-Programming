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
vector<int>v;
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,k;
    int h=86400;
    scanf("%d %d",&n,&k);
    int d=0;
    for(int i=0;i<n;i++){
        int f;
        scanf("%d",&f);
        v.push_back(f);
    }
    int c=0;
    for(int i=0;i<n;i++){
        if(v[i]<h){
            k=k-(h-v[i]);
        }
        if(k<=0){
            c=i+1;
            break;
        }
    }
    printf("%d\n",c);
//    if(d>k){
//        if(k<h) printf("1\n");
//        else printf("%d\n",((int)(k/h))+1);
//    }
//    if(d%h==0) printf("%d\n",d/h);
//    else if(d<h) printf("1\n");
//    else printf("%d\n",((int)(d/h))+1);
    return 0;
}
