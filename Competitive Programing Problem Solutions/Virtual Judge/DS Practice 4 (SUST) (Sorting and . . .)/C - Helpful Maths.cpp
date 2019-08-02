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
    int a=0,b=0,c=0;;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1') a++;
        else if(s[i]=='2') b++;
        else if(s[i]=='3') c++;
    }
    bool flag=true;
    for(int i=0;i<a;i++){
        if(flag==true){
            printf("1");
            flag=false;
        }
        else printf("+1");
    }
    for(int i=0;i<b;i++){
        if(flag==true){
            printf("2");
            flag=false;
        }
        else printf("+2");
    }
    for(int i=0;i<c;i++){
        if(flag==true){
            printf("3");
            flag=false;
        }
        else printf("+3");
    }
    return 0;
}
