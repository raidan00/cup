#include <stdio.h>
#include <string.h>

int main(){
	freopen("A-large-practice.in", "r", stdin);
	freopen("out.out", "w", stdout);
	
	int L, D, N;
	scanf("%d %d %d\n", &L, &D, &N);
	char arr[D][L+1];
	for(int i=0; i<D; i++){
		scanf("%s\n", arr[i]);
	}
	for(int i=0; i<N; i++){
		char pattern[1024];
		scanf("%s\n", pattern);
		int len = strlen(pattern);
		int count = 0;
		for(int i=0; i<D; i++){
			int j = 0;
			int group = 0;
			for(int k=0; k<len; k++){
				if(pattern[k] == arr[i][j] && j == L - 1) count++;	
				else if(pattern[k] == '(') group = 1;	
				else if(pattern[k] == ')') break;	
				else if(pattern[k] == arr[i][j] && group == 1){
					group = 0;
					j++;
					k = strchr(pattern+k, ')') - pattern;
				}
				else if(pattern[k] == arr[i][j]) j++;	
				else if(pattern[k] != arr[i][j] && group == 0) break;	
			}
		}
		printf("Case #%d: %d\n", i+1, count);
	}
}
