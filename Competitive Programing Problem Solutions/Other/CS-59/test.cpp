#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
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

int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int g1,p1,g2,p2;
    scanf("%d%d%d%d",&g1,&p1,&g2,&p2);
    int ans1,ans2;
    if((g1*p1)%100==0){
        ans1=(g1*p1)/100;
    }
    if((g1*p1)%100!=0){
        ans1=(g1*p1)/100;
        ans1+=1;
    }
    ans2=(g2*(p2+.999))/100;
//    cout<<ans1<<" "<<ans2<<endl;
    if(ans1>ans2){
        printf("%d\n",ans1-ans2);
    }
    else{
        printf("%d\n",ans2-ans1);
    }
    return 0;
}
/*

*/
