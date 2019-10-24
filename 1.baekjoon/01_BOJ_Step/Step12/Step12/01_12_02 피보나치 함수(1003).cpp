#include<iostream>
using namespace std;
int N, T;
int dp[41];

//0 1 1 2 3 5 8 
void Input() {
	cin >> T;
}
long Process(int n) {
	if (n == 0) {
		dp[n] = 0;
		return dp[n];
	}
	else if (n == 1) {
		dp[n] = 1;
		return dp[n];
	}
	if (dp[n]) {
		return dp[n];
	}
	else {
		dp[n] = Process(n - 1) + Process(n - 2);
		return dp[n];
	}
}
void Solution() {
	Input();
	while (T--) {
		cin >> N;
		for (int i = 0; i < 41; i++)dp[i] = 0;
		Process(N);
		if (N == 0)cout << "1 0\n";
		else if (N == 1)cout << "0 1\n";
		else cout << dp[N - 1] << " " << dp[N] << "\n";
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Solution();
	return 0;
}