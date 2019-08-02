/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
#include<bits/stdc++.h>
//#define pi             3.141592653589793238462643383
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define p              pair<int,int>
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
vector<pair<char,int> >pp;
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char ch;
        int x;
        scanf("%c %d",&ch,&x);
        pp.push_back(make_pair(ch,x));
    }
    int c=0;
    for(int i=0;i<n;i++){
        if(c>5){
            c=0;
            break;
        }
        if(pp[i].first=='&'){
            if(1&pp[i].second==pp[i].second){
                c++;
            }
            else break;
        }
        else if(pp[i].first=='|'){
            if(1|pp[i].second==pp[i].second){
                c++;
            }
            else break;
        }
        else if(pp[i].first=='^'){
            if(1^pp[i].second==pp[i].second){
                c++;
            }
            else break;
        }
    }
    printf("%d\n",c);
    for(int i=0;i<c;i++){
        printf("%c %d\n",pp[i].first,pp[i].second);
    }
    return 0;
}
