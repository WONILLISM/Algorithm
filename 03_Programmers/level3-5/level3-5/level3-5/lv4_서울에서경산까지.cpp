#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int dp[100000];
int solution(int K, vector<vector<int>> travel) {
	int answer = 0;
	for (int i = 0; i < travel.size(); i++) {
		for (int j = K; j >= 0; j--) {
			dp[j] = -123456789;
			if (j >= travel[i][0])
				dp[j] = max(dp[j], dp[j - travel[i][0]] + travel[i][1]);
			if (j >= travel[i][2])
				dp[j] = max(dp[j], dp[j - travel[i][2]] + travel[i][3]);
		}
	}
	return dp[K];
}
int main() {
	vector<vector<int>> travel = { {500, 200, 200, 100},
								   {800, 370, 300, 120},
								   {700, 250, 300, 90 } };
	cout << solution(1650, travel) << endl;
	return 0;
}