#include<bits/stdc++.h>
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define p              pair<int,int>
//#define ll             long long int
//#define llu            unsigned long long int
//#define mx             10000010
//#define mod            100000007
//const long long inf =  1e15;
//----------------------Graph Moves--------------------
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//-----------------------------------------------------
//-----------------------Bitmask-----------------------
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool check(int n,int pos){return (bool)(n&(1<<pos));}
//-----------------------------------------------------
using namespace std;

int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    string a,b,c;
    cin>>a>>b>>c;
    stack<int>alice,bob,charlie;
    for(int i=a.length()-1;i>=0;i--){
        alice.push(a[i]);
    }
    for(int i=b.length()-1;i>=0;i--){
        bob.push(b[i]);
    }
    for(int i=c.length()-1;i>=0;i--){
        charlie.push(c[i]);
    }
    char ch='a';
    bool flag=true;
    while(flag){
        if(ch=='a'){
            if(alice.empty()){
                printf("A\n");
                flag=false;
                break;
            }
            ch=alice.top();
            alice.pop();
        }
        else if(ch=='b'){
            if(bob.empty()){
                printf("B\n");
                flag=false;
                break;
            }
            ch=bob.top();
            bob.pop();
        }
        else if(ch=='c'){
            if(charlie.empty()){
                printf("C\n");
                flag=false;
                break;
            }
            ch=charlie.top();
            charlie.pop();
        }
    }
    return 0;
}

