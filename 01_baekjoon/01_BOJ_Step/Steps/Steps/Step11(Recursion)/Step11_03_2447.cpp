#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

int N;
void process(int n, int x, int y) {
	if ((x / n) % 3 == 1 && (y / n) % 3==1)printf(" ");
	else {
		if (n / 3 == 0)printf("*");
		else process(n / 3, x, y);
	}
}
void solution_2447() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			process(N,i, j);
		}
		printf("\n");
	}
}
int main() {
	solution_2447();
	return 0;
}

//
//const int MAX = 6561;//3^8
//int n;
//char star[MAX][MAX];
//void init() {
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			star[i][j] = ' ';
//}
//void stamp(int n, int x, int y) {
//	if (n == 1) {
//		star[y][x] = '*';
//		return;
//	}
//	int div = n / 3;
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			if (i != 1 || j != 1) {
//				stamp(div, x + div * i, y + div * j);
//			}
//		}
//	}
//	return;
//}
//int main() {
//	scanf("%d", &n);
//	init();
//	stamp(n, 0, 0);
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			printf("%c", star[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}