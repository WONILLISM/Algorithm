#include<iostream>
#include<vector>
using namespace std;

void solution(int n) {
	vector<int> st;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a) {
			st.push_back(a);
		}
		else st.pop_back();
	}
	a = 0;
	for (int i = 0; i<st.size(); i++)
		a += st[i];
	cout << a << "\n";
}
int main() {
	int n;
	cin >> n;
	solution(n);
	return 0;
}