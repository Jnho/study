#pragma warning(disable:4996)

#include<stdio.h>

int main(void)
{
	int i, j, cnt = 0, f = 0, ex = -1;
	char str[55];
	int alp[26] = { 0, };

	scanf("%s", str);

	//전체 개수, 각 알파벳 개수 세기
	for (i = 0; str[i] != '\0'; i++)
	{
		cnt++;
		alp[str[i] - 65]++;
	}

	//홀수 두개인 경우 찾기, 홀수 한개인 경우 ex에 인덱스 저장
	for (i = 0; i < 26; i++) {
		if (alp[i] % 2 == 1) {
			f++;
			ex = i;
		}
	}
	if (f > 1) printf("I'm Sorry Hansoo");
	else {
		//앞에 반틈 출력
		for (i = 0; i < 26; i++) {
			for (j = 0; j < alp[i] / 2; j++) printf("%c", i + 65);
		}
		//홀수 일 경우만 출력
		if (ex != -1) printf("%c", ex + 65);
		//뒤 반틈 출력
		for (i = 25; i >= 0; i--) {
			for (j = 0; j < alp[i] / 2; j++) printf("%c", i + 65);
		}
	}
	return 0;
}


