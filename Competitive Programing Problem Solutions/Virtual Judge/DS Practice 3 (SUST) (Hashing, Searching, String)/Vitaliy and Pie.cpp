/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
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
map<char,int>v;
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    string s;
    cin>>s;
//    for(int i=0;i<s.length();i++){
//        ss[i+1]=s[i];
//    }
    int ans=0;
    for(int i=0;i<s.length();i++){
        if(i%2==0) v[toupper(s[i])]++;
        else{
            if(v[s[i]]!=0){
                //cout<<s[i]<<"mill ase"<<endl;
                v[s[i]]--;
                //continue;
            }
            else ans++;
        }

    }
//    for(int i=0;i<v.size();i++){
//        cout<<v[i]<<endl;
//    }
    printf("%d\n",ans);
    return 0;
}
