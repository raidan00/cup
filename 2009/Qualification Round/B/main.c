#include <stdio.h>

typedef struct{
	int num;
	char label;
} cell;
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};
int H, W;
cell *getLast(cell *map, int y, int x){
	int lowest = 9999999;
	cell *next = NULL;
	int nxNext, nyNext;
	for( int i = 0; i<4; i++){
		int nx = x+dx[i], ny = y + dy[i];
		if( nx<0 || ny<0 || nx>=W || ny>=H ) continue;
		if( map[ny*W+nx].num < map[y*W+x].num && map[ny*W+nx].num < lowest ){
			next = &map[ny*W+nx];
			lowest = map[ny*W+nx].num;
			nxNext = nx;
			nyNext = ny;
		}
	}
	if(next == NULL)return &map[y*W+x];
	else return getLast(map, nyNext, nxNext);
}
int main(){
	freopen("B-large-practice.in", "r", stdin);
	freopen("out.out", "w", stdout);

	int T;
	scanf("%d\n", &T);
	for(int i=0; i<T; i++){
		scanf("%d %d\n", &H, &W);
		cell map[H][W];
		for(int y=0; y<H; y++)
		for(int x=0; x<W; x++){
			scanf("%d", &map[y][x].num);
			map[y][x].label = '0';
		}
		char label = 'a';
		for(int y=0; y<H; y++)
		for(int x=0; x<W; x++){
			if( map[y][x].label != '0' )continue;
			cell *last = getLast(&map[0][0], y, x);
			if(last->label == '0'){
				last->label = label++;
			}
			map[y][x].label = last->label;
		}
		printf("Case #%d:\n", i+1);
		for(int y=0; y<H; y++){
			for(int x=0; x<W; x++){
				printf("%c ", map[y][x].label);
			}
			printf("\n");
		}
	}
}
