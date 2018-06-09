#include <stdio.h>
#include <string.h>
typedef struct {
	int m[2][2];
} mx2;
mx2 matrixMult(mx2 A, mx2 B){
	mx2 mxEmpty = { {{0, 0}, {0, 0}} };
	static mx2 C;
	C = mxEmpty;
	for ( int i = 0; i < 2; i ++)
	for ( int j = 0; j < 2; j ++)
	for ( int k = 0; k < 2; k ++)
		C.m[i][k] = (C.m[i][k] + A.m[i][j] * B.m[j][k]) % 1000;
	return C;
}
mx2 fastExponentiation(mx2 A, int n){
	if ( n == 1 ) return A;
	if ( n%2 == 0 ){
	  mx2 A1 = fastExponentiation(A, n/2);
      return matrixMult(A1, A1);
	}
	return matrixMult(A, fastExponentiation(A, n-1));
}
int main () {
	freopen("C-large-practice.in", "r", stdin);
	freopen("out.out", "w", stdout);

	int T;
	scanf("%d\n", &T);
	for( int i = 0; i < T; i++ ){
		int n;
		scanf("%d\n", &n);
		mx2 A = { {{3, 5}, {1, 3}} };
		mx2 matrix = fastExponentiation(A, n);
		int result = (2 * matrix.m[0][0] + 999) % 1000;
		printf( "Case #%d: %03d\n" , i+1, result );
	}
}
