#include<iostream>
#include<string>
#define endl '\n'
using namespace std;

const int MAX = 2000000;
int Q[MAX];
int f, r;
string cmd;

void solution() {
	if (cmd == "push") {
		int a; cin >> a;
		Q[r++] = a;
	}
	else if (cmd == "pop") {
		if (f == r) cout << "-1" << endl;
		else cout << Q[f++] << endl;
	}
	else if (cmd == "size") {
		cout << r - f << endl;
	}
	else if (cmd == "empty") {
		if (f == r) cout << "1" << endl;
		else cout << "0" << endl;
	}
	else if (cmd == "front") {
		if (f == r)cout << "-1" << endl;
		else cout << Q[f] << endl;
	}
	else if (cmd == "back") {
		if (f == r)cout << "-1" << endl;
		else cout << Q[r - 1] << endl;
	}	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.in", "r", stdin);
	int n;
	cin >> n;
	while (n--) {
		cin >> cmd;
		solution();
	}
	return 0;
}