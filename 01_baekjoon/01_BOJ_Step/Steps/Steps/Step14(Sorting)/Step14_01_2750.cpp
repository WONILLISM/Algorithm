#include<iostream>
#include<algorithm>
#include<vector>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < n; i++) {
		int m_idx = i;
		for (int j = i + 1; j < n; j++) 
			if (v[j] < v[m_idx]) m_idx = j;
		int tmp = v[m_idx];
		v[m_idx] = v[i];
		v[i] = tmp;
	}
	
	bool chk = false;
	for (int i = 0; i < v.size(); i++) {	
		if (!chk) {
			chk = true;
			cout << v[i] << endl;
		}
		else {
			if (v[i - 1] != v[i])chk = false;
			if (!chk) {
				chk = true;
				cout << v[i] << endl;
			}
		}
	}
	return 0;
}