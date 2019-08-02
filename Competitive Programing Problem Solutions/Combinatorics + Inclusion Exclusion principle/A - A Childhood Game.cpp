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

int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int n;
        string s;
        cin>>n>>s;
        if(s=="Alice"){
            if(n%3==1)
                printf("Case %d: Bob\n",cs);
            else if(n%3==2)
                printf("Case %d: Alice\n",cs);
            else if(n%3==0)
                printf("Case %d: Alice\n",cs);
        }
        else{
            if(n%3==1)
                printf("Case %d: Bob\n",cs);
            else if(n%3==2)
                printf("Case %d: Bob\n",cs);
            else if(n%3==0)
                printf("Case %d: Alice\n",cs);
        }
    }
    return 0;
}
/*
Sample Input
3
1 Alice
2 Alice
3 Bob
Sample Output
Case 1: Bob
Case 2: Alice
Case 3: Alice
*/
