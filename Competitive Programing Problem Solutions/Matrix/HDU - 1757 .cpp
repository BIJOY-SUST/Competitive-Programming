#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

#define pf              printf
#define sf              scanf
///code start here
int mod;
struct mat{
    int v[15][15];
};
mat zero,I;

mat M_mul(mat &a,mat &b,int n){
    mat sol=zero;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sol.v[i][j]=0;
            for(int k=1;k<=n;k++){
        sol.v[i][j]+=(a.v[i][k]*b.v[k][j])%mod;
        sol.v[i][j]%=mod;
            }
        }

    }
    return sol;
}

mat big_mod(mat tem,int p,int n){
    mat x=I,y=tem;
    while(p){
        if(p&1) x=M_mul(x,y,n);
        y=M_mul(y,y,n);
        p>>=1;
    }
    return x;
}

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    for(int i=0;i<=10;i++)
        for(int j=0;j<=10;j++)
            zero.v[i][j]=0;

    I=zero;
    for(int i=0;i<=10;i++) I.v[i][i]=1;
    int k,m;
    while(sf("%d%d",&k,&m)!=EOF){
        mat org=zero;mod=m;
        for(int i=1;i<=10;i++){
            sf("%d",&org.v[1][i]);
        }
        for(int i=2;i<=10;i++) org.v[i][i-1]=1;
        int sum;
        if(k<10){
            sum=k%mod;
        }
        else{
            mat ans=big_mod(org,k-9,10);
            sum=0;
            for(int i=1;i<=10;i++){
                sum=(sum+(ans.v[1][i]*(10-i))%mod)%mod;
            }
        }
        pf("%d\n",sum);
    }
    return 0;
}
/*

*/


