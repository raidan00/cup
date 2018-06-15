#include <stdio.h>

int main(){
	freopen("B-small-practice.in", "r", stdin);
	freopen("out.out", "w", stdout);

	int C;
	scanf("%d\n", &C);
	for(int i=0; i<C; i++){
		long A, B, P;
		scanf("%ld %ld %ld\n", &A, &B, &P);
		long len = B - A + 1;
		void *unions[len];
		for(int i = 0; i < len; i++){
			unions[i] = &unions[i];
		}
		long primes[B - P];
		for(long prime = P; prime < B; prime++) {
			int flag = 1;
			for (long k = 2; k < prime; k++) {
				if (prime % k == 0) {flag = 0; break;}
			}
			if (flag){
				primes[prime-P] = 1;
			}else{
				primes[prime-P] = 0;
			}
		}
		for(int i = 0; i < len; i++)
		for(int j = i+1; j < len; j++){
			for(long k = 0; k < B-P; k++) {
				long prime = P+k;	
				int flag = primes[k];
				if (flag){
					if ((i + A)%prime == 0 && (j + A)%prime == 0){
						void **p = unions+j;
						while ( *p != &(*p) ){
							p = *p;
						}
						void **p1 = unions+i;
						while ( *p1 != &(*p1) ){
							p1 = *p1;
						}
						*p = *p1;
					}
				}

			}
		}
		int count = 0;
		for(int i = 0; i < len; i++){
			if ( unions[i] == &unions[i] ) count++;
		}
		printf("Case #%d: %d\n", i+1, count);
	}
}
