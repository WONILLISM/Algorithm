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

const int MAX = 4001;
int Map[MAX][MAX];
int ans;
int dx[] = { 0,0,1,-1 };// 상하좌우
int dy[] = { 1,-1,0,0 };
struct Atom {
	int x, y, dir, k;		// 원자의 위치, 방향, 보유 에너지
	bool chk;
};
vector<Atom> atom;

bool isRange(int y, int x) { return x >= 0 && x <= 4000 && y >= 0 && y <= 4000; }
void solution() {
	while (!atom.empty()) {
		for (int i = 0; i < atom.size(); i++) {
			int dir = atom[i].dir;
			int cury = atom[i].y, curx = atom[i].x;
			int ny = atom[i].y + dy[dir], nx = atom[i].x + dx[dir];

			if (isRange(ny, nx)) {
				atom[i].y = ny;
				atom[i].x = nx;
				Map[ny][nx] += atom[i].k;
				//Map[cury][curx] = 0;
			}
			else atom[i].k = 0;// 다음 좌표가 범위를 벗어나면 원자 소멸
		}
		for (int i = 0; i < atom.size(); i++) {
			int cury = atom[i].y, curx = atom[i].x;
			if (atom[i].k != 0) {								// 소멸되지 않은 원자라면
				if (Map[cury][curx] != atom[i].k) {			// 충돌 검사
					ans += Map[cury][curx];
					Map[cury][curx] = 0;
					//atom.erase(atom.begin() + i);
					atom[i].k = 0;
				}
			}
		}
		for (int i = 0; i < atom.size(); i++) {
			if (atom[i].k == 0)
				atom.erase(atom.begin() + i);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("swea_5648.in", "r", stdin);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int n; cin >> n;
		while (n--) {
			int x, y, dir, k;
			cin >> x >> y >> dir >> k;
			x += 1000, y += 1000;	//-1000 ~ 1000의 범위를 -2000 ~ 2000 범위로 맵핑
			x *= 2, y *= 2;
			atom.push_back({ x,y,dir,k, false });
		}
		ans = 0;
		solution();
		cout << "#" << t << " " << ans << endl;
	}
	return 0;
}