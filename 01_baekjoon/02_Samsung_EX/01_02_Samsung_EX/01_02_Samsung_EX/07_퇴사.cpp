#include<iostream>

using namespace std;
const int MAX = 15;

int N, Max;
int P[MAX], T[MAX];

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}
}
//T[i] : 3  5  1  1  2  4  2
//P[i] : 10 20 10 20 15 40 200

void Process(int sum, int day) {
	if (day == N) {
		if (Max < sum)Max = sum;
		return;
	}
	else if (day > N)return;	
	Process(sum + P[day], day + T[day]);
	Process(sum, day + 1);
}
void Solution() {
	Input();
	//Process(0, 0);
	cout << Max << endl;
}
int main() {
	freopen("07.in", "r", stdin);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Solution();
	return 0;
}