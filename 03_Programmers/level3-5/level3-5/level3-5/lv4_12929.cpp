#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;
const int MAX = 15;
int dp[MAX];

int process(int n) {
	if (n == 0)return dp[n] = 1;
	if (n == 1)return dp[n] = 1;
	if (dp[n])return dp[n];
	else {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			int k = n - j - 1;
			sum += process(j) * process(k);
		}
		dp[n] = sum;
		return dp[n];
	}
}
int solution(int n) {
	process(n);
	return dp[n];
}
int main() {
	cout << solution(4) << endl;
	return 0;
}
