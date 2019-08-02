/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
#include<bits/stdc++.h>
//#define pi             3.141592653589793238462643383
//#define pi             2*acos(0.0)
#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
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
char s[101][101];
char ch,ch1='W',ch2='B';
void dfs(int x,int y){
    if((x+y)%2==1){
        s[x][y]=ch1;
    }
    else{
        s[x][y]=ch2;
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int r,c;
    scanf("%d%d",&r,&c);
    for(int i=0;i<r;i++){
        scanf("%s",s[i]);
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(s[i][j]=='.'){
                dfs(i,j);
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%c",s[i][j]);
        }
        printf("\n");
    }
    return 0;
}
