                 // rotate algorithm example
#include <bits/stdc++.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::rotate
#include <vector>       // std::vector

int main () {
    int n,d;
   std::cin>>d;
  std::vector<int> myvector;

  // set some values:
  for (int i=0; i<d; ++i){
        std::cin>>n;

    myvector.push_back(n); // 1 2 3 4 5 6 7 8 9
  }

  std::rotate(myvector.begin(),myvector.begin()+3,myvector.end());
                                                  // 4 5 6 7 8 9 1 2 3
  // print out content:
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}


