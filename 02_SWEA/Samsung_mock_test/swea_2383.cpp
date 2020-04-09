#include<iostream>
#include<vector>
#include<queue>
#define PII pair<int,int>
using namespace std;

const int MAX = 10;
int N;
int board[MAX][MAX];
vector<PII> people;
vector<PII> stair;
int s[10];
int ans;
int siz;
int calc() {
	int t = 0;
	int chk = 0;
	int d[10];
	queue<int> c[2];

	for (int i = 0; i < siz; i++) {
		d[i] = abs(people[i].first - stair[s[i]].first) + abs(people[i].second - stair[s[i]].second);
	}

	while (1) {
		if (t >= ans) return t;
		if (chk == siz) return t;
		for (int i = 0; i < 2; i++) {//계단에 들어간 인원
			int ss = c[i].size();
			for (int j = 0; j < ss; j++) {
				int top = c[i].front();
				c[i].pop();
				top--;
				if (top != 0)
					c[i].push(top);
				else {
					chk++;
				}
			}
		}
		for (int i = 0; i < siz; i++) {//입구에 도착한 인원
			if (t == d[i]) {
				if (c[s[i]].size() < 3)//계단 입구 도착시 아무도 없다면
					c[s[i]].push(board[stair[s[i]].first][stair[s[i]].second]);
				else {
					c[s[i]].push(board[stair[s[i]].first][stair[s[i]].second] + c[s[i]].front());
				}
			}
		}
		t++;
	}
}

void solution(int cnt) {
	if (cnt == people.size()) {
		int tmp = calc();
		if (ans > tmp) ans = tmp;
		return;
	}
	s[cnt] = 0; 
	solution(cnt + 1);
	s[cnt] = 1; 
	solution(cnt + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("swea_2383.in", "r", stdin);

	int tc;
	cin >> tc;
	for (int t = 1; t<= tc; t++) {
		cin >> N;
		people.clear();
		stair.clear();
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) people.push_back({ i,j });	// 사람 저장
			else if (board[i][j] > 1) stair.push_back({ i,j });  // 계단 저장
		}
		siz = people.size();
		ans = 1 << 30;;
		solution(0);
		cout << "#" << t << ' ' << ans << '\n';

	}
	return 0;
}