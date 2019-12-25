#include<iostream>

using namespace std;

const int MAX = 1000000;

int N, B, C;
int A[MAX];
long long  answer;

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cin >> B >> C;
}

void Process() {
	for (int i = 0; i < N; i++) {
		if (A[i] >= B) {
			int d = A[i] - B;
			answer++;
			if (d >= 0 && d % C == 0) answer += d / C;
			else answer += d / C + 1;
		}
		else answer++;
	}
}
void Solution() {
	Input();
	Process();
	cout << answer << endl;
}
int main() {
	freopen("04.in", "r", stdin);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Solution();
	return 0;
}