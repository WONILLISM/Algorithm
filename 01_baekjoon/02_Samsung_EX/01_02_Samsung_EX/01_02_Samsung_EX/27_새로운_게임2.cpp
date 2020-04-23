#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm>
#define PII pair<int,int>

using namespace std;

const int MAX = 13;

int N, K;
int Map[MAX][MAX];		// 1:빨간색(모든 순서 바꿈), 2:파란색(방향 전환 후 한 칸)
struct Pos { int y, x, dir; };
Pos piece[MAX];
deque<int> deq[MAX][MAX];	// 해당 좌표의 체스 말 순서

int dy[] = { 0,0,0,-1,1 };
int dx[] = { 0,1,-1,0,0 };


bool isRanged(int y, int x) { return y > 0 && x > 0 && y <= N && x <= N; }
int solution() {
	int turn = 1;

	while (turn <= 1000) {
		for (int i = 1; i <= K; i++) {
			int curx = piece[i].x, cury = piece[i].y;
			int curdir = piece[i].dir;

			int ny = cury + dy[curdir], nx = curx + dx[curdir];

			if (!isRanged(ny, nx) || Map[ny][nx] == 2) {
				int d = piece[i].dir;
				piece[i].dir += d % 2 == 0 ? -1 : 1;
				curdir = piece[i].dir;
				ny = cury + dy[curdir], nx = curx + dx[curdir];
				if (isRanged(ny, nx) && Map[ny][nx] != 2) {
					if (Map[ny][nx] == 0) {
						deque<int> tmp;
						while (1) {
							int a = deq[cury][curx].back();
							deq[cury][curx].pop_back();
							piece[a].y = ny;
							piece[a].x = nx;
							tmp.push_back(a);
							if (i == a)break;
						}
						while (!tmp.empty()) {
							int a = tmp.back();
							tmp.pop_back();
							deq[ny][nx].push_back(a);
							if (deq[ny][nx].size() >= 4)return turn;
						}
					}
					else if (Map[ny][nx] == 1) {
						while (1) {
							int a = deq[cury][curx].back();
							deq[cury][curx].pop_back();
							piece[a].y = ny;
							piece[a].x = nx;
							deq[ny][nx].push_back(a);
							if (deq[ny][nx].size() >= 4)return turn;
							if (i == a)break;
						}
					}
				}
			}
			else {
				if (Map[ny][nx] == 0) {
					deque<int> tmp;
					while (1) {
						int a = deq[cury][curx].back();
						deq[cury][curx].pop_back();
						piece[a].y = ny;
						piece[a].x = nx;
						tmp.push_back(a);
						if (i == a)break;
					}
					while (!tmp.empty()) {
						int a = tmp.back();
						tmp.pop_back();
						deq[ny][nx].push_back(a);
						if (deq[ny][nx].size() >= 4)return turn;
					}

				}
				else if (Map[ny][nx] == 1) {
					while (1) {
						int a = deq[cury][curx].back();
						deq[cury][curx].pop_back();
						piece[a].y = ny;
						piece[a].x = nx;
						deq[ny][nx].push_back(a);
						if (deq[ny][nx].size() >= 4)return turn;
						if (i == a)break;
					}
				}
			}
		}
		turn++;
	}

	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("27.in", "r", stdin);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int a; cin >> a;
			Map[i][j] = a;
		}
	}
	for (int i = 1; i <= K; i++) {
		int y, x, dir;
		cin >> y >> x >> dir;
		piece[i] = { y,x,dir };
		deq[y][x].push_back(i);
	}
	cout << solution() << endl;

	return 0;
}