#include<iostream>
#include<algorithm>
#define endl '\n'

using namespace std;

int N, M;
bool visit[8];

void solution(int i, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < N; i++) {
			if (visit[i])
				cout << i + 1 << " ";
		}
		cout << endl;
		return;
	}

	for (int j = i + 1; j < N; j++) {
		if (!visit[j]) {
			visit[j] = true;
			solution(j, cnt + 1);
			visit[j] = false;
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		visit[i] = true;
		solution(i, 1);
		visit[i] = false;
	}
	return 0;
}