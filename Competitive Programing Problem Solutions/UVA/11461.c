#include <iostream>
#include <cmath>
using namespace std;
int a[1000100];
void isans()
{
    for (int i = 1; i <= 1000000; i++)  a[i] = 1;
    a[1] = 0;
    for (int i = 2; i <= 1000000; i++)
    {
        if ((long long)i * i <= 1000000 && a[i])
        {
            for (int j = i * i; j <= 1000000; j += i)
            {
                    a[j] = 0;
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    isans();
    while(n--)
    {
        long long x;
        cin >> x;
        long long num = sqrt(x);
        if (num * num == x && a[num])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
