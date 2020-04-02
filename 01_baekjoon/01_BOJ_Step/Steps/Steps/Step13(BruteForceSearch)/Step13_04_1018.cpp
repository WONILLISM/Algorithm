#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<algorithm>
#define endl '\n';
#define ll long long
#define PII pair<int,int>

using namespace std;

const int MAX = 51;
char board[MAX][MAX];
int visit[MAX][MAX];
int N, M, sx, sy, ans = 32;

int dx[] = { 1,0 }, dy[] = { 0,1 };

string white[8] = {
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" }
};
string black[8] = {
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" }
};
void process(int y, int x) {
	int cntW = 0, cntB = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (white[i][j] != board[y + i][x + j])cntW++;
			if (black[i][j] != board[y + i][x + j])cntB++;
		}
	}
	ans = min(ans, min(cntW,cntB));
}
void solution() {
	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			process(i, j);
		}
	}
	cout << ans << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> board[i];
	solution();
	return 0;
}