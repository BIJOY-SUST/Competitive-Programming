#include<bits/stdc++.h>
using namespace std;
double s = 0;
class data{
public:
    string name;
    int id;
    double cgpa;
};
bool compare(data a, data b){

        return a.cgpa>b.cgpa;
}
int main(){
    int n;
    cin>>n;
    data v[n];
    for(int i=0;i<n;i++){
        cin>>v[i].name>>v[i].id>>v[i].cgpa;
    }
    for(int i=0;i<n;i++){
        s+=v[i].cgpa;
    }
    s = s/n;
    cout<<"Average CPA : "<<s<<endl;
    sort(v,v+n, compare);
    for(int i=0;i<n;i++){
        cout<<v[i].name<<" "<<v[i].id<<" "<<v[i].cgpa<<endl;
    }
    return 0;
}



