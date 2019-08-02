#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,d,m;
    std::cin>>n>>d;
    std::vector<int>v;
    for(int i=0;i<n;i++){
        std::cin>>m;
        v.push_back(m);
    }
    std::rotate(v.begin(),v.begin()+d,v.end());
    for(std::vector<int>::iterator it=v.begin(); it!=v.end();it++){
        std::cout<<*it<<" ";
    }
    return 0;
}
