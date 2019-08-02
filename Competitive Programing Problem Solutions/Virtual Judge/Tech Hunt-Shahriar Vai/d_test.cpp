#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define mx             10055
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define p              pair<int,int>
//#define ll             long long int
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
using namespace std;
//vector<pair<char,char> >v;
char parent[1000];
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        string s1;
//        v.clear();
        s1.clear();
        cin>>s1;
        for(char ch='A';ch<='Z';ch++){
            parent[ch]=ch;
        }
        char cc='_';
        parent[cc]=cc;
        int r;
        scanf("%d",&r);
        for(int j=1;j<=r;j++){
            char ch1,ch2;
            cin>>ch1>>ch2;
            for(char ch='A';ch<='Z';ch++){
                if(parent[ch]==ch2){
                    parent[ch]=ch1;
                }
            }
//            cout<<s1<<endl;
        }
        for(int i=0;i<s1.length();i++){
            cout<<parent[s1[i]];
        }
        cout<<'\n';
    }
    return 0;
}
/*

*/

