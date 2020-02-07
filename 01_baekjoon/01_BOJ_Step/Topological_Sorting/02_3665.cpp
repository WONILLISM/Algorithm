#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long

using namespace std;
const int MAX = 501;

int N, M;
int g[MAX][MAX];
int entry[MAX];
int _rank[MAX];

void solution() {
	vector<int> ans;
	while (M--) {
		int a, b;
		cin >> a >> b;
		if (g[a][b]) {
			entry[a]++;
			entry[b]--;
		}
		else {
			entry[a]--;
			entry[b]++;
		}
		swap(g[a][b], g[b][a]);
	}
	queue<int> q;
	for (int i = 1; i <= N; ++i) {
		if (!entry[i])
			q.push(i);
	}
	int chk = 0;
	for (int i = 0; i < N; ++i) {
		if (q.empty()) {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
		else if (q.size() > 1) {
			cout << "?" << endl;
			return;
		}
		int cur = q.front(); q.pop();
		_rank[i] = cur;
		ans.push_back(cur);
		for (int next = 1; next <= N; ++next) {
			if (g[cur][next]) {
				entry[next]--;
				if (!entry[next])q.push(next);
			}
		}
	}
	for (int i = 0; i < N; ++i)
		cout << _rank[i] << " ";
	cout << endl;
}

int main() {
//	freopen("02_3665.in", "r", stdin);
	freopen("E.in", "r", stdin);
	int tc; 
	cin >> tc;
	while (tc--) {
		cin >> N;
		/*--- INIT ---*/
		/*memset(g, 0, sizeof(g));
		memset(_rank, 0, sizeof(_rank));
		memset(entry, 0, sizeof(entry));*/
		for (int i = 0; i < N; i++) { 
			_rank[i] = 0;
			entry[i] = 0;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				g[i][j] = 0;
			}
		}
		/*--- INIT ---*/
		for (int i = 0; i < N; i++)
			cin >> _rank[i];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < i; j++) {
				g[_rank[j]][_rank[i]] = 1;
				entry[_rank[i]]++;
			}
		}
		cin >> M;
		solution();
	}
	return 0;
}