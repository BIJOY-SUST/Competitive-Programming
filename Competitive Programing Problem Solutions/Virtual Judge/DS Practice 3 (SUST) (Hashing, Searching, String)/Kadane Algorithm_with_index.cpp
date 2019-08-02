/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
///Kadane’s Algorithm:
#include<bits/stdc++.h>
//#define pi             3.141592653589793238462643383
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define ll             long long int
//#define llu            unsigned long long int
//#define mx             1000001
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
//int biton(int N,int pos){return N=N(1<<pos);}
//int bitoff(int N,int pos){return N=N&~(1<<pos);}
//bool check(int N,int pos){return (bool)(N&(1<<pos));}
/*---------------------------------------------------*/
using namespace std;
int arr[10001];
int Start,End,t;
int maxSubArraySum(int n){
    int max_sum=INT_MIN,max_end=0;
    Start=0,End=0,t=0;
    for(int i=0;i<n;i++){
        max_end = max_end+arr[i];
        if(max_sum<max_end){
            max_sum = max_end;
            Start=t;
            End=i;
        }
        if(max_end<0){
            max_end=0;
            t=i+1;
        }
//        else if(max_sum<max_end) max_sum = max_end;
    }
    return max_sum;
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    int ans=maxSubArraySum(n);
    printf("Sum : %d\n",ans);
    printf("Start : %d\nEnd : %d\n",Start,End);
    return 0;
}

