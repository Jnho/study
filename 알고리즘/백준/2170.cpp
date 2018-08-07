#pragma warning(disable:4996)
#include<stdio.h>
#define MAX 1000005
int arr[MAX][2];

//퀵 정렬
void Q(int left, int right)
{
	int q, r, p;
	if (left >= right) return;
	q = left-1;
	r = right+1;
	p = arr[(q + r) / 2][0];
	while(1){
		while (p > arr[++q][0]);
		while (p < arr[--r][0]);

		if (q >= r) break;
		int t1, t2;
		t1 = arr[q][0];
		t2 = arr[q][1];
		arr[q][0] = arr[r][0];
		arr[q][1] = arr[r][1];
		arr[r][0] = t1;
		arr[r][1] = t2;
	}
	Q(left, q - 1);
	Q(r + 1, right);
}
int main()
{
	int N, i;
	int start, end, sum = 0;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d %d", &arr[i][0],&arr[i][1]);
	}
	Q(0, N - 1);
	start = arr[0][0];
	end = arr[0][1];
	for (i = 1; i < N; i++) {
		//현재 끝점이 다음 선분의 시작점 보다 작다면 sum 계산하고 다음 선분으로 start와 end 재설정
		if (end < arr[i][0]) {
			sum += end - start;
			start = arr[i][0];
			end = arr[i][1];
		}
		else {
			//다음 선분의 시작점 보다 현재 끝점이 더 뒤에 있고, 다음 선분의 끝점보단 앞에 있을 경우 end를 늘려준다
			if(end<arr[i][1])
				end = arr[i][1];
		}
	}
	//마지막 계산
	sum += end - start;
	printf("%d\n", sum);
	return 0;
}