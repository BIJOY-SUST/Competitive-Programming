#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--)
    {
        long long x;
        cin >> x;
        long long  num = sqrt(x);
        int i;
        for (i = 2;i * i<= num; i++)
        {
            if (num % i == 0)
            {
                break;
            }
        }
        if (num * num == x && i * i > num && x > 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
