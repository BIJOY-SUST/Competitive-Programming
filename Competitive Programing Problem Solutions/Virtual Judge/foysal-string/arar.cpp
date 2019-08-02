#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Declaring Vector of String type
    vector <string> colour;

    // Initialize vector with strings using push_back
    // command
    string s;
    for(int i=0;i<4;i++){
        cin>>s;
        colour.push_back(s);
    }

    // Print Strings stored in Vector
    for (int i=0; i<colour.size(); i++){
        cout << colour[i] << "\n";
    }

    return 0;
}

