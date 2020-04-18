#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define PII pair<int, int>
#define endl '\n'

using namespace std;

typedef struct pos {
	int x, y;
}Pos;
bool operator<(const Pos &a, const Pos &b) {
	if (a.x != b.x)return a.x > b.x;
	else return a.y > b.y;
}
priority_queue<Pos> pq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	while (n--) {
		Pos tmp;
		cin >> tmp.x >> tmp.y;
		pq.push(tmp);
	}
	while (!pq.empty()) {
		Pos cur = pq.top();
		pq.pop();
		cout << cur.x << " " << cur.y << endl;
	}
	/*vector<PII> v;
	int n; cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end());
	for (PII ans : v) {
		cout << ans.first << " " << ans.second << endl;
	}*/
	return 0;
}