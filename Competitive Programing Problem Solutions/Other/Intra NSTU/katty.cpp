#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        string s1,s2;
        int l1,l2,c=0,a1[26] = {0},a2[26] = {0};
        cin>>s1;
        cin>>s2;
        l1=s1.size();
        l2=s2.size();
        for(int i=0;i<l1;i++) a1[s1[i]-97]++;
        for(int i=0;i<l2;i++) a2[s2[i]-97]++;
        for(int i=0;i<26;i++) c+=abs(a1[i]-a2[i]);
        printf("Case %d: %d\n",i,c);
    }
    return 0;
}
