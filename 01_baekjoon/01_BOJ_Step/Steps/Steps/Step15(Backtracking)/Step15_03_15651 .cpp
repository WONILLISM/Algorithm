#include<iostream>
#include<algorithm>
#define endl '\n'

using namespace std;

int N, M;
//int Stack[7], top;
char d[15];
void solution(int cnt) {
	if (cnt == M) {
		d[cnt * 2 - 1] = '\n';
		cout << d;
		return;
	}
	for (int i = 1; i <= N; i++) {
		d[cnt * 2] = i + '0';
		d[cnt * 2 + 1] = ' ';
		solution(cnt + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	solution(0);

	return 0;
}
//void solution(int i, int cnt) {
//	if (cnt == M) {
//		for (int i = 0; i < top; i++)
//			cout << Stack[i] << " ";
//		cout << endl;
//		return;
//	}
//	for (int j = 0; j < N; j++) {
//		Stack[top++] = j + 1;
//		solution(j, cnt + 1);
//		top--;
//	}
//}
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> M;
//
//	for (int i = 0; i < N; i++) {
//		Stack[top++] = i + 1;
//		solution(i, 1);
//		top--;
//	}
//
//	return 0;
//}