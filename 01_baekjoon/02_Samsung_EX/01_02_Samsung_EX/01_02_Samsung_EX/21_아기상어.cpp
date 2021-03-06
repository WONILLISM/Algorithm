#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int MAX = 20;
int N, ans;
int Size, cntEat;
int Map[MAX][MAX];
int Visit[MAX][MAX];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
typedef struct Shark{
	int x, y, d;
	//Min heap 움직인 거리(d) > y > x
	bool operator < (const Shark &t)const {
		if (d == t.d) {
			if (y == t.y)return x > t.x;
			else return y > t.y;
		}
		else return d > t.d;
	}
};
priority_queue<Shark> pQ;
void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 9) {
				pQ.push({ j,i,0 });
				Map[i][j] = 0;
			}
		}
	}
}
void Init(int &curd) {
	curd = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Visit[i][j] = 0;
		}
	}
	while (!pQ.empty())pQ.pop();
}
void Process() {
	while (!pQ.empty()) {
		int curx = pQ.top().x;
		int cury = pQ.top().y;
		int curd = pQ.top().d;
		pQ.pop();
		// 만약 물고기의 사이즈가 상어보다 크다면 못먹는다
		if (Map[cury][curx] > 0 && Map[cury][curx] < Size) {
			// 물고기 먹은 횟수 계산
			Map[cury][curx] = 0;
			cntEat++;
			// 먹은 횟수 = 현재 상어 사이즈 이면 상어 사이즈 증가
			if (cntEat == Size) {
				Size++;
				cntEat = 0;
			}
			ans += curd;

			// 초기화
			Init(curd);
		}
		for (int i = 0; i < 4; i++) {
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (ny >= 0 && nx >= 0 && ny < N&&nx < N) {
				//Size보다 작거나 같아야만 상어는 이동할 수 있다.
				if (!Visit[ny][nx]&&Map[ny][nx]<=Size) {
					pQ.push({ nx,ny,curd + 1 });
					Visit[ny][nx] = 1;
				}
			}
		}
	}
}
void Solution() {
	Input();
	Size = 2;
	Process();
	cout << ans << "\n";
}
int main() {
	freopen("21.in", "r", stdin);
	Solution();
	return 0;
}