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
vector<int>v1,v2;
map<int,int>mapping1;
map<int,int>mapping2;
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int h;scanf("%d",&h);
        v1.push_back(h);
        v2.push_back(h);
        mapping1[h]++;
        //mapping2[i]=h;
    }
    sort(v1.rbegin(),v1.rend());
    v1.erase(unique(v1.begin(),v1.end()),v1.end());
    int k=1;
    for(int i=0;i<v1.size();i++){
        mapping2[v1[i]]=k;
        k+=mapping1[v1[i]];
    }
    for(int i=0;i<n;i++){
        printf("%d ",mapping2[v2[i]]);
    }
    return 0;
}
