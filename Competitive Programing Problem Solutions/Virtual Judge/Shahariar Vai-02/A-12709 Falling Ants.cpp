#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define p              pair<int,int>
#define ll             long long int
//#define one(n)         _builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
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

int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    while(scanf("%d",&n)){
        if(n==0) break;
        int low=0;
        ll ans=0;
        for(int i=0;i<n;i++){
            int l,w,h;
            scanf("%d %d %d",&l,&w,&h);
            if(h==low){
                ll t_ans=(ll)l*w*h;
                if(t_ans>ans) ans=t_ans;
            }
            if(h>low){
                low=h;
                ans=(ll)l*w*h;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
Sample Input
3
3 4 5
12 1 5
20 10 4
3
3 4 5
20 30 5
1 2 4
0
Sample Output
60
3000
*/
