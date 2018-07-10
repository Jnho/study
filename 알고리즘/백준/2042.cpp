#pragma warning(disable:4996)
#include <stdio.h>
#include<vector>
using namespace std;

#define MAX 1000005
int N, M, K;
vector <long long>arr;
struct RMQ { //Range minimum query
	//배열의 길이
	int n;
	//각 구간의 최소치
	vector<long long> rangeMin;
	RMQ(const vector<long long>& array) {
		n = array.size();
		rangeMin.resize(n * 4);
		init(array, 0, n - 1, 1);
	}
	//node 노드가 array[left..right]배열을 표현할 때
	//node를 루트로 하는 서브트리를 초기화하고 이 구간의 합을 반환한다
	long long init(const vector<long long>& array, int left, int right, int node) {
		if (left == right)
			return rangeMin[node] = array[left];
		int mid = (left + right) / 2;
		long long leftMin = init(array, left, mid, node * 2);
		long long rightMin = init(array, mid + 1, right, node * 2 + 1);
		return rangeMin[node] = leftMin + rightMin;
	}

	//node가 표현하는 범위 array[nodeLeft..nodeRight]가 주어질 때
	//이 범위와 array[left..right]의 교집합의 합을 구한다.
	long long query(int left, int right, int node, int nodeLeft, int nodeRight) {

		//두 구간이 겹치지 않으면 0 반환
		if (right < nodeLeft || nodeRight < left) return 0;

		//node가 표현하는 범위가 array[left..right]에 완전히 포함되는 경우
		if (left <= nodeLeft && nodeRight <= right)
			return rangeMin[node];

		//양쪽 구간을 나눠서 푼 뒤 결과를 합친다
		int mid = (nodeLeft + nodeRight) / 2;
		long long a = query(left, right, node * 2, nodeLeft, mid);
		long long b = query(left, right, node * 2 + 1, mid + 1, nodeRight);
		return a + b;
	}
	//query를 외부에서 호출하기 위한 인터페이스
	long long query(int left, int right) {
		return query(left, right, 1, 0, n - 1);
	}

	//array[index]=newValue로 바뀌었을 때 node를 루트로 하는 
	//구간 트리를 갱신하고 노드가 표현하는 구간의 최소치를 반환한다
	long long update(int index, int newValue, int node, int nodeLeft, int nodeRight) {

		//index가 노드가 표현하는 구간과 상관없는 경우엔 무시한다
		if (index < nodeLeft || nodeRight < index)
			return rangeMin[node];
		//트리의 리프까지 내려온 경우
		if (nodeLeft == nodeRight) return rangeMin[node] = newValue;
		int mid = (nodeLeft + nodeRight) / 2;
		long long a = update(index, newValue, node * 2, nodeLeft, mid);
		long long b = update(index, newValue, node * 2 + 1, mid + 1, nodeRight);
		return rangeMin[node]=a + b;
	}
	//update를 외부에서 호출하기 위한 인터페이스
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