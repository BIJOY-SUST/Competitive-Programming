#include<bits/stdc++.h>
#define mx             2010
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
//#define pp             pair<int,int>
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//int biton(int p,int pos){return p=p|(1<<pos);}
//int bitoff(int p,int pos){return p=p&~(1<<pos);}
//bool bitcheck(int p,int pos){return (bool)(p&(1<<pos));}
//ll POW(ll b,ll p) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
//ll BigMod(ll b,ll p,ll Mod) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
//ll ModInverse(ll p,ll Mod) {return BigMod(p,Mod-2,Mod);}
using namespace std;
char ss[mx][mx];
int arr[mx],str[mx][mx];
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        mem(str,0);
        int r,c;
        scanf("%d%d",&r,&c);
        for(int i=0;i<r;i++) scanf("%s",&ss[i]);
        for(int j=0;j<c;j++){
            if(ss[0][j]=='0') str[0][j]=1;
            else str[0][j]=0;
        }
        for(int i=1;i<r;i++){
            for(int j=0;j<c;j++){
                if(ss[i][j]=='0'){
                    str[i][j]=str[i-1][j]+1;
                }
                else{
                    str[i][j]=0;
                }
            }
        }
        stack<int>st;
        st.push(0);
        int ans=0;
        for(int k=0;k<r;k++){
            mem(arr,0);
            int top,i=0,sum=0,max_area=0;
            for(int j=0;j<c;j++){
                arr[j]=str[k][j];
            }
            for(i=0;i<c;){
                if(st.empty()||arr[st.top()]<=arr[i]) st.push(i++);
                else{
                    top=st.top();
                    st.pop();
                    if(st.empty()){
    //                    cout<<"BIJOY"<<endl;
                        sum=arr[top]*i;
                    }
                    else{
    //                    cout<<"JOY"<<endl;
                        sum=arr[top]*(i-st.top()-1);
                    }
    //                cout<<st.size()<<" "<<top<<" "<<i<<" "<<sum<<endl;
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
            ans=max(ans,max_area);
        }
        printf("Case %d: %d\n",cs,ans);
    }
    return 0;
}
/**
Input:
3
5 7
0110110
0000010
1000001
0100001
1100010
3 3
001
100
101
7 9
000101010
000100000
000100000
000000011
000000011
111000101
110101001
Output:

**/

