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
vector<int>v1,v2;
vector<int>dd;
bool flag[101];
int n,q;
int d=0;
int ans2=0;
void back_t(int c,int sum){
    if(sum>ans2&&sum<=n){
        if(sum>ans2&&sum<=n){
            ans2=sum;
            dd.clear();
            for(int i=0;i<v2.size();i++){
                dd.push_back(v2[i]);
            }
        }
    }
        for(int i=c;i<q;i++){
            if(!flag[i]&&sum+v1[i]<=n){
                flag[i]=true;
                v2.push_back(v1[i]);
                back_t(i,sum+v1[i]);
                flag[i]=false;
                v2.pop_back();
            }
        }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    while(scanf("%d %d",&n,&q)!=EOF){
        for(int i=0;i<q;i++){
            int k;scanf("%d",&k);
            v1.push_back(k);
        }
        back_t(0,0);
        for(int i=0;i<dd.size();i++){
            printf("%d ",dd[i]);
        }
        printf("sum:%d\n",ans2);
        v1.clear();
        v2.clear();
        dd.clear();
        memset(flag,false,sizeof(flag));
        ans2=0;
    }
    return 0;
}
/*

*/
