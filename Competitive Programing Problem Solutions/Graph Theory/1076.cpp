#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001];
bool BISECTION_RULE(int p){
    int c=1,d=0;
    for(int i=0;i<n;i++){
        d+=a[i];
        if(d>p){
            d=a[i];
            c++;
        }
    }
    if(c<=m) return true;
    else return false;
}
int main(){
    int T;
    cin>>T;
    getchar();
    for(int k=1;k<=T;k++){
        int l=1,h=0,mid,s;
        cin>>n>>m;
        int t_max=0,sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            t_max=max(a[i],t_max);
            h+=a[i];
        }
        while(l<=h){
            mid=(l+h)/2;
            if(BISECTION_RULE(mid)){
                s=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        t_max = max(t_max,s);
        cout<<"Case "<<k<<":"<<" "<<t_max<<endl;
    }
    return 0;
}
