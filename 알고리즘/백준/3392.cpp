#pragma warning(disable:4996)

#include<stdio.h>

#define MAX_N 10000
#define MAX_Y 30000
typedef struct {
	int x;
	int y1;
	int y2;
	int z;
}tt;
//segment tree���� n�� 2�� �ŵ������̸� 2n���� �־ ��
//�׷��� ���� ���� ����� 2�� �ŵ��������� n�� �ø��� �� 2�� ���ؾ���. �����ٸ� 4*n�� �ϴ� �͵� ���
int n, seg[4 * MAX_Y], cnt[4 * MAX_Y];
int a, b, c, d, ans, k;
tt arr[2 * MAX_N];
void Q(int left, int right) //����Ʈ 
{
	int q, r;
	if (left >= right) return;
	q = left - 1;
	r = right + 1;
	tt p = arr[(left + right) / 2];

	while (1) {
		while (arr[++q].x < p.x);
		while (arr[--r].x > p.x);

		if (q >= r) break;
		tt t = arr[q];
		arr[q] = arr[r];
		arr[r] = t;
	}

	Q(left, q - 1);
	Q(r + 1, right);
}
void update(int low, int high, int val, int node, int nodeLeft, int nodeRight)
{
	if (nodeRight < low || high < nodeLeft) //y�� ������ ���� ���׸�Ʈ Ʈ�� �迭 ������ ��� ���
		return;
	if (low <= nodeLeft && nodeRight <= high) //���� ���Դٸ�, val==1�� ���ۼ� val==-1�� ���� ��Ÿ��
		cnt[node] += val;
	else { //���ʸ� ������ ��ģ�ٸ� ���� ���� ����
		int mid = (nodeLeft + nodeRight) >> 1;
		update(low, high, val, node * 2, nodeLeft, mid);
		update(low, high, val, node * 2 + 1, mid + 1, nodeRight);
	}
	if (cnt[node]) seg[node] = nodeRight - nodeLeft + 1;
	else {
		if (nodeLeft == nodeRight) seg[node] = 0; //��������� ���
		else seg[node] = seg[node * 2] + seg[node * 2 + 1]; //cnt�� 0�̰� ������尡 �ƴ� ���
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		arr[i] = { a,b,d - 1,1 };
		arr[i + n] = { c,b,d - 1,-1 };
	}

	Q(0, 2 * n - 1);
	for (int i = 0; i < 2 * n; i++) { //x��ǥ�� �������� ���� �س��� ���¿��� update
		if (i) {
			int x = arr[i].x - k; //x ��ȭ��
			ans += x * seg[1]; //seg[1]���� ���� x �������� �󸶸�ŭ�� y�� ���ԵǾ� �ִ��� ��Ÿ��
		}
		update(arr[i].y1, arr[i].y2, arr[i].z, 1, 0, MAX_Y);
		k = arr[i].x; //���� x��ǥ ����
	}
	printf("%d\n", ans);
	return 0;
}