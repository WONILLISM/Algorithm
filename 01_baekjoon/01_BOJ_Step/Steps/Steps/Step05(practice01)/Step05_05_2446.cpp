#include<iostream>

using namespace std;

int ABS(int x) { return x > 0 ? x : -x; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;

	for (int i = 1; i <= 2 * n - 1; i++) {
		int k = (i <= n) ? i : 2 * n - i;
		for (int j = 1; j <= k - 1; j++) cout << " ";
		for (int j = k; j <= 2 * n - k; j++) cout << "*";
		cout << "\n";
	}
	/*int star = 2 * n - 1;
	int blank = 0;
	for (int i = 0; i < 2 * n - 1; i++) {
		for (int j = 0; j < blank; j++)
			cout << " ";
		for (int j = 0; j < star; j++)
			cout << "*";
		cout << endl;


		if (i >= n-1) {
			blank--;
			star += 2;
		}
		else{
			blank++;
			star -= 2;
		}
	}*/
	return 0;
}