#include <stdio.h>

typedef struct {
	long num;
	void **p;
}num;
int main(){
	freopen("B-small-practice.in", "r", stdin);
	freopen("out.out", "w", stdout);

	int C;
	scanf("%d\n", &C);
	for(int i=0; i<C; i++){
		long A, B, P;
		scanf("%ld %ld %ld\n", &A, &B, &P);
		long len = B - A + 1;
		num nums[len];
		void *unions[len];
		for(int i = 0; i < len; i++){
			nums[i].num = A+i;
			nums[i].p = &unions[i];
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
					if (nums[i].num%prime == 0 && nums[j].num%prime == 0){
						void **p = nums[j].p;
						while ( *p != &(*p) ){
							p = *p;
						}
						void **p1 = nums[i].p;
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
