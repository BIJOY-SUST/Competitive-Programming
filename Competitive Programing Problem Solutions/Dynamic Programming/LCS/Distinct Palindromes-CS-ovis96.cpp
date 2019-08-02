#include "bits/stdc++.h"
using namespace std;
long long Mod = 1e9 + 7;
int dp[1002][1002][26];
char Str[1005];

int Find( int l , int r , int alpha ){
if( dp[l][r][alpha] != -1 )
  return dp[l][r][alpha];

if( l > r )
  return 0;
else if( l == r ){
  if( Str[l] == 'a' + alpha )
    return dp[l][r][alpha] = 1;
  else
    return dp[l][r][alpha] = 0;
}
else if( Str[l] != 'a' + alpha || Str[r] != 'a' + alpha )
  return dp[l][r][alpha] = ( 1LL * Find( l+1 , r , alpha ) + 1LL * Find( l , r-1 , alpha ) - 1LL * Find( l+1 , r-1 , alpha) ) % Mod;
else{
  long long Ans = 2LL;

  for( int i = 0 ; i < 26 ; ++i )
    Ans = ( Ans + 1LL * Find( l+1 , r-1 , i ) ) % Mod;

  return dp[l][r][alpha] = Ans;
}
}

  int main(){
    int N , i , j;
    long long Ans = 0LL;
    scanf( "%s" , Str );
    N = strlen(Str);

    for( i = 0 ; i <= 1000 ; ++i ){
      for( j = 0 ; j <= 1000 ; ++j ){
        for( int k = 0 ; k < 26 ; ++k )
          dp[i][j][k] = -1;
     }
   }

    for( i = 0 ; i < 26 ; ++i )
      Ans = ( Ans + Find( 0 , N-1 , i ) ) % Mod;

    printf( "%lld\n" , Ans );
    return 0;
 }
