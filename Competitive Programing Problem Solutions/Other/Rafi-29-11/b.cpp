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
    int n,d;
    scanf("%d %d",&n,&d);
    string ss="0";
    int ans=0,cnt=0;
    bool flag=false;
    for(int i=1;i<=d;i++){
        string s;
        cin>>s;
//        bool f=false;
        int c=s.find(ss);
        if(c!=string::npos){
            cnt++;
//            if(flag==false) ans=max(ans,cnt);
//            flag=false;
        }
        else{
            cnt=0;
//            flag=true;
        }
        ans=max(ans,cnt);

    }
    printf("%d\n",ans);
    return 0;
}
/*

*/
