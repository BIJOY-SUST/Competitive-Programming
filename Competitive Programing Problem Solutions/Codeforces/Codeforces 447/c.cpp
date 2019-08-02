#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
//#define ll             long long int
//#define llu            unsigned long long int
#define mx             10000010
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
vector<int>a;
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    //printf("%d\n",__gcd(4,12));
    int m;
    scanf("%d",&m);
    int mm=mx;
    for(int i=1;i<=m;i++){
        int x;scanf("%d",&x);
        a.push_back(x);
        if(mm>x) mm=x;
    }
    int hh=mm;
    for(int i=0;i<m;i++){
            hh=__gcd(hh,a[i]);
    }
    if(mm==hh){
        printf("%d\n",(2*m)-1);
        printf("%d",a[0]);
        for(int i=1;i<m;i++){
            printf(" %d %d",mm,a[i]);
        }
        printf("\n");
    }
    else{
        printf("-1\n");
    }
    return 0;
}
/*

*/
