#include<iostream>
using namespace std;

char Gear[4][8];
int k, ans;
void Input() {
	for (int i = 0; i < 4; i++) 
		cin >> Gear[i];
	cin >> k;
}
void Rotate(int n, int d) {
	int tmp[8];
	if (d == 1) {
		for (int i = 0; i < 8; i++) {
			tmp[(i + 1) % 8] = Gear[n][i];
		}
	}
	else {
		for (int i = 0; i < 8; i++) {
			tmp[i] = Gear[n][(i + 1) % 8];
		}
	}
	for (int i = 0; i < 8; i++) {
		Gear[n][i] = tmp[i];
	}
}

void Process() {
	while (k--) {
		int n, d;
		cin >> n >> d; n--;
		int dir[4] = { 0 };
		dir[n] = d;
		for (int i = n; i < 3; i++) {
			if (Gear[i][2] != Gear[i + 1][6]) dir[i + 1] = -dir[i];
		}
		for (int i = n; i > 0; i--) {
			if (Gear[i][6] != Gear[i - 1][2]) dir[i - 1] = -dir[i];
		}
		for (int i = 0; i < 4; i++) {
			if (dir[i]) {
				Rotate(i, dir[i]);
			}
		}
	}
}
void Solution() {
	Input();
	Process();
	for (int i = 0; i < 4; i++) {
		if (Gear[i][0]=='1') ans += (1 << i);
	}
	cout << ans << "\n";
}

int main() {
	freopen("13.in", "r", stdin);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Solution();
	return 0;
}