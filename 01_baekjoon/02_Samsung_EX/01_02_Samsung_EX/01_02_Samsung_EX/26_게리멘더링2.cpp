#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define PII pair<int,int>

using namespace std;

const int MAX = 20;

int N;
int A[MAX][MAX];
int visit[MAX][MAX];
int area[5];

int process(int y, int x, int d1, int d2) {
	fill(&visit[0][0], &visit[MAX - 1][MAX], 0);
	vector<int> v;
	int sx = x;	//start x
	int cnt = 1;
	int a1 = y + min(d1, d2);
	int a2 = y + max(d1, d2);
	int a3 = y + d1 + d2;

	for (int i = y; i <= a1; i++) {
		for (int j = sx; j < sx + cnt; j++) {
			visit[i][j] = 5;
		}
		if (i != a1) {
			sx--;
			cnt += 2;
		}
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visit[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = a1 + 1; i <= a2; i++) {
		if (d1 >= d2) {
			sx--;
			for (int j = sx; j < sx + cnt; j++) {
				visit[i][j] = 5;
			}
		}
		else {
			sx++;
			for (int j = sx; j < sx + cnt; j++) {
				visit[i][j] = 5;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visit[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = a2 + 1; i <= a3; i++) {
		cnt -= 2;
		sx++;
		for (int j = sx; j < sx + cnt; j++) {
			visit[i][j] = 5;
		}
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visit[i][j] << " ";
		}
		cout << endl;
	}
	fill(area, area + 5, 0);
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i < y + d1 && j <= x) visit[i][j] = (visit[i][j] == 0 ? 1 : visit[i][j]);
			if (i <= y + d2 && j > x) visit[i][j] = (visit[i][j] == 0 ? 2 : visit[i][j]);
			if (i >= y + d1 && j < x + (d2 - d1)) visit[i][j] = (visit[i][j] == 0 ? 3 : visit[i][j]);
			if (i > y + d2 && j >= x + (d2 - d1)) visit[i][j] = (visit[i][j] == 0 ? 4 : visit[i][j]);
			cout << visit[i][j] << " ";
			area[visit[i][j] - 1] += A[i][j];
		}
		cout << endl;
	}
	sort(area, area + 5);
	return area[4] - area[0];
}
int solution() {
	int ans = 1 << 30;
	// 사각형 만들기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// 선거구 나누는 방법 1. d1, d2 ≥ 1, 1 ≤ x < x+d1+d2 ≤ N, 1 ≤ y-d1 < y < y+d2 ≤ N
			for (int d1 = 1; d1 < N; d1++) {	// d1의 길이 
				for (int d2 = 1; d2 < N; d2++) {	// d2의 길이
					if (i + d1 + d2 < N&&j - d1 >= 0 && j + d2 < N) {	
						cout << "___________START __________\n";
						ans = min(ans, process(i, j, d1, d2));
					}
				}
			}
		}
	}

	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	cout << solution() << endl;
}