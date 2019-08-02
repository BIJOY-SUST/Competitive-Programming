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
    int k=0;
    char s[100000],ss[100000];
    cin>>s;
    int len = strlen(s);
    //s[0]=toupper(s[0]);
    bool flag = true;
    //ss[k++] = toupper(s[0]);
    for(int i=0;i<len;i++){
        if(i==0&&isupper(s[i])){
            ss[k++]=tolower(s[i]);
        }
        else if(i==0&&islower(s[i])){
            ss[k++]=toupper(s[i]);
        }
        else if(isupper(s[i])){
            ss[k++]=tolower(s[i]);
        }
        else{
            flag = false;
            break;
        }
    }
    ss[k]='\0';
    if(flag==true)cout<<ss<<endl;
    else cout<<s<<endl;
    return 0;
}
