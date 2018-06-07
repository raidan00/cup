#include <stdio.h>
#include <stdlib.h>

struct flavor {
	int num;
	int malted;
};
struct cust {
	int len;
	struct flavor *flavors;
};
int Case, N, M;
int check( int *flavors, struct cust *customers ){
	for (int i = 0; i < M; i++){
		for (int j = 0; j < customers[i].len; j++){
			if ( customers[i].flavors[j].malted == flavors[customers[i].flavors[j].num-1] ) break;
			if ( customers[i].flavors[j].malted == 1 && flavors[customers[i].flavors[j].num-1] == 0 ){
				flavors[customers[i].flavors[j].num-1] = 1;
				check( flavors, customers );
				return 1;
			}
			if ( j == customers[i].len -1 &&  customers[i].flavors[j].malted != flavors[customers[i].flavors[j].num-1] ){
				printf("Case #%d: IMPOSSIBLE\n", Case+1);
				return 1;
			}
		}
	}

	printf("Case #%d:", Case+1);
	for (int i = 0; i < N; i++) {
		printf(" %d", flavors[i]);
	}
	printf("\n");
}
int cmpfunc (const void * a, const void * b) {
	if ( ((struct flavor *)a)->malted == 1  ) return 1;
	return -1;
}
int main (){
	freopen("./B-large-practice.in", "r", stdin);
	freopen("./out.out", "w", stdout);

	int C;
	scanf("%d\n", &C);
	for ( Case = 0; Case < C; Case++){
		scanf("%d\n", &N);
		int flavors[N];
		for (int i = 0; i < N; i++) flavors[i] = 0;
		scanf("%d\n", &M);
		struct cust customers[M];
		for (int i = 0; i < M; i++){
			scanf("%d", &customers[i].len);
			customers[i].flavors = malloc(sizeof(struct flavor) * customers[i].len);
			for (int j = 0; j < customers[i].len; j++){
				scanf("%d %d", &customers[i].flavors[j].num, &customers[i].flavors[j].malted);
			}
			qsort(customers[i].flavors, customers[i].len, sizeof(struct flavor), cmpfunc);
		}
		check( flavors, customers );
	}
}
