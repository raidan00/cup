#include <stdio.h>
#include <string.h>

char from[] = "y qeez ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
char to[] = "a zooq our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
int main(){
	freopen("A-small-practice.in", "r", stdin);
	freopen("out.out", "w", stdout);
	int T;
	scanf("%d\n", &T);
	for( int i = 0; i<T; i++){
		char G[101];
		scanf("%[^\n]\n", G);
		for (int i = 0; i<strlen(G); i++){
			for(int k = 0; k<strlen(from); k++){
				if(from[k] == G[i]) {
					G[i] = to[k];
					k = 9999;
					break;
				}
			}
		}
		printf("Case #%d: %s\n", i+1, G);
	}
}
