#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, a[21][21], p[22][22] = { 0 };

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			p[i][j] = p[i][j - 1] + p[i - 1][j] - p[i - 1][j - 1] + a[i][j];
		}
	}

	int mn = 1e9;
	for (int d1 = 1; d1 < n; d1++) {
		for (int d2 = 1; d2 < n - d1; d2++) {
			for (int x = d1 + 1; x <= n - d2; x++) {
				for (int y = 1; y <= n - d1 - d2; y++) {
					//1,1~ 
					int area1 = p[y + d1 - 1][x];

					int area2 = p[y + d2][n] - p[y + d2][x];

					int area3 = p[n][x - d1 + d2 - 1] - p[y + d1 - 1][x - d1 + d2 - 1];

					int area4 = p[n][n] - p[n][x - d1 + d2 - 1] - p[y + d2][n] + p[y + d2][x - d1 + d2 - 1];

					int dsum1 = 0, dsum2 = 0, dsum3 = 0, dsum4 = 0;

					for (int i = 0; i < d1; i++) {
						for (int j = 0; j <= i; j++) {
							dsum1 += a[y + i][x - j];
							dsum4 += a[y + d1 + d2 - i][x - d1 + d2 + j];
						}
					}
					for (int i = 0; i < d2; i++) {
						for (int j = 0; j <= i; j++) {
							dsum2 += a[y + 1 + i][x + 1 + j];
							dsum3 += a[y + d1 + d2 - 1 - i][x - d1 + d2 - 1 - j];
						}
					}

					area1 -= dsum1;
					area2 -= dsum2;
					area3 -= dsum3;
					area4 -= dsum4;
					int area5 = p[n][n] - (area1 + area2 + area3 + area4);
					int arr[5] = { area1,area2,area3,area4,area5 };
					sort(arr, arr + 5);

					mn = min(mn, arr[4] - arr[0]);
				}
			}
		}
	}
	cout << mn << '\n';
}