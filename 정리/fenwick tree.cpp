#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>

int a[1001];
int p[1001];

/*
Fenwick Tree 펜윅 트리
구간 합을 구할 때 사용
ex 1~7  구간 값을 구하고 싶다
7의 이진수 111
6의 이진수 110
4의 이진수 100

마지막 끝자리 1을 빼주면서 인덱스를 찾아 저장된 값을 더해주면 된다.
1~10 구간 값을 구하고 싶다
10의 이진수 1010
8의  이진수 1000
배열 p[10]과 p[8]에 저장된 값을 더해주면 된다.
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
처음 트리를 구성할 때
인덱스의 비트 끝자리 1을 더해주면서 인덱스를 찾는다
ex 1이 들어올 경우
1의 이진수 1
끝자리 1을 더해 다음 인덱스 2
2의 이진수는 10
끝자리 (10)를 더해주면 다음 인덱스 4
다음 인덱스 8

1칸 1 3 5 7 9
2칸 2 6 10
4칸 4 
8칸 8
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