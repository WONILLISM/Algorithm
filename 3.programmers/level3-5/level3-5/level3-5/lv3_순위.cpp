#include<iostream>
#include <string>
#include <vector>
using namespace std;

int Score[101][101];
int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	vector<vector<int>> score(n + 1, vector<int>(n + 1, 0));

	for (int i = 0; i < results.size(); i++)
	{
		Score[results[i][0]][results[i][1]]++;
		Score[results[i][1]][results[i][0]]--;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (Score[i][k]!=0) {
				for (int j = 1; j <= n; j++) {
					if (Score[i][k] == Score[k][j]) {
						Score[i][j] = Score[i][k];
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++)
			if ((Score[i][j] != 0) && (i != j))sum++;
		if (sum == n - 1)answer++;
	}
	return answer;
}
int main() {
	vector<vector<int>> r = { {4,3},{4,2},{3,2},{1,2},{2,5} };
	cout << solution(5, r) << endl;
	return 0;
}