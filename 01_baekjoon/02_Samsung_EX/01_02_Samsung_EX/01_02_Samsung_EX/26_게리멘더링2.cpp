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
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//#define PII pair<int,int>
//
//using namespace std;
//
//const int MAX = 20;
//
//int N;
//int A[MAX][MAX];
//int visit[MAX][MAX];
//int area[5];
//
//int process(int y, int x, int d1, int d2) {
//	fill(&visit[0][0], &visit[MAX - 1][MAX], 0);
//	vector<int> v;
//	int sx = x;	//start x
//	int cnt = 1;
//	int a1 = y + min(d1, d2);
//	int a2 = y + max(d1, d2);
//	int a3 = y + d1 + d2;
//
//	for (int i = y; i <= a1; i++) {
//		for (int j = sx; j < sx + cnt; j++) {
//			visit[i][j] = 5;
//		}
//		if (i != a1) {
//			sx--;
//			cnt += 2;
//		}
//	}
//	cout << endl;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cout << visit[i][j] << " ";
//		}
//		cout << endl;
//	}
//
//	for (int i = a1 + 1; i <= a2; i++) {
//		if (d1 >= d2) {
//			sx--;
//			for (int j = sx; j < sx + cnt; j++) {
//				visit[i][j] = 5;
//			}
//		}
//		else {
//			sx++;
//			for (int j = sx; j < sx + cnt; j++) {
//				visit[i][j] = 5;
//			}
//		}
//	}
//	cout << endl;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cout << visit[i][j] << " ";
//		}
//		cout << endl;
//	}
//	for (int i = a2 + 1; i <= a3; i++) {
//		cnt -= 2;
//		sx++;
//		for (int j = sx; j < sx + cnt; j++) {
//			visit[i][j] = 5;
//		}
//	}
//	cout << endl;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cout << visit[i][j] << " ";
//		}
//		cout << endl;
//	}
//	fill(area, area + 5, 0);
//	cout << endl;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (i < y + d1 && j <= x) visit[i][j] = (visit[i][j] == 0 ? 1 : visit[i][j]);
//			if (i <= y + d2 && j > x) visit[i][j] = (visit[i][j] == 0 ? 2 : visit[i][j]);
//			if (i >= y + d1 && j < x + (d2 - d1)) visit[i][j] = (visit[i][j] == 0 ? 3 : visit[i][j]);
//			if (i > y + d2 && j >= x + (d2 - d1)) visit[i][j] = (visit[i][j] == 0 ? 4 : visit[i][j]);
//			cout << visit[i][j] << " ";
//			area[visit[i][j] - 1] += A[i][j];
//		}
//		cout << endl;
//	}
//	sort(area, area + 5);
//	return area[4] - area[0];
//}
//int solution() {
//	int ans = 1 << 30;
//	// 사각형 만들기
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			// 선거구 나누는 방법 1. d1, d2 ≥ 1, 1 ≤ x < x+d1+d2 ≤ N, 1 ≤ y-d1 < y < y+d2 ≤ N
//			for (int d1 = 1; d1 < N; d1++) {	// d1의 길이 
//				for (int d2 = 1; d2 < N; d2++) {	// d2의 길이
//					if (i + d1 + d2 < N&&j - d1 >= 0 && j + d2 < N) {	
//						cout << "___________START __________\n";
//						ans = min(ans, process(i, j, d1, d2));
//					}
//				}
//			}
//		}
//	}
//
//	return ans;
//}
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> A[i][j];
//		}
//	}
//	cout << solution() << endl;
//}