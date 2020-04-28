#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<int> Stack;
	for (auto col : moves) {
		for (int i = 0; i < board.size(); i++) {
			int tmp = board[i][col - 1];
			if (tmp) {
				board[i][col - 1] = 0;
				if (!Stack.empty() && Stack.back()==tmp) {
					Stack.pop_back();
					answer += 2;	
				}
				else Stack.push_back(tmp);
				break;
			}
		}
	}
	return answer;
}
int main() {
	vector<vector<int>> b = {{0, 0, 0, 0, 0}, 
							 {0, 0, 1, 0, 3}, 
							 {0, 2, 5, 0, 1}, 
							 {4, 2, 4, 4, 2}, 
							 {3, 5, 1, 3, 1}};
	cout << solution(b, { 1,5,3,5,1,2,1,4 }) << endl;
	return 0;
}