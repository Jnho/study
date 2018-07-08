#pragma warning(disable:4996)
#include <stdio.h>

int p[1000001];
void init()
{
	for (int i = 0; i < 1000001; i++) p[i] = i;
}
int find(int x)
{
	if (p[x] == x) return x;
	else p[x] = find(p[x]);
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);

	p[y] = x;
	return;
}
int main()
{
	int i, T, N, M, k, a, b;
	scanf("%d", &T);

	for (i = 1; i <= T; i++) {
		init();
		int top = 0;
		scanf("%d %d", &N, &M);
		printf("#%d ", i);
		for (int m = 0; m < M; m++) {
			scanf("%d %d %d", &k, &a, &b);

			if (k == 0)
			{
				merge(a, b);
			}
			else if (k == 1)
			{
				a = find(a);
				b = find(b);

				if (a == b)
				{
					printf("1");
				}
				else
				{
					printf("0");
				}
			}
		}
		printf("\n");

	}
	return 0;
}