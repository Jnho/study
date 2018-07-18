#pragma warning(disable:4996)
#include<stdio.h>
char map[70][70];
int depth[65];
void divide(int n,int k,int a,int b) {
	if (n == 0) return;
	int i, j,f=0;
	for (i = a; i < n+a; ++i) {
		for (j = b; j < n+b; ++j) {
			if (map[a][b] != map[i][j]) {
				f = 1;
				break;
			}
		}
		if (f) break;
	}
	if (i == n + a && j == n + b) {		
			printf("%c", map[a][b]);
			depth[k]++;
			if (depth[k] == 4) {
				printf(")");
				depth[k] = 0;
			}
		
	}
	else {
		printf("(");
		divide(n / 2, k + 1, a, b);
		divide(n / 2, k + 1, a, b + n / 2);
		divide(n / 2, k + 1, a + n / 2, b);
		divide(n / 2, k + 1, a + n / 2, b + n / 2);
		depth[k]++;
		if (depth[k] == 4) {
			printf(")");
			depth[k] = 0;
		}
	}
}
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%s",map[i]);
	divide(N,0,0,0);
}