#include<iostream>
#include <string>
#include <vector>
#include<queue>

using namespace std;
int inf = 1 << 30;
//int Map[101][101][2];
int visit[101];
typedef struct Pos {
	int x, cost;
	bool operator<(const Pos &n)const {
		return cost > n.cost;
	}
};

//int solution(int n, vector<vector<int>> costs) {
//	int answer = 0;
//	vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
//	for (int i = 0; i < costs.size(); i++) {
//		int u = costs[i][0], v = costs[i][1], c = costs[i][2];
//		graph[u].push_back({ v, c });
//		graph[v].push_back({ u, c });
//		/*Map[u][v][0] = Map[v][u][0] = 1;
//		Map[u][v][1] = Map[v][u][1] = c;*/
//	}
//
//	priority_queue<Pos> pq;
//	Pos cur = { costs[0][0], 0 };
//	pq.push(cur);
//	while (!pq.empty()) {
//
//	}
//
//	return answer;
//}
int main() {
	vector<vector<int>> c;
	c.push_back({ 0,1,1 });
	c.push_back({ 0,2,2 });
	c.push_back({ 1,2,5 });
	c.push_back({ 1,3,1 });
	c.push_back({ 2,3,8 });
	//cout << solution(4, c) << endl;
	cout << "hi\n";
	return 0;
}