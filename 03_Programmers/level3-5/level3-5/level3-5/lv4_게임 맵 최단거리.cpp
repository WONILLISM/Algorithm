#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int ans, N, M;
int visit[100][100];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
struct Pos { int x, y, step; };
int solution(vector<vector<int> > maps){
	N = maps.size(), M = maps[0].size();
	queue<Pos> q;
	Pos cur = { 0,0,1 };
	visit[cur.y][cur.x] = 1;
	q.push(cur);
	while (!q.empty()) {
		cur = q.front(); q.pop();
		if (cur.y == N - 1 && cur.x == M - 1)return ans = cur.step;
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i], ny = cur.y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < M&&ny < N) {
				if (maps[ny][nx] && !visit[ny][nx]) {
					visit[ny][nx] = cur.step + 1;
					q.push({ nx,ny,cur.step + 1 });
				}
			}
		}
	}
	return -1;
}
int main() {
	vector<vector<int>> m = {
		{1, 0, 1, 1, 1},
		{1, 0, 1, 0, 1},
		{1, 0, 1, 1, 1},
		{1, 1, 1, 0, 1},
		{0, 0, 0, 0, 1} };
	cout << solution(m) << endl;
	return 0;
}