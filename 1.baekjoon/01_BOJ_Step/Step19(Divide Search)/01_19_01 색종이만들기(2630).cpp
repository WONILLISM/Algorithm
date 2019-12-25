#include<iostream>

using namespace std;
const int MAX = 128;
int N;
int Map[MAX][MAX];
int white, blue;

void process(int n,int x, int y) {
	if (Map[y][x] == -1)return;
	if (n == 1) {
		if (Map[y][x])blue++;
		else white++;
		Map[y][x] = -1;
		return;
	}
	else {
		bool chk = false;
		int cur, next;
		cur = Map[y][x];
		for (int i = y; i < y + n; i++) {
			chk = false;
			for (int j = x; j < x + n; j++) {
				next = Map[i][j];
				if (cur != next) {
					chk = true;
					break;
				}
			}
			if (chk)break;
		}
		if (!chk) {
			if (cur == 1)blue++;
			else white++;
			for (int i = y; i < y + n; i++) {
				for (int j = x; j < x + n; j++) {
					Map[i][j] = -1;
				}
			}
		}
	}
	int div = n / 2;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			process(div, x + div * i, y + div * j);
		}
	}
}
void solution() {
	process(N, 0, 0);
	cout << white << endl << blue << endl;
}
int main() {
	freopen("01.in", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> Map[i][j];
	solution();
	return 0;
}
