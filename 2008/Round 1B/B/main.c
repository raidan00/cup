// !!!!!!!!!!! only B-small-practice !!!!!!!!!!!!!!!!!!
// !!!!!!!!!!! only B-small-practice !!!!!!!!!!!!!!!!!!
// !!!!!!!!!!! only B-small-practice !!!!!!!!!!!!!!!!!!
#include <stdio.h>
#include <math.h>

int main(){
	freopen("B-small-practice.in", "r", stdin);
	freopen("out.out", "w", stdout);

	int n = 1000000;
	_Bool primes[n];
	int i, j;
	for (i=0;i<n;i++)
		primes[i]=1; 
	primes[0]=0,primes[1]=0;
	for (i=2;i<sqrt(n);i++)
		for (j=i*i;j<n;j+=i)
			primes[j] = 0;
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
		for(long k = P; k < len; k++) {
			long prime = k;	
			int flag = primes[k];
			if (flag){
				void **p = NULL;
				for(int i = 0; i < len; i++){
					if ((i + A)%prime == 0){
						if(p == NULL){
							p = unions+i;
							while ( *p != &(*p) ){
								p = *p;
							}
						} else {
							void **p1 = unions+i;
							while ( *p1 != &(*p1) ){
								p1 = *p1;
							}
							*p1 = *p;
						}
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
