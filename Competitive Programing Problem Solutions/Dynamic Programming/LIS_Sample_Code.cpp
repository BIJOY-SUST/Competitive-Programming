/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
///Longest Increasing Subsequence
///An O(n2) approach
#include<bits/stdc++.h>
//#define pi             3.14159265358979323846264338328
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define ll             long long int
//#define llu            unsigned long long int
#define mx             1001
//#define mod            100000007
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
using namespace std;
int m_pos,n,arr[mx],dp[mx],sequence[mx];
int LIS(){
    for(int i=0;i<mx;i++) dp[i]=1;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)
        if(arr[j]>arr[i]&&dp[j]<dp[i]+1) dp[j]=dp[i]+1;
    int ans=0;
    for(int i=0;i<n;i++) if(ans<dp[i]){ans=dp[i];m_pos=i;}
    return ans;
}
void lis_print(int M){
    int top=M-1;
    sequence[top]=arr[m_pos];top--;
    for(int i=m_pos-1;i>=0;i--) if(arr[i]<arr[m_pos]&&dp[i]==dp[m_pos]-1){
        m_pos=i;sequence[top]=arr[m_pos];top--;
    }
    printf("LIS is :");
    for(int i=0;i<M;i++) printf(" %d",sequence[i]);
    printf("\n");
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    int ans=LIS();
    printf("The LIS length is %d\n",ans);
    lis_print(ans);
    return 0;
}
