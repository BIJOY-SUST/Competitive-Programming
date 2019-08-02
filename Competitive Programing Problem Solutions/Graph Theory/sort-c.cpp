#include<bits/stdc++.h>
using namespace std;

class data{
public:
    string name;
    int height,weight;
    long long int income;
};
bool compare(data a, data b){
    if(a.income==b.income){
        if(a.height==b.height){
            if(a.weight==b.weight){
                return a.name<b.name;
            }
            else{
                return a.weight<b.weight;
            }
        }
        else{
            return a.height>b.height;
        }
    }
    else{
        return a.income>b.income;
    }
}
int main(){
    int n;
    cin>>n;
    data v[n];
    for(int i=0;i<n;i++){
        cin>>v[i].name>>v[i].income>>v[i].height>>v[i].weight;
    }
    sort(v,v+n, compare);
    for(int i=0;i<n;i++){
        cout<<v[i].name<<" "<<v[i].income<<" "<<v[i].height<<" "<<v[i].weight<<endl;
    }
    return 0;
}

