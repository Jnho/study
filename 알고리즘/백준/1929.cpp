#pragma warning(disable:4996)
#include<stdio.h>
#include<math.h>


/*
0~19 스무가지 토핑을 하는 피자 

꽉찬 집합
int fullpizza(1<<20)-1;

원소 추가
toppings |= (1<<p);

원소 포함 여부
if(toppings & (1<<p))
->&연산 결과값은 0 또는 1<<p, 논리 연산 처럼 1이나 true가 반환된다고 생각하면 안됨
->if((toppings & (1<<p))==1) 이 코드는 동작 안함

원소 삭제
toppings &=~(1<<p);

원소 토글
toppings ^=(1<<p);

집합 크기 구하기
int bitCount(int x){
	if(x==0) return 0;
	return x%2 + bitCount(x/2);
}
*/



//최대 100만 까지 찾아보자
#define MAX_N 1000000
int N, M;

//배열 하나로 숫자 8개씩 표현할 수 있으니까 
//0~7 8~15 이렇게 표현하니까 +7해서 /8로 만든 개수는 딱맞게 배열 크기 선언 가능
unsigned char sieve[(MAX_N + 7) / 8];
//k가 소수인지 확인
inline bool isPrime(int k) {
	return sieve[k >> 3] & (1 << (k & 7));
}
//k가 소수가 아니라고 표시
inline void setComposite(int k) {
	//4일 경우 배열 8칸을 사용, k/8번째 원소의 k%8번째 비트가 켜져 있는지 보고 켜져 있으면 끈다.
	sieve[k >> 3] &= ~(1 << (k & 7));
}
void eratosthenes() {
	//0과 1은 소수 아니라고 예외처리
	setComposite(0);
	setComposite(1);
	//n까지의 소수 구할 때 어떤 수 m=ab 라면 a와 b중 적어도 하나는 루트n이하이다
	//즉 n보다 작은 합성수 m은 루트n보다 작은 수의 배수만 체크해도 지워진다는 의미
	int sqrtn = int(sqrt(M));
	for (int i = 2; i <= sqrtn; i++) {
		if (isPrime(i)) {//이 수가 아직 지워지지 않았다면
			//i*i미만의 배수는 이미 지워졌으므로 신경쓰지 않는다
			for (int j = i * i; j <= M; j += i) setComposite(j);
		}
	}
}
int main() {
	int i,j;
	scanf("%d %d", &N, &M);

	//모든 배열을 255로 초기화 255는 비트로 1111 1111 인 상태 
	//이제 숫자 8개를 배열 한개로 검사를 하는데 소수가 아닐경우 ~연산으로 0으로 만듬
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