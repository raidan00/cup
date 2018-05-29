#include <stdio.h>
#include <string.h>
int main()
{
	freopen("./A-large-practice.in", "r", stdin);
	freopen("./out.out", "w", stdout);
	
	int N;
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++){
		int S;
		scanf("%d\n", &S);
		char s[S][101];
		for (int i = 0; i < S; i++){
			scanf("%[^\n]\n", s[i]);
		}
		int Q;
		scanf("%d\n", &Q);
		int k = 0;
		char cpy[S][101];
		for (int i = 0; i < S; i++){
			strcpy(cpy[i], s[i]);
		}
		int length = S;
		for (int i = 0; i < Q; i++){
			char q[1001];
			scanf("%[^\n]\n", q);
			for (int i = 0; i < S; i++){
				if ( strcmp(q, cpy[i]) == 0 ){
					length--;
					if ( length == 0 ){
						for (int i = 0; i < S; i++){
							strcpy(cpy[i], s[i]);
						}
						length = S-1;
						k++;
					}
					cpy[i][0] = '\0';
					break;
				}
			}
		}
		printf("Case #%d: %d\n", i+1, k);
	}
}
