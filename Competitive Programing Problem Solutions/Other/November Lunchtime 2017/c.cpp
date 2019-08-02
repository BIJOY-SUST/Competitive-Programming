#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
//#define ll             long long int
//#define llu            unsigned long long int
#define mx             5000010
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
vector<int>v;
vector<int>v1,v2;
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int m,x,y;
        scanf("%d%d%d",&m,&x,&y);
        for(int i=1;i<=m;i++){
            v.push_back(i);
        }
        while(v.size()>2){
            for(int i=0;i<v.size();i++){
                if((i+1)%2) v1.push_back(v[i]);
                else v2.push_back(v[i]);
            }
            int d1=v1.size();
            int e1=(d1*x)/y;
            v1.erase(v1.begin()+e1);
            int d2=v2.size();
            int e2=(d2*x)/y;
            v2.erase(v2.begin()+e2);
            v.clear();
            for(int i=0;i<v1.size();i++) v.push_back(v1[i]);
            for(int i=0;i<v2.size();i++) v.push_back(v2[i]);
//            for(int i=0;i<v.size();i++){
//                printf("%d ",v[i]);
//            }
            v1.clear();
            v2.clear();
        }
//        printf("\n");
        int ans;
//        for(int i=0;i<v.size()-1;i++){
            ans=v[0]^v[1];
//        }
        printf("%d\n",ans);
        v.clear();
        v1.clear();
        v2.clear();
    }
    return 0;
}
/*

*/
