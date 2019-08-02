#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define p              pair<int,int>
//#define ll             long long int
//#define ull            unsigned long long int
//#define mx             100001
//#define mod            1000000007
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
using namespace std;
p solve(int g,int w){
    p ans;
    bool flag=false;
    for(int i=0;i<=g;i++){
        if(i*100/g==w&&!flag){
            ans.first=i;
            flag=true;
        }
        if(i*100/g==w) ans.second=i;
    }
    return ans;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int g1,p1,g2,p2;
    scanf("%d %d %d %d",&g1,&p1,&g2,&p2);
    int ans1,ans2;
    p pp1=solve(g1,p1);
    p pp2=solve(g2,p2);
    int ans=pp2.second-pp1.first;
    ans=min(ans,g2-g1);
    printf("%d\n",ans);
    return 0;
}
/*

*/
