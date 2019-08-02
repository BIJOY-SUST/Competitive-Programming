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
map<int,bool>flag;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,h=1;
    cin>>n;
    vector<int>v,v1,v2,v3;
    //vector<int>v1;
    //vector<int>v2;
    //vector<int>v3;
    vector<int>::iterator it,a,b,c;
    //vector<int>::iterator a;//,a,b,c;
    //vector<int>::iterator b;//,a,b,c;
    //vector<int>::iterator c;//,a,b,c;

    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        v.push_back(k);
    }
    it=v.begin();
    while(it!=v.end()){
        if(*it==1){
            v1.push_back(h);
        }
        if(*it==2){
            v2.push_back(h);
        }
        if(*it==3){
            v3.push_back(h);
        }
        it++;
        h++;
    }
    int t=min(min(v1.size(),v2.size()),v3.size());
    cout<<t<<"\n";
    a=v1.begin();
    b=v2.begin();
    c=v3.begin();
    while(t--){
        cout<<*a<<" "<<*b<<" "<<*c<<"\n";
        a++,b++,c++;
    }
    return 0;
}


