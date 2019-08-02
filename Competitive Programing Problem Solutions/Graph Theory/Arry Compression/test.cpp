#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<string> vec;
    vector<string>::iterator it;
    vec.push_back("H");
    vec.push_back("i");
    vec.push_back("g");
    vec.push_back("h");
    vec.push_back("l");
    vec.push_back("a");
    vec.push_back("n");
    vec.push_back("d");
    vec.push_back("e");
    vec.push_back("r");

    it=find(vec.begin(),vec.end(),"a");
    //it++;
    int pos = distance(vec.begin(), it);

    if(it!=vec.end()){
        cout<<"FOUND  "<< *it<<"  at position: "<<pos<<endl;
    }
    else{
        cout<<"NOT FOUND"<<endl;
    }
    return 0;
}

