#include <bits/stdc++.h>
using namespace std;
int mx=1e5+5;
// (X[i], Y[i]) are coordinates of i'th point.
double polygonArea(double X[], double Y[], int n)
{
    // Initialze area
    double area = 0.0;

    // Calculate value of shoelace formula
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        area += (X[j] + X[i]) * (Y[j] - Y[i]);
        j = i;  // j is previous vertex to i
    }

    // Return absolute value
    return abs(area / 2.0);
}

// Driver program to test above function
int main()
{
        freopen("area.in","r",stdin);
    freopen("area.out","w",stdout);
//    ios_base::sync_with_stdio(false),cin.tie(NULL);

    int n;
    scanf("%d",&n);
    double X[mx],Y[mx];
    for(int i=0;i<n;i++){
        scanf("%lf%lf",&X[i],&Y[i]);
    }

    printf("%.10f\n",polygonArea(X, Y, n));
}

