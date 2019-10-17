#include<iostream>
#include<queue>
using namespace std;

const int MAX_N = 20;

int N, Answer;
int Map[MAX_N][MAX_N];

void Init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
		}
	}
}
void Move(int dir) {
	queue<int> q;
	if (dir == 0) {
		for (int i = 0, idx = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (Map[i][j]) q.push(Map[i][j]);
				Map[i][j] = 0;
			}
			idx = 0;
			while (!q.empty()) {
				int x = q.front();
				q.pop();

				if (!Map[i][idx])Map[i][idx] = x;
				else if (Map[i][idx] == x) {
					Map[i][idx] *= 2;
					idx++;
				}
				else {
					idx++;
					Map[i][idx] = x;
				}
			}
		}
	}
	else if (dir == 1) {
		for (int i = 0, idx = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				if (Map[i][j]) q.push(Map[i][j]);
				Map[i][j] = 0;
			}
			idx = N - 1;
			while (!q.empty()) {
				int x = q.front();
				q.pop();

				if (!Map[i][idx])Map[i][idx] = x;
				else if (Map[i][idx] == x) {
					Map[i][idx] *= 2;
					idx--;
				}
				else {
					idx--;
					Map[i][idx] = x;
				}
			}
		}
	}
	else if (dir == 2) {
		for (int i = 0, idx = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (Map[j][i]) q.push(Map[j][i]);
				Map[j][i] = 0;
			}
			idx = 0;
			while (!q.empty()) {
				int x = q.front();
				q.pop();

				if (!Map[idx][i])Map[idx][i] = x;
				else if (Map[idx][i] == x) {
					Map[idx][i] *= 2;
					idx++;
				}
				else {
					idx++;
					Map[idx][i] = x;
				}
			}
		}
	}
	else if (dir == 3) {
		for (int i = 0, idx = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				if (Map[j][i]) q.push(Map[j][i]);
				Map[j][i] = 0;
			}
			idx = N - 1;
			while (!q.empty()) {
				int x = q.front();
				q.pop();

				if (!Map[idx][i])Map[idx][i] = x;
				else if (Map[idx][i] == x) {
					Map[idx][i] *= 2;
					idx--;
				}
				else {
					idx--;
					Map[idx][i] = x;
				}
			}
		}
	}
}

void Process(int n) {
	int tmp[MAX_N][MAX_N];
	if (n == 5) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				Answer = max(Answer, Map[i][j]);
		return;
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			tmp[i][j] = Map[i][j];
	
	for (int d = 0; d < 4; d++) {
		Move(d);
		Process(n + 1);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				Map[i][j] = tmp[i][j];
	}
}
void Solution() {
	Init();
	Process(0);
	cout << Answer << endl;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	freopen("02.in", "r", stdin);
	Solution();
	return 0;
}