#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int T;
    double ab,ac,bc,r,ad;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>ab>>ac>>bc>>r;
        ad=double(ab*(sqrt(r/(r+1.0))));
        printf("Case %d: %f\n",i,ad);
    }
    return 0;
}
