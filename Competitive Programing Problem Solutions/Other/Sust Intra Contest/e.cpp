#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int e=0,e_i=0,o=0,o_i=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x%2==1){
            o++;
            o_i=i;
        }
        else{
            e++;
            e_i=i;
        }

    }
    o<e?cout<<o_i+1<<"\n":cout<<e_i+1<<"\n";
    return 0;
}
