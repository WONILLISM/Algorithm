#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n'
#define ll long long
#define PII pair<int,int>
using namespace std;

int N, W, H, answer;
int Map[15][12];

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
bool check[12];

queue<pair<PII, int>> q;	// x, y, dist

void copy_map(int (*from)[12], int (*to)[12]) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			to[i][j] = from[i][j];
		}
	}
}
// 벽돌 정리
void after_process() {
	for (int i = 0; i < W; i++) {
		for (int j = H - 1; j >= 1; j--) {
			for (int k = j - 1; k >= 0; k--) {
				if (Map[j][i])break;
				if (!Map[j][i] && Map[k][i]) {
					Map[j][i] = Map[k][i];
					Map[k][i] = 0;
					break;
				}
			}
		}
	}
}
// 벽돌 파괴
void process(int x, int y) {
	if (!Map[y][x])return;
	int dist = Map[y][x];
	Map[y][x] = 0;
	for (int i = 0; i < dist; i++) {
		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d] * i;
			int nx = x + dx[d] * i;
			if (ny >= 0 && ny < H &&nx >= 0 && nx < W && Map[ny][nx]) {
				process(nx, ny);
			}
		}
	}
}

void solution(int n) {
	// tmp 초기화
	int tmp[15][12] = { 0, };

	// 맵 복제 (Map => tmp)
	copy_map(Map, tmp);

	// 모든 공을 다 뿌렸으면
	if (n == N) {
		int cnt = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (Map[i][j])cnt++;
			}
		}
		answer = min(answer, cnt);
		return;
	}
	// 공 뿌릴 위치
	for (int i = 0; i < W; i++) {
		int y = 0, x = i;
		//벽돌이 있는 위치까지 탐색
		while ((x >= 0 && x < W && y >= 0 && y < H)&&!Map[y][x])
			y++;
		process(x, y);
		after_process();
		solution(n + 1);
		// 맵 복제 (tmp => Map)
		copy_map(tmp, Map);

	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("swea_5656.in", "r", stdin);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> N >> W >> H;
		answer = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> Map[i][j];
				if (Map[i][j])answer++;
			}
		}
		solution(0);
		cout << "#" << t << " " << answer << endl;
	}
	return 0;
}