#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

const int MAX = 101;
//R연산 모든 행에 대해서 정렬 수행
//C연산 모든 열에 대해서 정렬 수행
//N >= M일때에는 R연산
//N < M 일때에는 C연산
int r, c, k;
int Map[MAX][MAX];
int Num[MAX];
int N = 3, M = 3;
void Input() {
	cin >> r >> c >> k;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> Map[i][j];
		}
	}
}
void Process() {
	for (int t = 0; t < MAX; t++) {
		if (Map[r][c] == k) {
			cout << t << "\n";
			return;
		}
		if (N >= M) {
			for (int i = 1; i <= N; i++) {
				priority_queue<pair<int, int>> pq;
				for (int j = 0; j < MAX; j++)Num[j] = 0;
				for (int j = 1; j <= M; j++) {
					if (Map[i][j]) {
						Num[Map[i][j]] += 1;
						Map[i][j] = 0;
					}
				}
				for (int j = 1; j <= 100; j++)
					if (Num[j])pq.push({ -Num[j],-j });
				int len = pq.size() * 2;
				M = max(M, len);
				for (int j = 1; j <= len; j += 2) {
					Map[i][j] = -pq.top().second;
					Map[i][j + 1] = -pq.top().first;
					pq.pop();
				}
			}
		}
		else {
			for (int j = 1; j <= M; j++) {
				priority_queue<pair<int, int>> pq;
				for (int i = 0; i < MAX; i++)Num[i] = 0;
				for (int i = 1; i <= N; i++) {
					if (Map[i][j]) {
						Num[Map[i][j]] += 1;
						Map[i][j] = 0;
					}
				}
				for (int i = 1; i <= 100; i++)
					if (Num[i])pq.push({ -Num[i],-i });
				int len = pq.size() * 2;
				N = max(N, len);
				for (int i = 1; i <= len; i += 2) {
					Map[i][j] = -pq.top().second;
					Map[i + 1][j] = -pq.top().first;
					pq.pop();
				}
			}
		}
	}
	cout << "-1\n";
}
void Solution() {
	Input();
	Process();
}
int main() {
	freopen("24.in", "r", stdin);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Solution();
	return 0;
}