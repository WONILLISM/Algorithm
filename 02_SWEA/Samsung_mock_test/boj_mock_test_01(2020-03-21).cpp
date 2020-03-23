#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
#define PII pair<int,int>
using namespace std;

const int MAX = 40;
int N, M, K; 
int Map[MAX][MAX];
int Tmp[MAX][MAX];
int answer = 0;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

vector<vector<int>> piece[100];

// 시계 방향 회전
vector<vector<int>> rotate(vector<vector<int>> &a) {
	vector<vector<int>> tmp(a[0].size(), vector<int>(a.size(), 0));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[i].size(); j++) {
			tmp[j][i] = a[a.size() - 1 - i][j];
		}
	}
	return tmp;
}

bool process(int y, int x,int ans,vector<vector<int>> tmp) {
	
	for (int i = 0; i < tmp.size(); i++) {
		for (int j = 0; j < tmp[i].size(); j++) {
			if (Map[y + i][x + j] == 1 && tmp[i][j] == 1) 
				return false;
		}
	}
	for (int i = 0; i < tmp.size(); i++) {
		for (int j = 0; j < tmp[i].size(); j++) {
			if (Map[y + i][x + j] == 0 && tmp[i][j] == 1) {
				ans++;
				Map[y + i][x + j] = 1;
			}
		}
	}
	answer += ans;
	return true;
}
bool c = false;
void solution(int k, int ans) {
	if (k == K) {
		c = true;
		return;
	}
	vector<vector<int>> tmp = piece[k];
	answer = ans;
	bool chk = false;
	for (int d = 0; d < 4; d++) {
		int r = tmp.size();
		int c = tmp[0].size();
		for (int i = 0; i < N - r + 1; i++) {
			for (int j = 0; j < M - c + 1; j++) {
				chk =process(i, j, 0, tmp);
				if (c)return;
				if (chk) {
					solution(k + 1, answer);
				}
			}
		}
		
		tmp = rotate(tmp);
		if(d==3)solution(k + 1, answer);
	}
	
}

void input() {
	cin >> N >> M >> K;
	for (int k = 0; k < K; k++) {
		int r, c; cin >> r >> c;
		piece[k].assign(r, vector<int>(c, 0));
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> piece[k][i][j];
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("test01.in", "r", stdin);
	
	input();
	
	solution(0, 0);
	cout << answer << endl;

	return 0;
}