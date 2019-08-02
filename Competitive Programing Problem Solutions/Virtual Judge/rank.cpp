#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

vector<pair<int,int> >v;
int main(){

    int n,x,y,k,c=0;
    cin>>n>>k;
    for(int i = 0;i<n;i++){
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    int x1 = v[k].first,y1 = v[k].second;
    for(int j=0;j<n;j++){
        int x2 = v[j].first,y2 = v[j].second;
        if(x1==x2&&y1==y2){
            c++;
        }
    }
    cout<<c<<endl;
    return 0;
}
