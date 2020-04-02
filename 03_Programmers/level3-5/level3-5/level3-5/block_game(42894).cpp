#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#define PII pair<int,int>

using namespace std;

vector<vector<int>> map;
bool isPossibleB(int y, int x) {	// 블록을 떨어트릴 수 있는지 확인 ( 가능 한 블록 위는 항상 0 )
	for (int i = 0; i < y; i++) {
		if (map[i][x]) return false;
	}
	return true;
}
bool findBlocks(int y, int x, int h, int w) {
	int empty_b = 0; // 빈 공간은 최대 2개 
	int block_n = -1; // 마지막으로 만난 블럭의 번호 

	for (int i = y; i < y + h; i++) {
		for (int j = x; j < x + w; j++) {
			if (!map[i][j]) {
				if (!isPossibleB(i, j)) {	// 탐색할 블럭 위에 블럭이 존재한다면
					return false;
				}
				empty_b++;
				if (empty_b > 2) return false;
			}
			else {
				if (block_n != -1 && block_n != map[i][j]) {// 다른 모양의 블럭일 때
					return false;
				}
				block_n = map[i][j];
			}
		}
	}
	// 블럭 삭제
	for (int i = y; i < y + h; i++) {
		for (int j = x; j < x + w; j++) {
			map[i][j] = 0;
		}
	}
	return true;
}
int solution(vector<vector<int>> board) {
	int answer = 0;
	int n = board.size();
	map = board;
	int cnt;
	while(1) {
		cnt = 0;
		//최초 한번은 탐색을 해야한다. 
		//지워질 블록이 1개라도 존재할 때 반복한다. 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				//가로가 3, 세로가 2인 블럭 
				if (i <= n - 2 && j <= n - 3 && findBlocks(i, j, 2, 3)) {
					cnt++;
				}
				//가로가 2, 세로가 3인 블럭 
				else if (i <= n - 3 && j <= n - 2 && findBlocks(i, j, 3, 2)) {
					cnt++;
				}
			}
		}
		if (!cnt)break;
		answer += cnt;
	}

	return answer;
}

int main() {
	cout << solution({
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 4, 0, 0, 0},
		{0, 0, 0, 0, 0, 4, 4, 0, 0, 0},
		{0, 0, 0, 0, 3, 0, 4, 0, 0, 0},
		{0, 0, 0, 2, 3, 0, 0, 0, 5, 5},
		{1, 2, 2, 2, 3, 3, 0, 0, 0, 5},
		{1, 1, 1, 0, 0, 0, 0, 0, 0, 5} }) << endl;
	return 0;
}