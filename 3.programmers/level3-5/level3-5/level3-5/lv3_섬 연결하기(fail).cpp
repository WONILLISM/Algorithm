#include<iostream>
#include <string>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;
const int MAX = 101;
int matrix[MAX][MAX];
int visit[MAX];
int ans;
typedef struct Pos {
	int cost;
	int s, e;

	bool operator < (const Pos &n)const {
		return cost > n.cost;
	}
};
int solution(int n, vector<vector<int>> costs) {
	priority_queue<Pos> pq;
	Pos cur = { costs[0][2],costs[0][0],costs[0][1] };
	for (int i = 0; i < costs.size(); i++) {
		int a = costs[i][0], b = costs[i][1], c = costs[i][2];
		matrix[a][b] = c;
		matrix[b][a] = c;
	}
	
	pq.push(cur);
	//visit[cur.s] = 1;
	while (!pq.empty()) {
		cur = pq.top();
		pq.pop();
		ans += 1;
		if (ans == n)return cur.cost;
		for (int i = 0; i < n; i++) {
			int ns = i;
			if (matrix[cur.s][ns] && !visit[ns]) {
				pq.push({ matrix[cur.s][ns],ns,cur.s });
				visit[ns] = matrix[cur.s][ns];
			}
		}
	}
}
int main() {
	int n;
	cin >> n;
	vector<vector<int>> c;
	c.push_back({ 0,1,1 });
	c.push_back({ 0,2,2 });
	c.push_back({ 1,2,5 });
	c.push_back({ 1,3,1 });
	c.push_back({ 2,3,8 });
	cout << solution(n, c) - 1;
	return 0;
}