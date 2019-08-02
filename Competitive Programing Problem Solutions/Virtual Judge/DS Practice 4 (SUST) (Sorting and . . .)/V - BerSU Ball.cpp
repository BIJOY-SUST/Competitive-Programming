/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
#include<bits/stdc++.h>
//#define pi             3.141592653589793238462643383
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
//#define ll             long long int
//#define llu            unsigned long long int
//#define mx             100001
//#define mod            100000007
//const long long inf =  1e15;
/*----------------------Graph Moves------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
/*---------------------------------------------------*/
/*-----------------------Bitmask---------------------*/
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
/*---------------------------------------------------*/
using namespace std;
vector<int>v1,v2;
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int k;scanf("%d",&k);
        v1.push_back(k);
    }
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int k;scanf("%d",&k);
        v2.push_back(k);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int ans1=0;
    for(int i=0;i<v1.size();i++){
        for(int j=0;j<v2.size();j++){
            if(abs(v1[i]-v2[j])==1||abs(v1[i]-v2[j])==0){
                ans1++;
                v1.erase(v1.begin()+i);
                v2.erase(v2.begin()+j);
                i--;
                j--;
            }
        }
    }
    int ans2=0;
    for(int i=0;i<v2.size();i++){
        for(int j=0;j<v1.size();j++){
            if(abs(v1[j]-v2[i])==1||abs(v1[j]-v2[i])==0){
                ans2++;
                v1.erase(v1.begin()+j);
                v2.erase(v2.begin()+i);
                i--;
                j--;
            }
        }
    }
    printf("%d\n",max(ans1,ans2));
    return 0;
}
