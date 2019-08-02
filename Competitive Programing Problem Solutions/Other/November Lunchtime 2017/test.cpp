#include<bits/stdc++.h>
using namespace std;
void reset(long long arr[], int n)
{
    for(int i = 0; i < n; i++)
        arr[i] = 1;
}
int main()
{
    int n, q, t;
    long long x;
    cin >> t;
    while(t--) {
        cin >> n >> q;
        long long d[n + 3], r, mul = 1;
        reset(d, n);
        int k = 0;
        for(int i = 0, j = 0; i < n; i++) {
            cin >> x;
            if(mul <= 1000000005)
                mul *= x;

        }
        for(int i = 0; i < q; i++) {
            cin >> r;
            r /= mul;
            cout << r;
            if(i != q - 1)
                cout << " ";
        }
        cout << "\n";
    }
    return 0;
}


