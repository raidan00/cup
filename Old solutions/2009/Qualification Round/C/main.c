#include <stdio.h>
#include <string.h>

char pattern[] = "welcome to code jam";
char str[501];
int mem[501][20];

int dp(int i, int j) {
	int *ret = &mem[i][j];
	if( *ret >= 0 ) return *ret;
	if(pattern[j] == '\0') return  *ret = 1;
	if(str[i] == '\0') return *ret = 0;
    if (str[i] == pattern[j]) return *ret = (dp(i + 1, j) + dp(i + 1, j + 1))%10000;
    return *ret = dp(i + 1, j)%10000;
}

int main(){
	freopen("C-large-practice.in", "r", stdin);
	freopen("out.out", "w", stdout);

	int N;
	scanf("%d\n", &N);
	for( int i=0; i<N; i++){
		scanf("%[^\n]\n", &str[0]);
		memset(mem, -1, sizeof(mem));
		printf("Case #%d: %04d\n", i+1, dp(0,0));
	}
}
