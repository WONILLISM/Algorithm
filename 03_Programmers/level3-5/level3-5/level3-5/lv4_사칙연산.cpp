#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int dp[203][203];
int solution(vector<string> arr){
	int len = arr.size();
	for (int i = 0; i < len; ++i)
		dp[i][i] = stoi(arr[i]);
	
	for (int i = 2; i < len; i += 2) {
		for (int j = 0; j + i < len; j += 2) {
			int M, m;
			for (int k = j + 1; k < i + j; k += 2) {
				M = dp[j][k - 1] + dp[k - 1][j];
			}
		}
	}
	
}
int main() {
	vector<string> a = { "1", "-", "3","+", "5", "-", "8" };
	cout << solution(a) << endl;
	return 0;
}