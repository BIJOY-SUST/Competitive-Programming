#include<bits/stdc++.h>
using namespace std;
int ar[5005];
int par(int z){
    if(ar[z]==z) return z;
    else return par(ar[z]);
}
int  main(){
    int i, n, m;
    string s, ss, sss;
    while(scanf("%d%d", &n, &m)){
        if(n==0&&m==0) break;
        map<string, int>mp;
        map<int, int>mpp;
        int ans=0;
        for(i=1; i<=n; i++){
            cin>>s;
            mp[s]=i;
            ar[i]=i;
        }
        for(i=0; i<m; i++){
            cin>>ss>>sss;
            ar[par(mp[ss])]=par(mp[sss]);
        }
        for(i=1; i<=n; i++){
            ar[i]=par(i);
            mpp[ar[i]]++;
            ans=max(ans, mpp[ar[i]]);
        }
        cout<<ans<<endl;
        scanf("\n");
    }
    return 0;
}
