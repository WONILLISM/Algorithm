#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
#define ll long long
using namespace std;

bool Num[10001];
int A, B;
void GoldBach(int a,int b) {
	A = a;
	B = b;
	if (!Num[A] && !Num[B])return;
	GoldBach(a - 1, b + 1);
}
void PrimeNum() {
	Num[0] = true;
	Num[1] = true;
	for (int i = 2; i <= 10000; i++)
		for (int j = 2; i*j <= 10000; j++)
			if (!Num[i*j])Num[i*j] = true;
}
void solution_9020() {
	int t;
	scanf("%d", &t);
	PrimeNum();
	while (t--) {
		int n;
		scanf("%d", &n);
		A = n / 2;
		B = n / 2;
		GoldBach(A, B);
		printf("%d %d\n", A, B);
	}
}
int main() {
	solution_9020();
	return 0;
}
