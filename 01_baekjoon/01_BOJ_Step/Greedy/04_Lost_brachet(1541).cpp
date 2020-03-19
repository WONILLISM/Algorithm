#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<algorithm>
#define endl '\n';
#define ll long long
#define PII pair<int,int>
#define PIS pair<int,string>

using namespace std;

string s;
int answer = 0;
void solution() {
	string tmp;
	bool chk = false;
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] >= '0'&&s[i] <= '9')tmp += s[i];
		else {
			if (chk)answer -= stoi(tmp);
			else answer += stoi(tmp);

			tmp.clear();
			if (s[i] == '-') chk = true;
		}
	}
	cout << answer << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> s;
	solution();
	return 0;
}