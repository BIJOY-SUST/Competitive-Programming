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
vector<int>arr;
bool flag[11];
bool f1=false;
void back_t(int u,int value,int c){
    if(value==23&&c==5){
        f1=true;
        return;
    }
    for(int i=0;i<5;i++){
        if(!flag[i]){
            flag[i]=true;
            back_t(i,value+arr[i],c+1);
            back_t(i,value-arr[i],c+1);
            back_t(i,value*arr[i],c+1);
            flag[i]=false;
        }
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    while(1){
        for(int i=0;i<5;i++){
            int k;scanf("%d",&k);
            arr.push_back(k);
        }
        if(arr[0]==0&&arr[1]==0&&arr[2]==0&&arr[3]==0&&arr[4]==0) break;
        sort(arr.rbegin(),arr.rend());
        for(int i=0;i<5;i++){
            flag[i]=true;
            back_t(i,arr[i],1);
            flag[i]=false;
            if(f1) break;
        }
        if(f1) printf("Possible\n");
        else printf("Impossible\n");
        arr.clear();
        f1=false;
        memset(flag,false,sizeof(flag));
    }
    return 0;
}
/*

*/
