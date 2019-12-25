#include<iostream>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
	int answer = 0, Max = 0;
	queue<int> q;
	vector<int> visit(n + 1, 0);
	//牢立府胶飘 积己
	vector<vector<int>> g(n + 1, vector<int>());
	for (int i = 0; i < edge.size(); i++) {
		int u = edge[i][0], v = edge[i][1];
		g[u].push_back(v);
		g[v].push_back(u);
	}
	visit[1] = 1;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < g[cur].size(); i++) {
			int next = g[cur][i];
			if (!visit[next] && next != 0) {
				visit[next] = visit[cur] + 1;
				q.push(next);
				if (visit[next] > Max)Max = visit[next];
			}
		}
	}
	for (int i = 1; i <= n; i++)
		if (Max == visit[i])answer++;
	return answer;
}
int main() {
	vector<vector<int>> edge;
	edge.push_back({ 3,6 });
	edge.push_back({ 4,3 });
	edge.push_back({ 3,2 });
	edge.push_back({ 1,3 });
	edge.push_back({ 1,2 });
	edge.push_back({ 2,4 });
	edge.push_back({ 5,2 });
	cout << solution(6, edge) << "\n";
	return 0;
}


i/*nt Visit[20001], ans, Max;
int Mat[20001][20001];
queue<int> q;
void process(int n){
	int cur = 1;
	Visit[cur] = 1;
	q.push(cur);
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (Mat[cur][i] && !Visit[i]) {
				Visit[i] = Visit[cur] + 1;
				q.push(i);
				if (Max < Visit[i])Max = Visit[i];
			}
		}
	}
}
int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	for (int i = 0; i < edge.size(); i++)
		Mat[edge[i][0]][edge[i][1]] = Mat[edge[i][1]][edge[i][0]] = 1;
	process(n);
	for (int i = 1; i <= n; i++)
		if (Max == Visit[i])ans++;
	answer = ans;
	return answer;
}*/
