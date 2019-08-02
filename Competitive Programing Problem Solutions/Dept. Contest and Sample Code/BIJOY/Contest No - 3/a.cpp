#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
//#define ll             long long int
//#define llu            unsigned long long int
//#define mx             10000010
//#define mod            100000007
//const long long inf =  1e15;
//----------------------Graph Moves--------------------
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//-----------------------------------------------------
//-----------------------Bitmask-----------------------
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
//-----------------------------------------------------
using namespace std;

int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    string u,v;
    cin>>u;
    cin>>v;
    bool flag=false;
    if(u.length()>v.length()){
        printf("GREATER\n");
    }
    else if(u.length()<v.length()){
        printf("LESS\n");
    }
    else{
        for(int i=0;i<u.length();i++){
            if(u[i]-'0'>v[i]-'0'){
                printf("GREATER\n");
                flag=true;
                break;
            }
            else if(u[i]-'0'<v[i]-'0'){
                printf("LESS\n");
                flag=true;
                break;
            }
        }
        if(flag==false){
            printf("EQUAL\n");
        }
    }
    return 0;
}
