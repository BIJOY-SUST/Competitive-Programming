#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

vector<pair<int,int> >v;
bool a[10001] = {};

int main(){

    int n,x0,y0,x,y;
    cin>>n>>x0>>y0;
    for(int i = 0;i<n;i++){
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    int min_s = 0;
    for(int i=0;i<n;i++){
        int x1 = v[i].first,y1 = v[i].second;
        if(a[i]==false){
            min_s++;
        }
        for(int j=i+1;j<n;j++){
            int x2 = v[j].first,y2 = v[j].second;
            if(a[j]==false && (y1-y0)*(x2-x0) == (x1-x0)*(y2-y0)){
                a[j]=true;
            }
        }
    }
    cout<<min_s<<endl;
    return 0;
}
