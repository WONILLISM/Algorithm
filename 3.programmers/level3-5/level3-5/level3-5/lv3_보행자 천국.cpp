#include<iostream>
#include <vector>
using namespace std;

int MOD = 20170805;
int rDp[501][501];
int dDp[501][501];
int solution(int m, int n, vector<vector<int>> city_map) {
	for (int y = 1; y <= m; y++) {
		for (int x = 1; x <= n; x++) {
			int type = city_map[y - 1][x - 1];
			if ((x == 1) && (y == 1)) {
				rDp[x][y] = 1;
				dDp[x][y] = 1;
			}
			else if (type == 0) {
				rDp[y][x] = (rDp[y][x - 1] + dDp[y - 1][x]) % MOD;
				dDp[y][x] = (rDp[y][x - 1] + dDp[y - 1][x]) % MOD;
			}
			else if (type == 1) {
				rDp[y][x] = 0;
				dDp[y][x] = 0;
			}
			else if (type == 2) {
				rDp[y][x] = rDp[y][x - 1];
				dDp[y][x] = dDp[y - 1][x];
			}
		}
	}
	return rDp[m][n];
}
int main() {
	vector<vector<int>> cm = { {0, 2, 0, 0, 0, 2},{0, 0, 2, 0, 1, 0},{1, 0, 0, 2, 2, 0 } };
	cout << solution(3, 6, cm);
	return 0;
}