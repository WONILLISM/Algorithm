#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
#define ll long long
using namespace std;
int Apart[15][15];
void solution_2775();
int main() {
	solution_2775();
	return 0;
}
void solution_2775() {
	int t, k, n;
	scanf("%d", &t);
	for (int i = 0; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			if (i == 0)Apart[i][j] = j;
			if (i >= 1)Apart[i][j] += Apart[i - 1][j] + Apart[i][j-1];
		}
	}
	while (t--) {
		int sum = 0;
		scanf("%d %d", &k, &n);
		printf("%d\n", Apart[k][n]);

	}
}