#include<iostream>

using namespace std;

int N, M;
char d[17];

void solution(int i, int cnt) {
	if (cnt == M) {
		d[cnt * 2 - 1] = '\n';
		cout << d;
		return;
	}
	for (int j = i; j <= N; j++) {
		d[cnt * 2] = j + '0';
		d[cnt * 2 + 1] = ' ';
		solution(j, cnt + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	solution(1, 0);
	return 0;
}