#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> T;
int dp[500][500];
int Max;
//n:높이 idx: 높이의 행
int process(int n,int idx) {
	if (idx < 0)return 0;
	if (n == 0)return dp[0][0] = T[0][0];

	if (dp[n][idx])return dp[n][idx];
	else {
		int a = process(n - 1, 0);
		for (int i = 0; i <=n; i++) {
			//int b = process(n - 1, i - 1);
			if (i == 0) {
				dp[n][i] = a + T[n][i];
			}
			else if(i>0&&i<n){
				int b = process(n - 1, i);
				int c = a > b ? a : b;
				dp[n][i] = c + T[n][i];
				a = b;
			}
			else if (i == n) {
				dp[n][i] = a + T[n][i];
			}
			if (Max < dp[n][i])Max = dp[n][i];
		}
		return dp[n][idx];
	}
}
int solution(vector<vector<int>> triangle) {
	T = triangle;
	process(triangle.size() - 1, 0);
	int answer = Max;
	return answer;
}
int main() {
	vector<vector<int>> t;
	t.push_back({ 7 });
	t.push_back({ 3,8 });
	t.push_back({ 8,1,0 });
	t.push_back({ 2,7,4,4 });
	t.push_back({ 4,5,2,6,5 });
	cout << solution(t) << endl;
	return 0;
}