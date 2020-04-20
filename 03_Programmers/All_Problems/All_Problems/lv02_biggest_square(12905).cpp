#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board){
	int answer = 0;
	int N =board.size();
	int M = board[0].size();

	if (M < 2 || N < 2) {					// 가로,세로 중 하나라도 1이면 커봐야 1
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 1)
					answer = 1;
			}
		}
	}
	else {
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < M; j++) {
				if (board[i][j] == 1) {
					board[i][j] = min({ board[i][j - 1], board[i - 1][j], board[i - 1][j - 1] }) + 1;
					answer = max(answer, board[i][j]);
				}
			}
		}
	}
	answer *= answer;
	return answer;
}
int main() {
	cout << solution({ {0, 1, 1, 1},{1, 1, 1, 1},{1, 1, 1, 1},{0, 0, 1, 0} }) << endl;
	/*
		0111
		1122
		1223
		0010
	*/
	return 0;
}