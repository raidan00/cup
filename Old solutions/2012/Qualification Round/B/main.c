#include <stdio.h>
#include <stdlib.h>

int main(){
	freopen("B-large-practice.in", "r", stdin);
	freopen("out.out", "w", stdout);

	int T;
	scanf("%d\n", &T);
	for( int i=0; i<T; i++ ){
		int N, S, p;
		scanf("%d %d %d", &N, &S, &p);
		int count = 0;
		for( int i=0; i<N; i++ ){
			int sum;
			scanf("%d", &sum);
			int unsurp = p - 1;
			if( unsurp < 0 ) unsurp = 0;
			int surp = p - 2;
			if( surp < 0 ) surp = 0;
			if( (sum - p - unsurp*2) >= 0 ){
				count ++;
			}else if( S>0 && (sum - p - surp*2) >= 0 ){
				count ++;
				S--;
			}
		}
		printf("Case #%d: %d\n", i+1, count);
	}
}
