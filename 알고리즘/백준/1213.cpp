#pragma warning(disable:4996)

#include<stdio.h>

int main(void)
{
	int i, j, cnt = 0, f = 0, ex = -1;
	char str[55];
	int alp[26] = { 0, };

	scanf("%s", str);

	//��ü ����, �� ���ĺ� ���� ����
	for (i = 0; str[i] != '\0'; i++)
	{
		cnt++;
		alp[str[i] - 65]++;
	}

	//Ȧ�� �ΰ��� ��� ã��, Ȧ�� �Ѱ��� ��� ex�� �ε��� ����
	for (i = 0; i < 26; i++) {
		if (alp[i] % 2 == 1) {
			f++;
			ex = i;
		}
	}
	if (f > 1) printf("I'm Sorry Hansoo");
	else {
		//�տ� ��ƴ ���
		for (i = 0; i < 26; i++) {
			for (j = 0; j < alp[i] / 2; j++) printf("%c", i + 65);
		}
		//Ȧ�� �� ��츸 ���
		if (ex != -1) printf("%c", ex + 65);
		//�� ��ƴ ���
		for (i = 25; i >= 0; i--) {
			for (j = 0; j < alp[i] / 2; j++) printf("%c", i + 65);
		}
	}
	return 0;
}


