#include <iostream>
using namespace std;

const int MAX = 100;
int N, L, ans;
int Map[MAX][MAX];

void Input() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
		}
	}
}
/*
D가 0이라면, 길의 높이가 같은 경우이다.
D가 1이라면, 올라가는 경사로가 필요한 경우이다.
D가 -1이라면, 내려가는 경사로가 필요한 경우이다.
길의 높이가 같다면 (D == 0), 카운트를 1 증가시킨다. 카운트는 경사로의 길이와 비교하기 위해 필요하다.
올라가는 경사로라면 (D == 1), 카운트가 경사로의 길이 L 이상인지 확인한다. 카운트가 L 이상이라면,
경사로를 놓을 수 있는 경우이므로, 카운트를 1로 초기화시킨다.
내려가는 경사로라면 (D == -1), 카운트가 0 이상인지 확인한다. 
0 이상이라면, 카운트를 경사로의 길이 L만큼을 음수로 만든다. 
만약 카운트가 음수라면, 내려가는 경사로를 만들고 있는 중이므로, 경사로를 놓을 수 없다.
*/
void slope(int i, bool c) {
	int cnt = 1;
	for (int j = 0; j < N - 1; j++) {
		//행이냐 열이냐
		int d = c == true ? Map[i][j + 1] - Map[i][j] : Map[j + 1][i] - Map[j][i];
		if (d == 0) cnt++;
		else if (d == 1 && cnt >= L) cnt = 1;
		else if (d == -1 && cnt >= 0) cnt = -L + 1;
		else return;
	}
	if (cnt >= 0) ans += 1;
}
void Process() {
	for (int i = 0; i < N; i++) {
		slope(i, true);
		slope(i, false);
	}
}
void Solution() {
	Input();
	Process();
	cout << ans << "\n";
}
int main() {
	freopen("12.in", "r", stdin);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Solution();
	return 0;
}