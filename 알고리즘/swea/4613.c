#pragma warning(disable:4996)
#include <stdio.h>
int N, M,ans,min;
char map[55][55];
int cnt[55][3];
void count() {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (map[i][j] == 'W') cnt[i][0]++;
			else if (map[i][j] == 'B') cnt[i][1]++;
			else if (map[i][j] == 'R') cnt[i][2]++;
		}
	}
}
void init() {
	int i, j;
	ans = 0;
	for (i = 0; i < N; i++) cnt[i][0] = cnt[i][1] = cnt[i][2] = 0;
}
void sol2(int a,int b) {
	int i,k=0;
	for (i = 0; i < a; i++) k += cnt[i][1] + cnt[i][2];
	for (i = a; i <= a+b; i++) k += cnt[i][0] + cnt[i][2];
	for (i = a + b + 1; i < N; i++) k += cnt[i][0] + cnt[i][1];
	if (k < min) min = k;
}
void sol(int d,int k) {
	int i, j;
	for (i = 1; i <= N - 2; i++) {
		for (j = 0; j < N - 2; j++) {
			if(i+j<N-1) sol2(i, j);
		}
	}

}
int main()
{
	int i, T,j;
	scanf("%d", &T);
	for (i = 1; i <= T; i++) {
		scanf("%d %d", &N, &M);
		for (j = 0; j < N; j++) scanf("%s", map[j]);
		count();
		min = 2500;
		sol(0,0);
		printf("#%d %d\n", i, min);
		init();
	}
}
