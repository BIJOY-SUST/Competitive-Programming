#include<bits/stdc++.h>
using namespace std;
int main(){
    int myints[] = {10,2,5,4,3,8,6,7};
  vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30
  ///vector<int>::iterator low,up;
  vector<int>::iterator low,up;

  low=lower_bound(v.begin(), v.end(), 10); //          ^
  up= upper_bound(v.begin(), v.end(), 10); //                   ^
  cout<<*low<<endl;
  cout<<*up<<endl;
  //cout<<up<<endl;
  cout << "lower_bound at position " << (low- v.begin()) << '\n';
  cout << "upper_bound at position " << (up - v.begin()) << '\n';
    return 0;

}
