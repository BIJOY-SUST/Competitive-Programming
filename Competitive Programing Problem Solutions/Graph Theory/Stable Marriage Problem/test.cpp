 #include "bits/stdc++.h"
 using namespace std;
 int Men[505][505] , Women[505][505];
 int CurMen[505] , MarriedMen[505] , MarriedWomen[505];
 bool Free[505];
 queue<int> q;

 int Find_Pos( int N , int index , int key ){
 	for( int i = 1 ; i <= N ; ++i )
 		if( Women[index][i] == key ) return i;

 	return 1;
 }

 int main(){
 	int T , N , i , j , Num;
 	scanf( "%d" , &T );

 	while( T-- ){
 		scanf( "%d" , &N );
 		fill( CurMen , CurMen + N + 1 , 1 );
 		fill( Free , Free + N + 1 , true );

 		for( i = 1 ; i <= N ; ++i ){
 			q.emplace( i );
 			scanf( "%d" , &Num );

 			for( j = 1 ; j <= N ; ++j )
 				scanf( "%d" , &Women[i][j] );
 		}

 		for( i = 1 ; i <= N ; ++i ){
 			scanf( "%d" , &Num );

 			for( j = 1 ; j <= N ; ++j )
 				scanf( "%d" , &Men[i][j] );
 		}

 		int y , x , ind1 , ind2;

 		while( !q.empty() ){
 			x = q.front();
 			q.pop();

 			for( i = CurMen[x] ; i <= N ; ++i ){
 				y = Men[x][i];

 				if( Free[y] ){
 					MarriedMen[x] = y;
 					MarriedWomen[y] = x;
 					Free[y] = false;
 					break;
 				}
 				else{
 					ind1 = Find_Pos( N , y , x );
 					ind2 = Find_Pos( N , y , MarriedWomen[y] );

 					if( ind1 < ind2 ){
 						q.emplace( MarriedWomen[y] );
 						MarriedWomen[y] = x;
 						MarriedMen[x] = y;
 						break;
 					}
 				}
 			}

 			CurMen[x] = i + 1;
 		}

 		for( i = 1 ; i <= N ; ++i )
 			printf( "%d %d\n" , i , MarriedMen[i] );
 	}

 	return 0;
 }
