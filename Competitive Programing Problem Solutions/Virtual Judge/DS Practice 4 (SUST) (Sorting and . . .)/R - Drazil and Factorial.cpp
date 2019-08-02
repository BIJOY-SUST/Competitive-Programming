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
vector<int>v;
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        int h=(s[i]-'0');
        if(h==9){
            v.push_back(3);
            v.push_back(3);
            v.push_back(2);
//            v.push_back(2);
//            v.push_back(2);
            v.push_back(7);
        }
        else if(h==8){
            v.push_back(2);
            v.push_back(2);
            v.push_back(2);
            v.push_back(7);
        }
        else if(h==6){
            //v.push_back(2);
            v.push_back(3);
            v.push_back(5);
        }
        else if(h==4){
            v.push_back(2);
            v.push_back(2);
            v.push_back(3);
        }
        else if(h>=2){
            v.push_back(h);
        }
    }
    sort(v.rbegin(),v.rend());
    for(int i=0;i<v.size();i++){
        printf("%d",v[i]);
    }
    printf("\n");
    return 0;
}
//Input
//10
///1413472614
//Output
///753333222222222
//Answer
///75333332222222
