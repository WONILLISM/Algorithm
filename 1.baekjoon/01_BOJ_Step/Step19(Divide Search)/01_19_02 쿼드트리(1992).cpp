#include<iostream>
#include<string>
using namespace std;
const int MAX = 65;
int N;
char Map[MAX][MAX];
string Ans;
void process(int n, int x, int y) {
	bool chk = false;
	if (Map[x][y] == '-')return;
	else {
		char cur, next;
		cur = Map[x][y];
		for (int i = y; i < y + n; i++) {
			chk = false;
			for (int j = x; j < x + n; j++) {
				next = Map[j][i];
				if (cur != next) {
					chk = true;
					break;
				}
			}
			if (chk)break;
		}
		if (!chk) {
			if (cur == '1') {
				Ans.push_back('1');
			}
			else if (cur == '0') {
				Ans.push_back('0');
			}
			for (int i = y; i < y + n; i++) {
				for (int j = x; j < x + n; j++) {
					Map[j][i] = '-';
				}
			}
		}
		else {
			int div = n / 2;
			int cnt = 0;
			Ans.push_back('(');
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					process(div, x + div * i, y + div * j);
				}
			}
			Ans.push_back(')');
		}
		if (n == 1)return;
	}
}
void solution() {
	process(N, 0, 0);
	for (int i = 0; i < Ans.size(); i++)
		cout << Ans[i];
}
int main() {
	freopen("02.in", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Map[i];
	solution();
	return 0;
}
