#include<iostream>
#include <deque>
using namespace std;

int N, M, K, ans;
int a[10][10];	//겨울마다 추가되는 양분
int nutrient[10][10]; //누적 맵 정보
deque<int> tree[10][10];
const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void Input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
			nutrient[i][j] = 5;
		}
	}
	//나무가 있는 위치에 나무의 나이를 저장
	//deque으로 만들었기 때문에 같은 위치에 있는 나무가 추가된다.
	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tree[x - 1][y - 1].push_back(z);
		ans++;
	}
}
void spring_summer() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {			
			for (int k = 0; k < (int)tree[i][j].size(); k++) {
				//나무가 양분을 먹을 수 있으면
				if (nutrient[i][j] >= tree[i][j][k]) { // Spring
					nutrient[i][j] -= tree[i][j][k];
					tree[i][j][k]++;
				}
				//나무가 양분을 먹을 수 없으면
				else { // Summer
					while (k < tree[i][j].size()) {
						nutrient[i][j] += (tree[i][j].back() / 2);
						tree[i][j].pop_back();
						ans--;
					}
					break;
				}
			}
		}
	}
}

void fall_winter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < (int)tree[i][j].size(); k++) {
				if (tree[i][j][k] % 5 == 0) { // Fall
					for (int t = 0; t < 8; t++) {
						int x = i + dx[t], y = j + dy[t];
						if (x < 0 || x >= N || y < 0 || y >= N) continue;
						tree[x][y].push_front(1);
						ans++;
					}
				}
			}
			nutrient[i][j] += a[i][j]; // Winter
		}
	}
}

void Solution() {
	Input();
	while (K--) {
		spring_summer();
		fall_winter();
	}
	cout << ans << "\n";
}

int main() {
	freopen("20.in", "r", stdin);
	Solution();
	return 0;
}

