/*********** [ AkJn ] ***********/
#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define pb push_back
#define mp make_pair
#define ld long double
#define ll long long
#define fr(i,n) for(ll i=0; i<n; i++)
#define fre(i,n) for(ll i=1; i<=n; i++)

/* CHECK THESE POINTS BEFORE SUBMITTING
 * Read the question carefully.
 * Read the code once before final submission.
 * Check the extremities of the constraints.
 * 0 is better than -1.
*/

ll int gcd(ll int a, ll int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll int findGCD(ll int arr[], ll int n)
{
    ll int result = arr[0];
    for (ll int i = 1; i < n; i++)
        result = gcd(arr[i], result);

    return result;
}

#define MAX 15000001

// prime[] for storing smallest prime divisor of element
// count[] for storing the number of times a particular
// divisor occurs in a subsequence
ll int prime[MAX], countdiv[MAX];

// Simple sieve to find smallest prime factors of numbers
// smaller than MAX
void SieveOfEratosthenes()
{
    for (ll int i = 2; i * i < MAX; ++i)
    {
        if (!prime[i])
            for (ll int j = i * i; j < MAX; j += i)
                prime[j] = i;
    }

    // Prime number will have same divisor
    for (ll int i = 1; i < MAX; ++i)
        if (!prime[i])
            prime[i] = i;
}

// Returns length of the largest subsequence
// with GCD more than 1.
ll int largestGCDSubsequence(ll int arr[], ll int n)
{
    ll int ans = 0;
    for (ll int i=0; i < n; ++i)
    {
        ll int element = arr[i];

        // Fetch total unique prime divisor of element
        while (element > 1)
        {
            ll int div = prime[element];

            // Increment count[] of Every unique divisor
            // we get till now
            ++countdiv[div];

            // Find maximum frequency of divisor
            ans = max(ans, countdiv[div]);

            while (element % div==0)
                element /= div;
        }
    }

    return ans;
}

// Driver code
int main()
{
    fast
    SieveOfEratosthenes();
    ll int n, count=0;
    cin>>n;

    ll int a[n], gcdArr, ans;

    for (ll int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a,a+n);

    gcdArr = findGCD(a, n);

    for (ll int i = 0; i < n; ++i)
    {
        a[i] = a[i]/gcdArr;
    }

    ans = largestGCDSubsequence(a, n);
    if(ans==0){
      cout << "-1";
      return 0;
    }
    cout << n-ans;
    return 0;
}
