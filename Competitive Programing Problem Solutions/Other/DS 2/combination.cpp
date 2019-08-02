#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >v;
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(b,a));
    }
    sort(v.rbegin(),v.rend());
    int k=1,ans=0;
    for(int i=0;i<v.size();i++){
        if(k==0) break;
        ans+=v[i].second;
        k+=v[i].first;
        k--;
    }
    printf("%d\n",ans);
    return 0;
}
