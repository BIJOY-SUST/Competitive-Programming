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
int a[110][110];
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int h,w;
    scanf("%d %d",&h,&w);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int top=0,bot=0,left=0,right=0,fro=0,bac=0;
    bot=top=w*h;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(j==0){
                left+=a[i][j];
            }
            else if(a[i][j-1]<a[i][j]){
                left+=a[i][j]-a[i][j-1];
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=w-1;j>=0;j--){
            if(j==w-1){
                right+=a[i][j];
            }
            else if(a[i][j+1]<a[i][j]){
                right+=a[i][j]-a[i][j+1];
            }
        }
    }

    for(int j=0;j<w;j++){
        for(int i=h-1;i>=0;i--){
            if(i==h-1){
                fro+=a[i][j];
            }
            else if(a[i+1][j]<a[i][j]){
                fro+=a[i][j]-a[i+1][j];
            }
        }
    }
    for(int j=0;j<w;j++){
        for(int i=0;i<h;i++){
            if(i==0){
                bac+=a[i][j];
            }
            else if(a[i-1][j]<a[i][j]){
                bac+=a[i][j]-a[i-1][j];
            }
        }
    }
    int ans=left+right+fro+bac+top+bot;
    printf("%d\n",ans);
    return 0;
}
/*

*/
