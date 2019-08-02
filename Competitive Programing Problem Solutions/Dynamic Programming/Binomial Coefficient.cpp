/*______________________________________________
 !                   BIJOY                      !
 !               CSE-25th Batch                 !
 !Shahjalal University of Science and Technology!
 !______________________________________________!
*/
#include<bits/stdc++.h>
//#define pi             3.14159265358979323846264338328
//#define pi             acos(-1)
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mx             10001
#define mod            1000000007
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
using namespace std;
int dp[mx][mx];
int sieve(int n,int r){
    if(r==0||r==n) return 1;
    if(dp[n][r]!=-1) return dp[n][r];
    else{
        dp[n][r]=sieve(n-1,r-1)+sieve(n-1,r);
        return dp[n][r];
    }
}
int main(){
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        int n,r;
        scanf("%d %d",&n,&r);
        memset(dp,-1,sizeof(dp));
        int ans=sieve(n-1,r);
        printf("Case %d: %d\n",tc,2*ans);
    }
    return 0;
}

//Auxiliary Space: O(k) is here.....
//http://www.geeksforgeeks.org/dynamic-programming-set-9-binomial-coefficient/










/*
#include<bits/stdc++.h>
using namespace std;

int binomialCoeff(int n, int k){
    int C[k+1];
    memset(C, 0, sizeof(C));

    C[0] = 1;  // nC0 is 1

    for (int i = 1; i <= n; i++)
    {
        // Compute next row of pascal triangle using
        // the previous row
        for (int j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j-1];
    }
    return C[k];
}
int main(){
    int n = 5, k = 2;
    printf ("Value of C(%d, %d) is %d ",
            n, k, binomialCoeff(n, k) );
    return 0;
}
Run on IDE

Output:
Value of C[5][2] is 10
Time Complexity: O(n*k)
Auxiliary Space: O(k)
*/
