#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    while(cin>>N){
        //getchar();
        if(N==0){
            break;
        }
        priority_queue<int,vector<int>,greater<int> >v;
        for(int i=0;i<N;i++){
            int n;
            cin>>n;
            v.push(n);
        }
        int k,sum=0;
        for(int i=1;i<N;i++){
            int a=v.top();v.pop();
            int b=v.top();v.pop();
            k = (a+b);
            sum+=k;
            v.push(k);
        }
        cout<<sum<<'\n';
    }
    return 0;
}
