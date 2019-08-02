#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    while(cin>>N){
        getchar();
        if(N==0){
            break;
        }
        priority_queue<int>v;
        for(int i=0;i<N;i++){
            int n;
            cin>>n;
            v.push(-n);
        }
        int k,sum=0;
        for(int i=1;i<N;i++){
            int a=v.top();v.pop();
            int b=v.top();v.pop();
            k = -(a+b);
            sum+=k;
            v.push(-k);
        }
        cout<<sum<<endl;
    }
    return 0;
}
