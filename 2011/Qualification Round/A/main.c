#include <stdio.h>
#include <stdlib.h>

int main(){
	freopen("A-large-practice.in", "r", stdin);
	freopen("out.out", "w", stdout);

	int T;
	scanf("%d\n", &T);
	for(int i = 0; i<T; i++){
		int blue = 1;
		int orange = 1;
		int partial = 0;
		char last = 'X';
		int steps = 0;
		int N;
		scanf("%d ", &N);
		for(int i = 0; i<N; i++){
			char R; int P;
			scanf("%c %d ", &R, &P);
			int *ptr;
			if ( R == 'B' ) ptr = &blue;
			if ( R == 'O' ) ptr = &orange;
			int num = abs(P-*ptr)+1;
			if ( R != last ){
				if( partial >= num ) num = 1;
				else num -= partial;
				partial = 0;
				last = R;
			}
			partial += num;
			steps += num;
			*ptr = P;
		}
		printf("Case #%d: %d\n", i+1, steps);
	}
}
