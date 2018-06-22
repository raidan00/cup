#include <stdio.h>

int main(){
	freopen("A-large-practice.in", "r", stdin);
	freopen("out.out", "w", stdout);

	int T;
	scanf ("%d", &T);
	for (int i=1; i <= T; i++) {
		int N,K;
        scanf ("%d %d\n", &N, &K);
        printf ("Case #%d: ", i);
        puts ((K+1)%(1<<N)==0 ? "ON" : "OFF");
    }  
}
