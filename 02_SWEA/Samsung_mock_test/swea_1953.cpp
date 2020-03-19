#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
#define PII pair<int,int>
using namespace std;

const int MAX = 51;
int N, M, r, c, L, answer;
int Map[MAX][MAX];
int visit[MAX][MAX];
// ╩С ©Л го аб
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
vector<vector<int>> dir = {
	{},
	{0,1,2,3},	// ╩С го аб ©Л
	{0,2},		// ╩С го
	{1,3},		// ©Л аб
	{0,1},		// ╩С ©Л
	{1,2},		// ©Л го
	{2,3},		// го аб
	{0,3}		// ╩С аб
};
void solution() {
	queue<PII> q;	// yабг╔ xабг╔
	q.push({ r,c });
	visit[r][c] = 1;

	while (!q.empty()) {
		PII cur = q.front();
		int step = visit[cur.first][cur.second];
		q.pop();
		int type = Map[cur.first][cur.second];
		for (int i = 0; i < dir[type].size(); i++) {
			int d = dir[type][i];
			int ny = cur.first + dy[d];
			int nx = cur.second + dx[d];


			if (ny >= 0 && ny < N&&nx >= 0 && nx < M) {
				bool chk = false;
				int nType = Map[ny][nx];
				int nStep = step + 1;
				for (int j = 0; j < dir[nType].size(); j++) {
					if (dir[nType][j] == (d + 2) % 4) {
						chk = true;
					}
				}
				if (!visit[ny][nx] && chk&&nStep <= L) {
					visit[ny][nx] = nStep;
					q.push({ ny,nx });
					answer++;
				}
			}
		}
	}
}
void input() {
	cin >> N >> M >> r >> c >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc; cin >> tc;

	for (int t = 1; t <= tc; t++) {
		answer = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visit[i][j] = 0;
				Map[i][j] = 0;
			}
		}
		input();
		solution();
		cout << "#" << t << " " << answer << endl;
	}
	return 0;
}