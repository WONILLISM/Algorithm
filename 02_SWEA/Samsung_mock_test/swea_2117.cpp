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

const int MAX = 21;
int Map[MAX][MAX];
int visit[MAX][MAX];
int ans, N, M;
int cost[22];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

queue<PII> q;	//y,x
//bfs
void process(int y, int x) {
	int k = 1;
	q.push({ y, x });
	visit[y][x] = 1;

	int map = Map[y][x];
	while (k <= N+1) {
		if (((map * M) - cost[k]) >= 0) {	// 이익이 발생하면 최대 이익 계산
			ans = max(ans, map);
			
		}
		
		// bfs의 성질을 이용한 마름모 처리
		int size = q.size();	
		for (int i = 0; i < size; i++) {
			int cury = q.front().first, curx = q.front().second;
			q.pop();
			for (int d = 0; d < 4; d++) {
				int ny = cury + dy[d], nx = curx + dx[d];
				if (ny >= 0 && ny < N&&nx >= 0 && nx < N && !visit[ny][nx]) {
					visit[ny][nx] = 1;
					q.push({ ny,nx });
					if (Map[ny][nx] == 1) {
						map++;
					}
				}
			}
		}
		k++;
	}
	while (!q.empty()) {
		q.pop();
	}
}
void solution() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fill(&visit[0][0], &visit[N][N], 0);
			//for (int a = 0; a < N; a++)
			//	for (int b = 0; b < N; b++)
			//		visit[a][b] = 0;
			process(i, j);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("swea_2117.in", "r", stdin);
	//freopen("swea_2117.out", "w", stdout);
	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> N >> M;
		ans = -1;
		//모든 운영비용 계산
		for (int k = 1; k <= MAX; k++)
			cost[k] = k * k + (k - 1)*(k - 1);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> Map[i][j];
			}
		}
		solution();
		cout << "#" << t << " " << ans << endl;
	}
	return 0;
}