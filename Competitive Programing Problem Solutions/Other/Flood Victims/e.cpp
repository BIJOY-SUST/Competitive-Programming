#include<bits/stdc++.h>
using namespace std;
int rec(int n){

}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n,ans=0;
        scanf("%d",&n);
        if(n==1||n==3) ans=1;
        else if(n==2) ans=2;
        else{

            //s:
            int k=1;
            //ans++;
            //n=n-1;
            while(k<=n){
                n=n-k;
                k*=2;
//                cout<<n<<" "<<k<<endl;
                if(n==k){
                    ans++;
                    break;
                }
//                n=n-k;
                else if(n>k) continue;
                else if(n<k){
                    ans++;
                    if(n==1||n==3){
                        ans+=1;
                        break;
                    }
                    else if(n==2){
                        ans+=2;
                        break;
                    }
                    else{
//                        ans++;
                        k=1;
//                        n+=k;
                    }
                }
            }
        }
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}
