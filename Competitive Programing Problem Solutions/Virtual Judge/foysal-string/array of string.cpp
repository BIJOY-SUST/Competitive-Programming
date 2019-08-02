#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Declaring Vector of String type
    vector <string> colour;

    // Initialize vector with strings using push_back
    // command
    colour.push_back("Blue");
    colour.push_back("Red");
    colour.push_back("Orange");
    colour.push_back("Yellow");

    // Print Strings stored in Vector
    for (int i=0; i<colour.size(); i++)
        cout << colour[i] << "\n";
}


/*// C++ program to demonstrate array of strings using
// array of strings.
#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Initialize String Array
    string colour[4] = {"Blue", "Red", "Orange", "Yellow"};

    // Print Strings
    for (int i = 0; i < 4; i++)
        cout << colour[i] << "\n";
}*/
