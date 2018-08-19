#pragma warning(disable:4996)
#include<stdio.h>
#include<math.h>


/*
0~19 �������� ������ �ϴ� ���� 

���� ����
int fullpizza(1<<20)-1;

���� �߰�
toppings |= (1<<p);

���� ���� ����
if(toppings & (1<<p))
->&���� ������� 0 �Ǵ� 1<<p, �� ���� ó�� 1�̳� true�� ��ȯ�ȴٰ� �����ϸ� �ȵ�
->if((toppings & (1<<p))==1) �� �ڵ�� ���� ����

���� ����
toppings &=~(1<<p);

���� ���
toppings ^=(1<<p);

���� ũ�� ���ϱ�
int bitCount(int x){
	if(x==0) return 0;
	return x%2 + bitCount(x/2);
}
*/



//�ִ� 100�� ���� ã�ƺ���
#define MAX_N 1000000
int N, M;

//�迭 �ϳ��� ���� 8���� ǥ���� �� �����ϱ� 
//0~7 8~15 �̷��� ǥ���ϴϱ� +7�ؼ� /8�� ���� ������ ���°� �迭 ũ�� ���� ����
unsigned char sieve[(MAX_N + 7) / 8];
//k�� �Ҽ����� Ȯ��
inline bool isPrime(int k) {
	return sieve[k >> 3] & (1 << (k & 7));
}
//k�� �Ҽ��� �ƴ϶�� ǥ��
inline void setComposite(int k) {
	//4�� ��� �迭 8ĭ�� ���, k/8��° ������ k%8��° ��Ʈ�� ���� �ִ��� ���� ���� ������ ����.
	sieve[k >> 3] &= ~(1 << (k & 7));
}
void eratosthenes() {
	//0�� 1�� �Ҽ� �ƴ϶�� ����ó��
	setComposite(0);
	setComposite(1);
	//n������ �Ҽ� ���� �� � �� m=ab ��� a�� b�� ��� �ϳ��� ��Ʈn�����̴�
	//�� n���� ���� �ռ��� m�� ��Ʈn���� ���� ���� ����� üũ�ص� �������ٴ� �ǹ�
	int sqrtn = int(sqrt(M));
	for (int i = 2; i <= sqrtn; i++) {
		if (isPrime(i)) {//�� ���� ���� �������� �ʾҴٸ�
			//i*i�̸��� ����� �̹� ���������Ƿ� �Ű澲�� �ʴ´�
			for (int j = i * i; j <= M; j += i) setComposite(j);
		}
	}
}
int main() {
	int i,j;
	scanf("%d %d", &N, &M);

	//��� �迭�� 255�� �ʱ�ȭ 255�� ��Ʈ�� 1111 1111 �� ���� 
	//���� ���� 8���� �迭 �Ѱ��� �˻縦 �ϴµ� �Ҽ��� �ƴҰ�� ~�������� 0���� ����
	for (i = 0; i < (MAX_N + 7) / 8; i++) sieve[i] = 255;
	eratosthenes();

	for (i = N/8; i < M / 8+1; i++) {
		for (j = 0; j < 8; j++) {
			if (i == N / 8 && j < N % 8) continue;
			if (i == M/8 && j > M % 8) break;
			if (sieve[i] & (1 << j)) printf("%d\n",i*8+j);
		}
	}
	return 0;
}