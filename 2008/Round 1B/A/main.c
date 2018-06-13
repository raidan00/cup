#include <stdio.h>

int main(){
	freopen("A-large-practice.in", "r", stdin);
	freopen("out.out", "w", stdout);
	
	int N;
	scanf("%d\n", &N);
	for( int i=0; i < N; i++){
		int n, A, B, C, D, x0, y0, M;
		scanf("%d %d %d %d %d %d %d %d\n", &n, &A, &B, &C, &D, &x0, &y0, &M);
		long bucket[9] = { [0 ... 8] = 0 };
		long ret = 0;
		long X = x0;
		long Y = y0;
		for (int i = 0; i < n; i++) {
			bucket[((int)X % 3) * 3 + (int)Y % 3]++;
			X = (A * X + B) % M;
			Y = (C * Y + D) % M;
		}
		for (int i = 0; i < 9; i++){
			ret += bucket[i] * (bucket[i]-1) * (bucket[i]-2) / 6;
		}
		for (int i = 0; i < 9; i++)
		for (int j = i + 1; j < 9; j++)
		for (int k = j + 1; k < 9; k++){
			if ( ((i / 3) + (j / 3) + (k / 3)) % 3 == 0 && ((i % 3) + (j % 3) + (k % 3)) % 3 == 0 ){
				ret += bucket[i] * bucket[j] * bucket[k];
			}
		}
		printf("Case #%d: %ld\n", i+1, ret);
	}
}
