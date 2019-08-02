#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<pair<int,int> >v;

int main(){
    int n,k,x,y;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int x1 = v[k-1].first,y1 = v[k-1].second;
    int c = 0;
    for(int i=0;i<n;i++){
        int x2 = v[i].first, y2 = v[i].second;
        if(x1 == x2 && y1 == y2){
            c++;
        }
    }
    cout<<c;

    return 0;
}
