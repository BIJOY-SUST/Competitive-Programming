#include<bits/stdc++.h>
using namespace std;
vector<int>v;
void mmm(int n){
    int i=0;
    while(n){
        if(n&1){
            v.push_back(i);
        }
        n=n>>1;
        i++;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        mmm(n);
        int k=v.size();
//        sort(v.rbegin(),v.rend());
        printf("2^%d",v[k-1]);
        for(int i=v.size()-2;i>=0;i--){
            printf(" + 2^%d",v[i]);
        }
        printf("\n");
        v.clear();
    }
    return 0;
}

