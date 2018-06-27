#include <stdio.h>

char fields[4][4];
int dx[10][4] = { {0,1,2,3}, {0,1,2,3}, {0,1,2,3}, {0,1,2,3}, {0,0,0,0}, {1,1,1,1}, {2,2,2,2}, {3,3,3,3}, {0,1,2,3}, {0,1,2,3} };
int dy[10][4] = { {0,0,0,0}, {1,1,1,1}, {2,2,2,2}, {3,3,3,3}, {0,1,2,3}, {0,1,2,3}, {0,1,2,3}, {0,1,2,3}, {0,1,2,3}, {3,2,1,0} };
int main(){
	freopen("A-large-practice.in", "r", stdin);
	freopen("out.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for(int i=0; i<T; i++){
		for(int i=0; i<4; i++)
		for(int k=0; k<4; k++){
			scanf(" %c", &fields[k][i]);
		}
		int completed = 1;
		int j=0;
		for(; j<10; j++){
			char test = 'E';
			int next = 0;
			for(int k=0; k<4; k++){
				char c = fields[ dx[j][k] ][ dy[j][k] ];
				if ( c == '.' ){
					completed = 0;
				}
				if ( next ) continue;
				if ( k == 3 && ( c == test || c == 'T' ) ){
					printf("Case #%d: %c won\n", i+1, test);
					j = 100;
					break;
				}
				if ( test == 'E' && c != 'T' && c != '.' ) test = c;
				if ( c != test && c != 'T') next = 1;
			}
		}
		if ( completed  == 1 && j != 101) printf("Case #%d: Draw\n", i+1);
		if ( completed  == 0 && j != 101) printf("Case #%d: Game has not completed\n", i+1);
	}
	
}
