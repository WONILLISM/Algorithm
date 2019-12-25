#include<iostream>
#include<vector>
using namespace std;
const int MAX = 20;
int Res;
int a[MAX][MAX];
int N, Min = 1 << 30;
bool Player[MAX];
vector<int> Sky;
vector<int> Link;
int answer[2];
void Input() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> a[i][j];
}
void Process() {
	int s = 0;
	int l = 0;
	for (int i = 0; i < N/2; i++) {
		for (int j = i + 1; j < N/2; j++) {
			s += a[Sky[i]][Sky[j]] + a[Sky[j]][Sky[i]];
			l += a[Link[i]][Link[j]] + a[Link[j]][Link[i]];
		}
	}
	//int res = s > l ? s - l : l - s;
	Res= s > l ? s - l : l - s;
	//if (Min > res)Min = res;
	if (Min > Res)Min = Res;
}
void Team(int j, int n) {
	if (n == N / 2) {
		Sky.clear();
		Link.clear();
		for (int i = 0; i < N; i++) {
			if (Player[i])Sky.push_back(i);
			else Link.push_back(i);
		}
		Process();
		return;
	}
	for (int i = j+1; i < N; i++) {
		Player[i] = true;
		Team(i, n + 1);
		Player[i] = false;
	}
}

void Solution() {
	Input();
	for (int i = 0; i < N; i++) {
		Player[i] = true;
		Team(i, 1);
		Player[i] = false;
	}
	cout << Min << "\n";
}
int main() {
	freopen("11.in", "r", stdin);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Solution();
	return 0;
}