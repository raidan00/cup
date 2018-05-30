#include <stdio.h>
#include <stdlib.h>

enum timeType { leave, arrive };
struct time {
	int value;
	enum timeType type;
};
int cmpfunc (const void *a, const void *b) {
	if ( ((struct time *)a)->value > ((struct time *)b)->value ) return 1;
	if ( ((struct time *)a)->value == ((struct time *)b)->value && ((struct time *)a)->type == leave ) return 1;
	return -1;
}
int main () {
	freopen("./B-large-practice.in", "r", stdin);
	freopen("./out.out", "w", stdout);
	int N;
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++){
		int T;
		scanf("%d\n", &T);
		int NA, NB;
		scanf("%d %d\n", &NA, &NB);
		struct time a[NA + NB];
		struct time b[NA + NB];
		int k = 0;
		for (; k < NA; k++){
			int leaveHour, leaveMinute, arriveHour, arriveMinute;
			scanf("%d:%d %d:%d\n", &leaveHour, &leaveMinute, &arriveHour, &arriveMinute);
			a[k].value = leaveHour*60 + leaveMinute;
			a[k].type = leave;
			b[k].value = arriveHour*60 + arriveMinute + T;
			b[k].type = arrive;
		}
		for (int j = 0; j < NB; j++){
			int leaveHour, leaveMinute, arriveHour, arriveMinute;
			scanf("%d:%d %d:%d\n", &leaveHour, &leaveMinute, &arriveHour, &arriveMinute);
			b[j+k].value = leaveHour*60 + leaveMinute;
			b[j+k].type = leave;
			a[j+k].value = arriveHour*60 + arriveMinute + T;
			a[j+k].type = arrive;
		}
		qsort(a, NA+NB, sizeof(struct time), cmpfunc);
		qsort(b, NA+NB, sizeof(struct time), cmpfunc);
		int A = 0, maxA = 0;
		for(int i = 0; i < NA+NB; i++){
			if( a[i].type == leave) {
				A++;
				if ( A > maxA ) maxA = A;
			}
			if( a[i].type == arrive) A--; 
		}
		int B = 0, maxB = 0;
		for(int i = 0; i < NA+NB; i++){
			if( b[i].type == leave) {
				B++;
				if ( B > maxB ) maxB = B;
			}
			if( b[i].type == arrive) B--;
		}
		printf("Case #%d: %d %d\n", i+1, maxA, maxB);
	}
}
