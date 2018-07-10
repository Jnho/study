#pragma warning(disable:4996)
#include <stdio.h>
#include<vector>
using namespace std;

#define MAX 1000005
int N, M, K;
vector <long long>arr;
struct RMQ { //Range minimum query
	//�迭�� ����
	int n;
	//�� ������ �ּ�ġ
	vector<long long> rangeMin;
	RMQ(const vector<long long>& array) {
		n = array.size();
		rangeMin.resize(n * 4);
		init(array, 0, n - 1, 1);
	}
	//node ��尡 array[left..right]�迭�� ǥ���� ��
	//node�� ��Ʈ�� �ϴ� ����Ʈ���� �ʱ�ȭ�ϰ� �� ������ ���� ��ȯ�Ѵ�
	long long init(const vector<long long>& array, int left, int right, int node) {
		if (left == right)
			return rangeMin[node] = array[left];
		int mid = (left + right) / 2;
		long long leftMin = init(array, left, mid, node * 2);
		long long rightMin = init(array, mid + 1, right, node * 2 + 1);
		return rangeMin[node] = leftMin + rightMin;
	}

	//node�� ǥ���ϴ� ���� array[nodeLeft..nodeRight]�� �־��� ��
	//�� ������ array[left..right]�� �������� ���� ���Ѵ�.
	long long query(int left, int right, int node, int nodeLeft, int nodeRight) {

		//�� ������ ��ġ�� ������ 0 ��ȯ
		if (right < nodeLeft || nodeRight < left) return 0;

		//node�� ǥ���ϴ� ������ array[left..right]�� ������ ���ԵǴ� ���
		if (left <= nodeLeft && nodeRight <= right)
			return rangeMin[node];

		//���� ������ ������ Ǭ �� ����� ��ģ��
		int mid = (nodeLeft + nodeRight) / 2;
		long long a = query(left, right, node * 2, nodeLeft, mid);
		long long b = query(left, right, node * 2 + 1, mid + 1, nodeRight);
		return a + b;
	}
	//query�� �ܺο��� ȣ���ϱ� ���� �������̽�
	long long query(int left, int right) {
		return query(left, right, 1, 0, n - 1);
	}

	//array[index]=newValue�� �ٲ���� �� node�� ��Ʈ�� �ϴ� 
	//���� Ʈ���� �����ϰ� ��尡 ǥ���ϴ� ������ �ּ�ġ�� ��ȯ�Ѵ�
	long long update(int index, int newValue, int node, int nodeLeft, int nodeRight) {

		//index�� ��尡 ǥ���ϴ� ������ ������� ��쿣 �����Ѵ�
		if (index < nodeLeft || nodeRight < index)
			return rangeMin[node];
		//Ʈ���� �������� ������ ���
		if (nodeLeft == nodeRight) return rangeMin[node] = newValue;
		int mid = (nodeLeft + nodeRight) / 2;
		long long a = update(index, newValue, node * 2, nodeLeft, mid);
		long long b = update(index, newValue, node * 2 + 1, mid + 1, nodeRight);
		return rangeMin[node]=a + b;
	}
	//update�� �ܺο��� ȣ���ϱ� ���� �������̽�
	long long update(int index, int newValue) {
		return update(index, newValue, 1, 0, n - 1);
	}
};

int main() {
	int a, b, c, i;
	long long ans;
	scanf("%d %d %d", &N, &M, &K);
	for (i = 0; i < N; i++) {
		scanf("%d", &a);
		arr.push_back(a);
	}
	RMQ rmq(arr);
	for (i = 0; i < M + K; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) {
			rmq.update(b-1, c);
		}
		else {
			printf("%lld\n",rmq.query(b-1, c-1));
		}
	}
	return 0;
}