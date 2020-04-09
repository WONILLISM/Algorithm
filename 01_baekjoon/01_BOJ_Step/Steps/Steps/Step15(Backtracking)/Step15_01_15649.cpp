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
using namespace std;

const int MAX = 9;
vector<int> v;	//stack
bool visit[MAX];
int n, m;
void process(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			v.push_back(i);
			process(cnt + 1);
			visit[i] = false;
			v.pop_back();
		}
	}
}
void solution() {
	process(0);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	solution();
	return 0;
}