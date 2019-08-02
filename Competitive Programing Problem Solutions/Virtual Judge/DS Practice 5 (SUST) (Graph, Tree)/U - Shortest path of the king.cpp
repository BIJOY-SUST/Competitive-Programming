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
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    string s1,s2;
    cin>>s1>>s2;
    int x1=s1[0]-'a'+1,y1=s1[1]-'0',x2=s2[0]-'a'+1,y2=s2[1]-'0';
    int ans=max(abs(x1-x2),abs(y1-y2));
    printf("%d\n",ans);
//    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    while(x2>x1&&y2>y1){
        printf("RU\n");
        x1++;
        y1++;
    }
    while(x1<x2&&y2<y1){
        printf("RD\n");
        x1++;
        y1--;
    }
    while(x1>x2&&y2>y1){
        printf("LU\n");
        x1--;
        y1++;
    }
    while(x1>x2&&y1>y2){
        printf("LD\n");
        x1--;
        y1--;
    }
    while(x1==x2&&y2>y1){
        printf("U\n");
        y1++;
    }
    while(x1==x2&&y2<y1){
        printf("D\n");
        y1--;
    }
    while(y1==y2&&x2<x1){
        printf("L\n");
        x1--;
    }
    while(y1==y2&&x2>x1){
        printf("R\n");
        x1++;
    }
    return 0;
}
