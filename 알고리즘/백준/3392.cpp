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
//segment tree에서 n이 2의 거듭제곱이면 2n개만 있어도 됨
//그렇지 않은 경우는 가까운 2의 거듭제곱으로 n을 올림한 뒤 2를 곱해야함. 귀찮다면 4*n을 하는 것도 방법
int n, seg[4 * MAX_Y], cnt[4 * MAX_Y];
int a, b, c, d, ans, k;
tt arr[2 * MAX_N];
void Q(int left, int right) //퀵소트 
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
	if (nodeRight < low || high < nodeLeft) //y의 범위가 현재 세그먼트 트리 배열 범위를 벗어날 경우
		return;
	if (low <= nodeLeft && nodeRight <= high) //범위 들어왔다면, val==1은 시작선 val==-1은 끝선 나타냄
		cnt[node] += val;
	else { //한쪽만 범위가 걸친다면 다음 노드로 들어간다
		int mid = (nodeLeft + nodeRight) >> 1;
		update(low, high, val, node * 2, nodeLeft, mid);
		update(low, high, val, node * 2 + 1, mid + 1, nodeRight);
	}
	if (cnt[node]) seg[node] = nodeRight - nodeLeft + 1;
	else {
		if (nodeLeft == nodeRight) seg[node] = 0; //리프노드일 경우
		else seg[node] = seg[node * 2] + seg[node * 2 + 1]; //cnt가 0이고 리프노드가 아닐 경우
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
	for (int i = 0; i < 2 * n; i++) { //x좌표를 기준으로 정렬 해놓은 상태에서 update
		if (i) {
			int x = arr[i].x - k; //x 변화량
			ans += x * seg[1]; //seg[1]에는 이전 x 구간에서 얼마만큼의 y가 포함되어 있는지 나타냄
		}
		update(arr[i].y1, arr[i].y2, arr[i].z, 1, 0, MAX_Y);
		k = arr[i].x; //이전 x좌표 정보
	}
	printf("%d\n", ans);
	return 0;
}