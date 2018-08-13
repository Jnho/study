#pragma warning(disable:4996)

#include <stdio.h>

void selection_sort(int *arr) //선택 정렬 앞에서 부터 하나씩 정렬 해나감
{
	int i, j;
	for (i = 0; i < 9; i++) {
		for (j = i+1; j < 10; j++) {
			if (arr[i] > arr[j]) {
				int t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}
	for (i = 0; i < 10; i++) printf("%d ", arr[i]);
}

void bubble_sort(int arr[]) //버블 정렬, 인접한 두개 크기 비교로 정렬
{
	int i, j;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9 - i; j++) {
			if (arr[j] < arr[j + 1]) {
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
}

void insertion_sort(int arr[]) //key값 하나 설정, 키값 기준으로 정렬 하고 마지막에 키값 위치 찾아줌
{
	int i, j,k;
	for (i = 1; i < 10;i++) {
		k = arr[i];
		for (j = i-1; j >= 0; j--) {
			if (k < arr[j]) {
				arr[j + 1] = arr[j];
			}
			else break;
		}
		arr[j + 1] = k;
	}
	for (i = 0; i < 10; i++)printf("%d ", arr[i]);
}

void quick(int left, int right,int arr[]) //퀵 정렬, 분할 정복
{
	if (left >= right) return;
	int r, q, p;
	q = left - 1;
	r = right + 1;
	p = arr[(q + r) / 2];

	while (1)
	{
		while (arr[++q] > p);
		while (arr[--r] < p);

		if (q >= r) break;
		int t = arr[q];
		arr[q] = arr[r];
		arr[r] = t;
	}
	quick(left, q - 1, arr);
	quick(r + 1, right, arr);

	if (left == 0 & right == 9) {
		for (int i = 0; i < 10; i++) printf("%d ", arr[i]);
	}
}


int main()
{
	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int arr2[11];
	selection_sort(arr);
	printf("\n");
	bubble_sort(arr);
	printf("\n");
	insertion_sort(arr);
	printf("\n");
	arr[0] = 2; arr[1] = 7; arr[2] = 4; arr[3] = 5; arr[4] = 1;
	arr[5] = 9; arr[6] = 10; arr[7] = 8; arr[8] = 3; arr[9] = 6;
	quick(0, 9, arr);
	printf("\n");

	return 0;
}
