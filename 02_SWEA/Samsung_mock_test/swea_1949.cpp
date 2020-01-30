#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define endl "\n"
using namespace std;

const int MAX = 8;

int Map[MAX][MAX];
bool visit[MAX][MAX];
int N, K, maxHeight, ans;
//struct Pos { int x, y; };
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

// dfs
void process(int x, int y, int len, bool isK) {
	ans = max(ans, len);
	//Pos cur = { x,y };
	for (int i = 0; i < 4; ++i) {
		//int nx = cur.x + dx[i], ny = cur.y + dy[i];
		int nx = x + dx[i], ny = y + dy[i];

		if (nx >= 0 && nx < N&&ny >= 0 && ny < N) {
			// 내리막길
			//if (Map[cur.y][cur.x] > Map[ny][nx])
			if (!visit[ny][nx]) {
				if (Map[y][x] > Map[ny][nx]) {
					visit[ny][nx] = true;
					process(nx, ny, len + 1, isK);
					visit[ny][nx] = false;
				}
				// 내리막길 x , 공사 안함
				//else if (Map[cur.y][cur.x] <= Map[ny][nx] && !isK)
				else if (Map[y][x] <= Map[ny][nx] && !isK) {
					//공사 진행
					for (int dig = 1; dig <= K; ++dig) {
						isK = true;
						Map[ny][nx] -= dig;
						//if (Map[cur.y][cur.x] > Map[ny][nx])
						if (Map[y][x] > Map[ny][nx]) {
							visit[ny][nx] = true;
							process(nx, ny, len + 1, isK);
							visit[ny][nx] = false;
						}
						Map[ny][nx] += dig;
						isK = false;
					}
				}
			}
		}
	}
}
void solution() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (maxHeight == Map[i][j]) {
				visit[i][j] = true;
				process(j, i, 1, false);
				visit[i][j] = false;
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	freopen("swea_1949.in", "r", stdin);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		/*---- Init ----*/
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				Map[i][j] = 0;
				visit[i][j] = false;
			}
		}
		ans = 1;
		maxHeight = 0;
		/*---- Init ----*/

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> Map[i][j];
				maxHeight = max(maxHeight, Map[i][j]);
			}
		}
		solution();
		cout << "#" << tc << " " << ans << endl;
	}

	return 0;
}
