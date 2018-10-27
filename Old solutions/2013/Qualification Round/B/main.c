#include <stdio.h>

int main(){
	freopen("B-large-practice.in", "r", stdin);
	freopen("out.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, M;
		scanf("%d %d\n", &N, &M);
		int map[N][M];
		for(int y=0; y<N; y++)
		for(int x=0; x<M; x++){
			scanf("%d", &map[y][x]);
		}
		int y=0;
		for(; y<N; y++)
		for(int x=0; x<M; x++){
			int max = map[y][x];
			for( int i=0; i<N; i++){
				if( map[i][x] > max ) max = map[i][x];
			}
			if(max == map[y][x])continue;
			max = map[y][x];
			for( int i=0; i<M; i++){
				if( map[y][i] > max ) max = map[y][i];
			}
			if(max == map[y][x])continue;
			y = 1000;
			printf("Case #%d: NO\n", t+1);
			break;
		}
		if( y != 1001 ) printf("Case #%d: YES\n", t+1);
	}
}
