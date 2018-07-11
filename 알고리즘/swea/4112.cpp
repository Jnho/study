#pragma warning(disable:4996)
#include <stdio.h>
int visit[10005], check[10005],qu[10005][2];

void init() {
	for (int i = 0; i < 10001; i++) visit[i] = 0;
	visit[0] = 1; //0은 안쓸거라서 방문 못하게
}
int bfs(int x,int y) {
	int front = 0, rear = 0,data,tt;
	int tx, ty;
	if (x == y) return 0;
	qu[rear][0] = x;
	qu[rear++][1] = 0;
	visit[x] = 1;
	while (1) {
		data = qu[front][0];
		tt = qu[front++][1];
		if (data == y) return tt;
		for (int i = 0; i < 6; i++) {
			//6방향 둘러보기
			if (i == 0) tx = data - check[data];
			else if (i == 1) tx = data - check[data] + 1;
			else if (i == 2) tx = data - 1;
			else if (i == 3) tx = data + 1;
			else if (i == 4) tx = data + check[data];
			else if (i == 5) tx = data + check[data] + 1;
			//1보다 작은 지점은 없음, 방문한 지점, 두칸이상 차이나는 지점은 가면안됨
			if (tx < 1 || visit[tx]==1 || check[data]-check[tx]>1 ||check[tx]-check[data]>1) continue;
			//한 칸 차이 나지만 다음 줄로 넘어가기전과 넘어간 직후 숫자는 인접하지 않기 때문에 방문하면 안됨
			if (check[data] - check[tx] == 1 || check[tx] - check[data] == 1) {
				if (data == 1 || tx == 1); // (1,2) (2,1)은 예외처리
				else if (data - tx == 1 || tx - data == 1) continue;
			}
			//같은 줄에 있지만 인접하지 않으면 방문하면 안됨
			if (check[data] == check[tx] && !(data - tx == 1 || tx - data == 1)) continue;
			qu[rear][0] = tx;
			qu[rear++][1] = tt+1;
			visit[tx] = 1;
		}
	}
}
int main(void) {
	int t, T,a,b;
	scanf("%d", &T);
	a = 1;
	b = 0;
	check[0] = 0;
	for (int i = 1; i <= 10000;i++) {
		check[i] = a;
		b++;
		if (a == b) {
			a++;
			b = 0;
		}
	}
	for (t = 1; t <= T; t++) {
		scanf("%d %d", &a, &b);
		init();
		bfs(a,b);
		printf("#%d %d\n", t, bfs(a,b));
	}
	return 0;
}