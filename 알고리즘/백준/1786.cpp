#pragma warning(disable:4996)
#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define MAX 1000005
//char T[MAX];
//char P[MAX];
string T;
string P;
//N���� �ڱ� �ڽ��� ã���鼭 ��Ÿ���� �κ� ��ġ�� �̿��� pi[]�� ���
//pi[i]=N[..i]�� ���̻絵 �ǰ� ���λ絵 �Ǵ� ���ڿ��� �ִ� ����
vector<int> getPartialMatch(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);
	//KMP�� �ڱ� �ڽ��� ã�´�
	//N�� N���� ã�´�. begin=0�̸� �ڱ� �ڽ��� ã�ƹ����ϱ� �ȵ�
	int begin = 1;
	int matched = 0;
	//���� ���ڰ� N�� ���� ������ ������ ã���鼭 �κ� ��ġ�� ��� ����Ѵ�
	while (begin + matched < m) {
		if (N[begin + matched] == N[matched]) {
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				++begin;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

//T�� �κ� ���ڿ��� P�� �����ϴ� ���� ��ġ���� ��� ��ȯ�Ѵ�
vector<int> kmpSearch(const string &H, const string& N) {
	int n = H.size(), m = N.size();
	vector<int> ret;

	//pi[i]=N[..i]�� ���̻絵 �ǰ� ���λ絵 �Ǵ� ���ڿ��� �ִ� ����
	vector<int> pi = getPartialMatch(N);
	//begin=matched=0���� ���� ����
	int begin = 0, matched = 0;
	while (begin<=n-m)
	{
		if (matched < m && T[begin + matched] == N[matched]) {
			++matched;
			//��������� m���ڰ� ��� ��ġ �ߴٸ� �信 �߰��Ѵ�
			if (matched == m) ret.push_back(begin);
		}
		else {
			if (matched != 0) {
				begin += matched - pi[matched - 1];
				//begin�� �Ű�ٰ� ó������ �ٽ� ���� �ʿ䰡 ����
				//�ű� �Ŀ��� pi[matched-1]��ŭ�� �׻� ��ġ�ϱ� ����
				matched = pi[matched - 1];
			}
			else begin++;
		}
	}
	return ret;
}
int main(void)
{
	getline(cin, T);
	getline(cin, P);
	vector<int> answer=kmpSearch(T, P);
	printf("%d\n", answer.size());
	for (int i = 0; i < answer.size(); i++) printf("%d ", answer[i]+1);
	return 0;
}
