#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
//#define ll             long long int
//#define llu            unsigned long long int
//#define mx             100001
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
int v[365];

int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    int cnt=0,ans=0;
    while(cnt<n){
        int sum=0;
        int j=cnt;
        sum+=v[j];
        j++;
        if(j==n) j=0;
        bool f=false;
        while(sum+v[j]<=180){
            sum+=v[j];
            j++;
            if(j==n) j=0;

        }
        ans=max(ans,sum);
        cnt++;
    }
    printf("%d\n",2*abs(ans-180));
    return 0;
}
/*

*/
