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

const int MAX = 1001;
int N, M, K, ans;
int Map[MAX][MAX];

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
struct Cell {
	int y, x, life;
};
vector<Cell> v;

bool cmp(Cell a, Cell b) { return a.life > b.life; }
void solution() {
	int time = 0;
	ans = 0;
	while (time != K) {
		int size = v.size();
		sort(v.begin(), v.end(), cmp);
		for (int i = 0; i < size; i++) {
			Cell cur = v[i];

			if (cur.life == Map[cur.y][cur.x] / 2) {// 활성화 상태
				for (int d = 0; d < 4; d++) {
					int ny = cur.y + dy[d], nx = cur.x + dx[d];
					if (!Map[ny][nx]) {				// 다음 공간이 비어있다면
						Map[ny][nx] = Map[cur.y][cur.x];		// 번식
						v.push_back({ ny,nx,Map[cur.y][cur.x] });	// 번식한 세포 추가
					}
				}
			}
			cur.life--;	// 생명력 감소
			if (!cur.life) {
				Map[cur.y][cur.x] = -1;	// 죽은 세포
				//v.erase(v.begin() + i);
				cur.life = -1;
				v[i] = cur;
			}
			else v[i] = cur;
		}
		vector<Cell> tmp = v;
		v.clear();
		for (int i = 0; i < tmp.size(); i++) {
			if (tmp[i].life != -1)v.push_back(tmp[i]);
		}
		time++;
	}
	for (auto a : v) {
		if (a.life != -1)ans++;
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	freopen("swea_5653.in", "r", stdin);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> N >> M >> K;
		fill(&Map[0][0], &Map[MAX][MAX], 0);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int l; cin >> l;
				if (l) {
					int y = i + MAX/2, x = j + MAX/2;
					Map[y][x] = l * 2;
					v.push_back({ y,x,l * 2 });
				}
			}
		}
		solution();
		cout << "#" << t << " " << ans << endl;
	}
	return 0;
}