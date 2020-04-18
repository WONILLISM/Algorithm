#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool comp(char a, char b) { return a > b; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	sort(s.begin(), s.end(), comp);
	cout << s;
	return 0;
}