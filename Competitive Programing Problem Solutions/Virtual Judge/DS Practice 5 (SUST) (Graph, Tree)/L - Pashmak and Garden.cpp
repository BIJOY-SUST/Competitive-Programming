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
    int x1,x2,y1,y2,x3,x4,y3,y4;
    while(cin>>x1>>y1>>x2>>y2){
        if(y1==y2&&x1!=x2){
            x3=x2;
            y3=y2+abs(x2-x1);
            x4=x1;
            y4=y2+abs(x2-x1);
            cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<"\n";
        }
        else if(x1==x2&&y1!=y2){
            y3=y2;
            x3=x2+abs(y2-y1);
            y4=y1;
            x4=x2+abs(y2-y1);
            cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<"\n";
        }
        else if(abs(x2-x1)==abs(y2-y1)){
            x3=x2;
            y3=y1;
            x4=x1;
            y4=y2;
            cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<"\n";
        }
        else{
            cout<<-1<<"\n";
        }
    }
    return 0;
}
