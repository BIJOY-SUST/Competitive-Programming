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
class data{
public:
    int prob;
    int time;
};
bool compare(data a,data b){
//    if(a.prob>a.prob) return true;
//    else if(a.prob==b.prob&&a.time<b.time) return true;
//    else return false;
    return a.prob>b.prob|(a.prob==b.prob&&a.time<b.time);
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,k;
    data ob[101];
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d %d",&ob[i].prob,&ob[i].time);
    }
    sort(ob,ob+n,compare);
//    for(int i=0;i<n;i++){
//        printf("%d %d\n",ob[i].prob,ob[i].time);
//    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(ob[i].prob==ob[k-1].prob&&ob[i].time==ob[k-1].time){
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
