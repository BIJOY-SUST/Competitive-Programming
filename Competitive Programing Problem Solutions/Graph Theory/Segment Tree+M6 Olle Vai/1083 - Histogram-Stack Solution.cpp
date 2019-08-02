#include<bits/stdc++.h>
#define mx             100010
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
//#define pp             pair<int,int>
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//int biton(int p,int pos){return p=p|(1<<pos);}
//int bitoff(int p,int pos){return p=p&~(1<<pos);}
//bool bitcheck(int p,int pos){return (bool)(p&(1<<pos));}
//ll POW(ll b,ll p) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
//ll BigMod(ll b,ll p,ll Mod) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
//ll ModInverse(ll p,ll Mod) {return BigMod(p,Mod-2,Mod);}
using namespace std;
int arr[mx];
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);
        int top,i=0,sum=0,max_area=0;
        stack<int>st;
        st.push(0);
        for(i=0;i<n;){
            if(st.empty()||arr[st.top()]<=arr[i]) st.push(i++);
            else{
                top=st.top();
                st.pop();
                if(st.empty()){
                    sum=arr[top]*i;
                }
                else{
                    sum=arr[top]*(i-st.top()-1);
                }
                max_area=max(sum,max_area);
            }
        }
        while(!st.empty()){
            top=st.top();
            st.pop();
            if(st.empty()) sum=arr[top]*i;
            else sum=arr[top]*(i-st.top()-1);
            max_area=max(sum,max_area);
        }
        printf("Case %d: %d\n",cs,max_area);
    }
    return 0;
}
/**
Input:
2

7

2 1 4 5 1 3 3

5

4 4 3 2 4
Output:
Case 1: 8

Case 2: 10
**/
