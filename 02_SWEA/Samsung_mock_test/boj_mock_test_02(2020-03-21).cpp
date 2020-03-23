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

const int MAX = 50;
int N, M, G, R;
int Map[MAX][MAX];
char visit[MAX][MAX];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int answer = 0;
//0È£¼ö 1x 2o
vector<pair<PII, char>> able;
queue<pair<PII, char>> q;

bool isRange(int y, int x) { return y >= 0 && y < N&&x >= 0 && x < M; }
int process() {	
	int ans = 0;
	while (!q.empty()) {
		PII cur = q.front().first;
		char ample = q.front().second;
		q.pop();



		for (int i = 0; i < 4; i++) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (Map[ny][nx] && isRange(ny,nx)) {
				if (visit[ny][nx] != 'b') {
					if (visit[ny][nx] == 'x') {
						q.push({ { ny,nx }, ample });
						visit[ny][nx] = ample;
					}
					else if (visit[ny][nx] != ample) {
						visit[ny][nx] = 'b';
						ans++;
					}
				}
			}
		}
	}
	return ans;
}
void solution() {
	if (R == 0 && G == 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visit[i][j] = 'x';
			}
		}
		for (int i = 0; i < able.size(); i++) {
			q.push(able[i]);
			int y = able[i].first.first;
			int x = able[i].first.second;
			visit[y][x] = able[i].second;
		}
		answer = max(process(), answer);
		return;
	}
	for (int i = 0; i < able.size(); i++) {
		if (able[i].second == 'x') {
			if (R) {
				R--;
				able[i].second = 'r';
				solution();
				able[i].second = 'x';
				R++;
			}
			if (G) {
				G--;
				able[i].second = 'g';
				solution();
				able[i].second = 'x';
				G++;
			}
		}
	}
}
int main() {
	cin >> N >> M >> G >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 2)
				able.push_back({ { i,j }, 'x' });
			visit[i][j] = 'x';
		}
	}
	solution();
	cout << answer << endl;
	return 0;
}