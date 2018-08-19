#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>

int a[1001];
int p[1001];

/*
Fenwick Tree ���� Ʈ��
���� ���� ���� �� ���
ex 1~7  ���� ���� ���ϰ� �ʹ�
7�� ������ 111
6�� ������ 110
4�� ������ 100

������ ���ڸ� 1�� ���ָ鼭 �ε����� ã�� ����� ���� �����ָ� �ȴ�.
1~10 ���� ���� ���ϰ� �ʹ�
10�� ������ 1010
8��  ������ 1000
�迭 p[10]�� p[8]�� ����� ���� �����ָ� �ȴ�.
*/
int sum(int i)
{
	int ans = 0;
	while (i > 0)
	{
		ans += p[i];
		i &= ~(i&-i);
	}
	return ans;
}

/*
ó�� Ʈ���� ������ ��
�ε����� ��Ʈ ���ڸ� 1�� �����ָ鼭 �ε����� ã�´�
ex 1�� ���� ���
1�� ������ 1
���ڸ� 1�� ���� ���� �ε��� 2
2�� �������� 10
���ڸ� (10)�� �����ָ� ���� �ε��� 4
���� �ε��� 8

1ĭ 1 3 5 7 9
2ĭ 2 6 10
4ĭ 4 
8ĭ 8
*/
void update(int i, int n, int num)
{
	while (i <= n)
	{
		p[i] += num;
		i += (i&-i);
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i + 1]);
		update(i + 1, n, a[i + 1]);
	}
	for (int i = 0; i < m; i++) {
		int w, x;
		scanf("%d %d", &w, &x);
		printf("%d \n", sum(x) - sum(w - 1));
	}
}