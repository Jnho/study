#pragma warning(disable:4996)
#include <stdio.h>
int visit[10005], check[10005],qu[10005][2];

void init() {
	for (int i = 0; i < 10001; i++) visit[i] = 0;
	visit[0] = 1; //0�� �Ⱦ��Ŷ� �湮 ���ϰ�
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
			//6���� �ѷ�����
			if (i == 0) tx = data - check[data];
			else if (i == 1) tx = data - check[data] + 1;
			else if (i == 2) tx = data - 1;
			else if (i == 3) tx = data + 1;
			else if (i == 4) tx = data + check[data];
			else if (i == 5) tx = data + check[data] + 1;
			//1���� ���� ������ ����, �湮�� ����, ��ĭ�̻� ���̳��� ������ ����ȵ�
			if (tx < 1 || visit[tx]==1 || check[data]-check[tx]>1 ||check[tx]-check[data]>1) continue;
			//�� ĭ ���� ������ ���� �ٷ� �Ѿ������ �Ѿ ���� ���ڴ� �������� �ʱ� ������ �湮�ϸ� �ȵ�
			if (check[data] - check[tx] == 1 || check[tx] - check[data] == 1) {
				if (data == 1 || tx == 1); // (1,2) (2,1)�� ����ó��
				else if (data - tx == 1 || tx - data == 1) continue;
			}
			//���� �ٿ� ������ �������� ������ �湮�ϸ� �ȵ�
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