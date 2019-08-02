#include<bits/stdc++.h>
using namespace std;
int main(){
  int num[] = {1,5,2,99,55,66,11,8};
  vector<int> v(num,num+8);           // 10 20 30 30 20 10 10 20
  sort (v.begin(), v.end());
  vector<int>::iterator low,up;
  low = lower_bound(v.begin(),v.end(),5);
  up = upper_bound(v.begin(),v.end(),5);
  cout<<low-v.begin()<<endl;
  cout<<up-v.begin()<<endl;

  return 0;
}
