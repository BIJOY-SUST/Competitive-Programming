///###################Summary of Solution######################
///Here is a quick summary of what I described above. We can find solution for Linear Diophantine Equation Ax+By=C in 3 steps:
///1.  No Solution
///    First check if solution exists for given equation. Let g=gcd(A,B). If g/|C then no solution exists.
///
///2.  Simplify Equation
///    Let a=Ag,b=Bg and c=Cg. Then finding solution for Ax+By=C is same as finding solution for ax+by=c.
///    In simplified equation, make sure GCD(a,b) is 1. If not, multiply −1 with a,b,c.
///
///3.  Extended Euclidean Algorithm
///    Use ext_gcd() to find solution (x1,y1) for ax+by=1.
///    Then multiply the solution with c to get solution for ax+by=c, where x=x1×c,y=y1×c.

#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
///    return b==0?a:gcd(b,a%b);
    return (a%b==0)?abs(b):gcd(b,a%b);
}
int ext_gcd ( int A, int B, int *X, int *Y ){
    int x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}
bool linearDiophantine ( int A, int B, int C, int *x, int *y ) {
    int g = gcd ( A, B );
    if ( C % g != 0 ) return false; //No Solution

    int a = A / g, b = B / g, c = C / g;
    ext_gcd( a, b, x, y ); //Solve ax + by = 1

    if ( g < 0 ) { //Make Sure gcd(a,b) = 1
        a *= -1; b *= -1; c *= -1;
    }

    *x *= c; *y *= c; //ax + by = c
    return true; //Solution Exists
}

int main () {
    int x, y, A = 3, B = 6, C = 9;
    bool res = linearDiophantine ( A, B, C, &x, &y );

    if ( res == false ) printf ( "No Solution\n" );
    else {
        printf ( "One Possible Solution (%d %d) \n", x, y );

        int g = gcd ( A, B );

        int k = 1; //Use different value of k to get different solutions
        printf ( "Another Possible Solution (%d %d)\n", x + k * ( B / g ), y - k * ( A / g ) );
    }

    return 0;
}
