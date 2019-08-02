/*
BIJOY
CSE-25th Batch
Shahjalal University of Science and Technology
*/
///Longest Increasing Subsequence
///An O(nlogk) Approach
#include<bits/stdc++.h>
//#define pi             3.14159265358979323846264338328
//#define pi             2*acos(0.0)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define ll             long long int
//#define llu            unsigned long long int
#define mx             10001
//#define mod            100000007
const long long inf =  1e10;
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
using namespace std;
int m_pos,n,arr[mx],dp[mx],I[mx],sequence[mx];
int LIS(){
    I[0]=-inf;
    for(int i=1;i<=n;i++) I[i]=inf;
    int lis_len=0;
    for(int i=0;i<n;i++){
        int low=0,high=lis_len,mid;
        while(low<=high){
            mid=(low+high)/2;
            if(I[mid]<arr[i]) low=mid+1;
            else high=mid-1;
        }
        I[low]=arr[i];
        dp[i]=low;
        if(lis_len<low){lis_len=low;m_pos=i;}
    }
    return lis_len;
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
    //lis_print(ans);
    return 0;
}
