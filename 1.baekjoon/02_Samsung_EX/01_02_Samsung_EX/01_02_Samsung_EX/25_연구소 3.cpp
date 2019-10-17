#include<iostream>
#include<queue>
using namespace std;
const int MAX = 50;
int N, M, k, Answer = 1 << 30;
int Map[MAX][MAX];
int Step[MAX][MAX];
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,-1,0,1 };
//좌표, 활성상태
vector<pair<pair<int, int>, bool>> virus;
//좌표(x,y)
queue<pair<int, int>> Q;
void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 2) virus.push_back({ {j, i}, false });
			if (Map[i][j] == 0)k += 1;
		}
	}
}
//빈칸 0 벽 1 비활성화 바이러스 2 활성화 바이러스 3

void Process() {
	int time = 0, a = 0;
	while (!Q.empty()) {
		int curx = Q.front().first;
		int cury = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (ny >= 0 && nx >= 0 && ny < N&&nx < N) {
				if (Map[ny][nx] != 1 && Step[ny][nx] == -1) {
					Step[ny][nx] = Step[cury][curx] + 1;
					if (Map[ny][nx] == 0) {
						a += 1;
						time = Step[ny][nx];
					}
					Q.push({ nx,ny });
				}
			}
		}
	}
	if (a == k && Answer > time)Answer = time;
}
void ActVirus(int idx, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				Step[i][j] = -1;
			}
		}
		for (int i = 0; i < virus.size(); i++) {
			if (virus[i].second) {
				Q.push({ virus[i].first.first, virus[i].first.second });
				Step[virus[i].first.second][virus[i].first.first] = 0;
			}
		}
		Process();
		return;
	}
	for (int i = idx; i < virus.size(); i++) {
		if (!virus[i].second) {
			virus[i].second = true;
			ActVirus(i+1, cnt + 1);
			virus[i].second = false;
		}
	}
}
void Solution() {
	Input();
	ActVirus(0, 0);
	if (Answer == 1 << 30)cout << "-1" << "\n";
	else cout << Answer << "\n";
}
int main() {
	freopen("25.in", "r", stdin);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Solution();
	return 0;
}