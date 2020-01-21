#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

const int MAX = 1000000;
int n, ans;
int process(int m) {
	int sum = m;
	while (m != 0) {
		int r = m % 10;
		sum += r;
		m /= 10;
	}
	return sum;
}
void solution_2231() {
	scanf("%d", &n);
	for (int i = 1; i<=MAX; i++) {
		if (process(i) == n) {
			printf("%d\n", i);
			return;
		}
	}
	printf("0\n");
}
int main() {
	solution_2231();
	return 0;
}
