#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

int dp[21];
int process(int n) {
	if (n == 0)return dp[0];
	if (n == 1)return dp[1] = 1;
	if (dp[n])return dp[n];
	else {
		dp[n] = process(n - 1) + process(n - 2);
		return dp[n];
	}
}
void solution_10870() {
	int n;
	scanf("%d", &n);
	printf("%d\n", process(n));
}
int main() {
	solution_10870();
	return 0;
}