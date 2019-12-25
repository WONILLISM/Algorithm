#include<iostream>
using namespace std;

int N, K, ans = 1 << 30;
int coin[10][2];
void Input() {
	cin >> N >> K;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> coin[i][0];
	}
}
void Process(int i,int res) {
	int s = res + coin[i][0];
	coin[i][1] += 1;
	if (K > s)Process(i, s);
	else if (K == s) {
		int cnt=0;
		for (int i = 0; i < N; i++) {
			cnt += coin[i][1];
		}
		if (ans >= cnt)ans = cnt;
	}
	else {
		coin[i][1] -= 1;
		Process(i - 1, res);
	}
}
void Solution() {
	Input();
	Process(N - 1, 0);
	cout << ans << endl;
}
int main() {
	Solution();
	return 0;
}