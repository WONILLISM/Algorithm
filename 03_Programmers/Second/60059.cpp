#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	int m = key.size(), n = lock.size();
	int kcnt = 0, lcnt = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (lock[i][j] == 0)lcnt++;
	//rotate
	for (int r = 0; r < 4; r++) {
		//lock
		for (int ly = -m; ly <= n; ly++) {
			for (int lx = -m; lx <= n; lx++) {
				//key
				bool chk = true;
				kcnt = 0;
				for (int ky = 0; ky < m; ky++) {
					for (int kx = 0; kx < m; kx++) {
						int ny = ky + ly, nx = kx + lx;
						if (ny >= 0 && nx >= 0 && ny < n&&nx < n) {
							if (key[ky][kx] == 1 && lock[ny][nx] == 1) 
								chk = false;
							else if (key[ky][kx] == 1 && lock[ny][nx] == 0)kcnt++;
						}
					}
				}
				if (lcnt == kcnt && chk)return true;
			}
		}
		vector<vector<int>> tmp(m, vector<int>(m, 0));
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				tmp[j][m - i - 1] = key[i][j];
		key = tmp;
	}
	return false;
}
int main() {
	vector<vector<int>> key = { {0, 0, 0}, {1, 0, 0}, {0, 1, 1} };
	vector<vector<int>> lock = { {1, 1, 1}, {1, 1, 0}, {1, 0, 1} };
	cout << solution(key, lock) << endl;
	return 0;
}

//cout << "key" << endl;
//for (int i = 0; i < m; i++) {
//	for (int j = 0; j < m; j++) {
//		cout << key[i][j];
//	}
//	cout << endl;
//}
//cout << endl;
//cout << "lock" << endl;
//for (int i = 0; i < n; i++) {
//	for (int j = 0; j < n; j++) {
//		cout << lock[i][j];
//	}
//	cout << endl;
//}
//cout << endl;