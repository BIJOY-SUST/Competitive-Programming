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
int arr[1009];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,ar[101];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    bool flag=true;
    bool c=true;
    bool k=true;
    for(int i=1;i<n;i++){
        if(flag==true&&ar[i-1]<ar[i]){
            continue;
        }
        else if(c==true&&ar[i]==ar[i-1]){
            flag=false;
        }
        else if(ar[i-1]>ar[i]){
            c=false;
            flag=false;
            //continue;
        }
        else{
            k=false;
            break;
        }
    }
    k==true?cout<<"YES\n":cout<<"NO"<<"\n";
    return 0;
}
