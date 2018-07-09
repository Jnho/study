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
//N에서 자기 자신을 찾으면서 나타나는 부분 일치를 이용해 pi[]를 계산
//pi[i]=N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이
vector<int> getPartialMatch(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);
	//KMP로 자기 자신을 찾는다
	//N을 N에서 찾는다. begin=0이면 자기 자신을 찾아버리니까 안됨
	int begin = 1;
	int matched = 0;
	//비교할 문자가 N의 끝에 도달할 때까지 찾으면서 부분 일치를 모두 기록한다
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

//T의 부분 문자열로 P가 출현하는 시작 위치들을 모두 반환한다
vector<int> kmpSearch(const string &H, const string& N) {
	int n = H.size(), m = N.size();
	vector<int> ret;

	//pi[i]=N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이
	vector<int> pi = getPartialMatch(N);
	//begin=matched=0에서 부터 시작
	int begin = 0, matched = 0;
	while (begin<=n-m)
	{
		if (matched < m && T[begin + matched] == N[matched]) {
			++matched;
			//결과적으로 m글자가 모두 일치 했다면 답에 추가한다
			if (matched == m) ret.push_back(begin);
		}
		else {
			if (matched != 0) {
				begin += matched - pi[matched - 1];
				//begin을 옮겼다고 처음부터 다시 비교할 필요가 없다
				//옮기 후에도 pi[matched-1]만큼은 항상 일치하기 때문
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
