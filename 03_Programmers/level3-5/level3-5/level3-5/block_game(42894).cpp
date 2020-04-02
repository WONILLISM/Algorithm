#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#define PII pair<int,int>

using namespace std;

vector<vector<int>> map;
bool isPossibleB(int y, int x) {	// ����� ����Ʈ�� �� �ִ��� Ȯ�� ( ���� �� ��� ���� �׻� 0 )
	for (int i = 0; i < y; i++) {
		if (map[i][x]) return false;
	}
	return true;
}
bool findBlocks(int y, int x, int h, int w) {
	int empty_b = 0; // �� ������ �ִ� 2�� 
	int block_n = -1; // ���������� ���� ���� ��ȣ 

	for (int i = y; i < y + h; i++) {
		for (int j = x; j < x + w; j++) {
			if (!map[i][j]) {
				if (!isPossibleB(i, j)) {	// Ž���� �� ���� ���� �����Ѵٸ�
					return false;
				}
				empty_b++;
				if (empty_b > 2) return false;
			}
			else {
				if (block_n != -1 && block_n != map[i][j]) {// �ٸ� ����� ���� ��
					return false;
				}
				block_n = map[i][j];
			}
		}
	}
	// �� ����
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
		//���� �ѹ��� Ž���� �ؾ��Ѵ�. 
		//������ ����� 1���� ������ �� �ݺ��Ѵ�. 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				//���ΰ� 3, ���ΰ� 2�� �� 
				if (i <= n - 2 && j <= n - 3 && findBlocks(i, j, 2, 3)) {
					cnt++;
				}
				//���ΰ� 2, ���ΰ� 3�� �� 
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