#include <stdio.h>
#include <stdlib.h>

int cmpasc (const void * a, const void * b) {
	return ( *(int*)a - *(int*)b );
}
int cmpdes (const void * a, const void * b) {
	return ( *(int*)b - *(int*)a );
}
int main (){
	freopen("./A-large-practice.in", "r", stdin);
	freopen("./out.out", "w", stdout);

	int T;
	scanf("%d\n", &T);
	for (int i = 0; i < T; i++){
		int n;
		scanf("%d\n", &n);
		int v1[n];
		for(int i = 0; i < n; i++){
			scanf("%d", v1+i);
		}
		int v2[n];
		for(int i = 0; i < n; i++){
			scanf("%d", v2+i);
		}
		qsort(v1, n, sizeof(int), cmpasc);
		qsort(v2, n, sizeof(int), cmpdes);
		long long result = 0;
		for(int i = 0; i < n; i++){
			result += (long)(v1[i])*v2[i];
		}
		printf("Case #%d: %lld\n", i+1, result);
	}
}
