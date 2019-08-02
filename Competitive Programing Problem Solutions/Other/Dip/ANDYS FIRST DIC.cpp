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
    string s;
    set<string>v;
    while(cin>>s){
        transform(s.begin(),s.end(),s.begin(),::tolower);
        string ss;
        bool let=false;
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i])){
                ss+=s[i];
                let=true;
            }
            else if(let){
                v.insert(ss);
                ss.clear();
                let=false;
            }
        }
        if(!ss.empty()) v.insert(ss);
        s.clear();
        ss.clear();
    }
    for(__typeof(v.begin()) it=v.begin();it!=v.end();it++){
        cout<<*it<<'\n';
    }
    return 0;
}
