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
vector<pair<int,int> >v1,v2;
//bool compare(const pair<int,int> &a,const pair<int,int> &b){
//    return a.first<b.first;
//}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    ll ans1=0;
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        ans1+=y;
        if(x>0) v1.push_back(make_pair(x,y));
        else v2.push_back(make_pair(x,y));
    }
    int a=v1.size(),b=v2.size();
    if(a==b) printf("%lld\n",ans1);
    else if(a>b){
        ll ans2=0;
//        sort(v1.begin(),v1.end(),compare);
        sort(v2.rbegin(),v2.rend());
//        for(int i=0;i<b;i++){
//            printf("%d %d\n",v2[i].first,v2[i].second);
//        }
        for(int i=0;i<b;i++) ans2+=v2[i].second;
//        sort(v2.begin(),v2.end(),compare);
        sort(v1.begin(),v1.end());
        for(int i=0;i<b+1;i++) ans2+=v1[i].second;
        printf("%lld\n",ans2);
    }
    else{
        ll ans2=0;
//        sort(v2.begin(),v2.end(),compare);
        sort(v1.begin(),v1.end());
        for(int i=0;i<a;i++) ans2+=v1[i].second;
        sort(v2.rbegin(),v2.rend());
//        sort(v1.begin(),v1.end(),compare);
        for(int i=0;i<a+1;i++) ans2+=v2[i].second;
        printf("%lld\n",ans2);
    }
    return 0;
}

